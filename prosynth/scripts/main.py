#!/usr/bin/env python3
import subprocess
import sys
import os
from pathlib import Path
import random
import networkx as nx
import re



scriptPath = sys.argv[0]
problemDirName = "yago"
#problemDirName = sys.argv[1]
#outputRelation = sys.argv[2]
outputRelation = "livesIn"
fileName = "kb.tsv" 
width = 2
numberOfInventedPredicates = 1
relevancethreshhold = 0.01
negativeExampleAmount = 5
train_test_split = 0


kb = open(problemDirName + "/" + fileName, encoding = "utf-8")
kbSize = Path(problemDirName + "/" + fileName).stat().st_size

relations = []

# File assumed to be in tsv format and not include any '/' sign 
for line in kb:
    line = line.split('\t')
    with open(problemDirName + "/" + line[1] + ".facts", "a+") as file:
        file.write(line[0] + "\t" + line[2])  

print("Converted kb into souffle syntax")

#generate negative examples
subjects = []
objects = []
negativeExamples = []
output = set()
with open(problemDirName + "/" + outputRelation + ".facts", "r") as file:
    for line in file:
        pair = line.split("\t")
        subjects.append(pair[0])
        objects.append(pair[1])
    
    length = len(subjects) - 1

i = 0
while i < negativeExampleAmount:
    negEx =subjects[random.randint(0, length)] + "\t" +  objects[random.randint(0, length)]
    with open(problemDirName + "/" + outputRelation + ".facts", "r") as file:
        if negEx in file.read():
            pass
        else:
            negativeExamples.append(negEx)
            i = i + 1
    


with open(problemDirName + "/" + outputRelation + ".notexpected", "w") as file:
    for line in negativeExamples:
        file.write(line)
#split
entities = set()
with open(problemDirName + "/" + outputRelation + ".facts", "r") as file:
    with open(problemDirName + "/" + outputRelation + ".expected", "w") as train_file:
        with open(problemDirName + "/I" + outputRelation + ".facts", "w") as inputFile:
            with open(problemDirName + "/" + "test" + ".csv", "w") as test_file:
                for line in file:
                    inputFile.write(line)
                    if random.random() >= train_test_split:
                        train_file.write(line)
                    else:
                        test_file.write(line)
                        entities.add(line.split("\t")[0])



#determine relevant relations
pairs = []
for filename in os.listdir(problemDirName):
    if filename.endswith(".facts"):
        if Path(problemDirName + "/" + filename).stat().st_size > kbSize * relevancethreshhold:
            relations.append(filename.split(".")[0])
        #pairs.append((filename.split(".")[0], Path(problemDirName + "/" + filename).stat().st_size))
#pairs.sort(key= lambda s: s[0], reverse=True)

max_size = 5
current = 0
for pair in pairs:
    if current < max_size:
        relations.append(pair[0])
        current = current + 1
if "I" + outputRelation in relations:
    relations.remove("I"+ outputRelation) 
    relations.append("I"+ outputRelation)
if  outputRelation in relations:
    relations.remove(outputRelation)
    relations.append(outputRelation)

#preserve order and have the output at the back. Important for the rule generation
relations = list(dict.fromkeys(relations))
print(relations)

def isConnected(rule):
    graph = nx.Graph()
    head, body = rule.split(":")
    match = re.compile('\((\w+), (\w+)\)')

    result = re.findall(match, body)

    for e in result:
        if e[0] not in graph:
            graph.add_node(e[0])
        if e[1] not in graph:
            graph.add_node(e[1])
        graph.add_edge(e[0], e[1])

    headmatch = re.search(match, head)
    if nx.has_path(graph, headmatch.group(1), headmatch.group(2)) or nx.has_path(graph, headmatch.group(2), headmatch.group(1)):
        return True
    else:
        return False

#generateRules
with open(problemDirName + "/"+ "rules.t", "w+") as ruleFile:
    for relation in relations:
        if relation == outputRelation:
            #ruleFile.write(relation + "(V,V)\n" )
            pass
        else:
            ruleFile.write("*" + relation + "(V,V)\n")

    for i in range(0, numberOfInventedPredicates):
        ruleFile.write("inv_" + str(i) + "(V,V)\n")
    ruleFile.write(outputRelation + "(V,V)\n" )

subprocess.run(["./scripts/rule-gen/generate-fast", problemDirName, str(width)], stdin=subprocess.PIPE, stdout=subprocess.PIPE,  universal_newlines=True)


# Remove rules of the form A(x,y) :- A(x,y), B(x,y) as they don't offer any additional information
with open(problemDirName + "/rules.dl", "r+") as ruleFile:
    with open(problemDirName + "/tmp.dl", "w") as tmp:
        for line in ruleFile:
            if ":-" in line:
                # Remove all lines where head (before :) appears also in the body. [:-1] is necessary as there is a 
                # blankspace after the head, but a , in the body.
                if line.count(line.split(":")[0].split()[0][:-1]) >= 2:
                    continue
                # prevent v(x, y) :- v(y,x) and v(x,y) :- Iv(y,x) from occuring
                if "I" + outputRelation + "(v1, v0)" in line:
                    continue
                if not isConnected(line):
                    continue
            tmp.write(line)

with open(problemDirName + "/tmp.dl", "r") as tmp:
    with open(problemDirName + "/rules.dl", "w") as ruleFile:
        for line in tmp:
            ruleFile.write(line)

print("generatedRules")


subprocess.run(["./scripts/prepare", problemDirName, "souffle.small.out", "rules.dl"], stdin=subprocess.PIPE, stdout=subprocess.PIPE,  universal_newlines=True)

#generate ruleHelperRelation
with open(problemDirName + "/Rule.facts", "w") as file:
    num_lines = sum(1 for line in open(problemDirName + '/rules.dl'))
    for i in range(1, num_lines):
        file.write(str(i)+ "\n")

print("Evaluating Rules")

#taken from prosynth
def runSouffle(command):
    with subprocess.Popen([ problemDirName + command, '-F', problemDirName, '-D', problemDirName, '-j', '8' ], \
                            stdin=subprocess.PIPE, \
                            stdout=subprocess.PIPE, \
                            universal_newlines=True) as souffleProc:

            while souffleProc.stdout.readline().strip() != '###': pass
            while souffleProc.stdout.readline().strip() != '###': pass
            def execSouffleCmd(cmd):
                #logging.info('prosynth to souffle: ' + cmd)
                print(cmd, file=souffleProc.stdin)
                souffleProc.stdin.flush()

                response = [ souffleProc.stdout.readline().strip() ]
                if response[-1] == '':
                    return "error reading" #doesn't deal with underlying problem, just passes error through and skips question
                    #return execSouffleCmd(cmd)
                while response[-1] != '###': 
                    response.append(souffleProc.stdout.readline().strip())
                response = response[:-1]
                ans = '\n'.join(response)
                #logging.info('souffle to prosynth: ' + ans)
                return ans
            execSouffleCmd('format json')
            execSouffleCmd('setdepth 200000')
runSouffle('/souffle.small.out')

#assumed to fit in memory for a cleaner code. Works for the tested examples from DBpedia and YAGO
expected = set(open(problemDirName + "/" + outputRelation + ".expected"))
producable = set(open(problemDirName + "/" + outputRelation + ".csv"))

goal = expected.intersection(producable)

if len(goal) == 0:
    print("No mining possible")
    with open(problemDirName + "/evaluation_" +  outputRelation + ".txt", "w") as evFile:
        evFile.write("No Mining possible")
    quit()

with open(problemDirName + "/" + outputRelation + ".expected", "w") as file:
    for line in goal:
        file.write(line)

print("Preparation finished!")

subprocess.run(["./scripts/prosynth", problemDirName, "0", "1", "data.log"], stdin=subprocess.PIPE, stdout=subprocess.PIPE,  universal_newlines=True)

#prosynth.runProsynth(problemDirName, 0, 1, "data.log")

print("finished Mining")

#evaluate
with open(problemDirName + "/evaluation_" +  outputRelation + ".txt", "w") as evFile:
    #evaluate whole program
    subprocess.run(["./scripts/prepare", problemDirName, "program.small.out", "solution.dl"],\
         stdin=subprocess.PIPE, stdout=subprocess.PIPE,  universal_newlines=True)

    runSouffle("/program.small.out")

    with open(problemDirName + "/solution.dl") as solFile:
        for line in solFile:
            evFile.write(line)
    produced = set(open(problemDirName + "/" + outputRelation + ".csv"))
    expected = set(open(problemDirName + "/test.csv"))

    if len(expected) == 0:
        quit()

    truePredictions = len(expected.intersection(produced))

    expectedEntities = {element.split("\t")[0] for element in produced}

    falsePredictions = len(entities.intersection(expectedEntities)) - truePredictions

    evFile.write("True predictions:\t" + str(truePredictions) + "\n")
    evFile.write("False predictions:\t" + str(falsePredictions) + "\n")
    evFile.write("Unknown predictions:\t" + str(len(produced)- truePredictions - falsePredictions) + "\n")

    evFile.write("Retrieved:\t" + str(truePredictions/len(expected)) + "\n" )


