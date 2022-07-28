#!/usr/bin/env python3
from copy import deepcopy
import subprocess
import sys
import os
from pathlib import Path
import random
import networkx as nx
import re
import time



scriptPath = sys.argv[0]
problemDirName = sys.argv[1]
outputRelation = sys.argv[2]
if len(sys.argv) > 3:
    types = sys.argv[3]
else:
    types = None
fileName = "kb.tsv" 
width = 2
numberOfInventedPredicates = 1
relevancethreshhold = 0.01
negativeExampleAmount = 5
train_test_split = 0.25
multipleRelations = True

kb = open(problemDirName + "/" + fileName, encoding = "utf-8")
kbSize = Path(problemDirName + "/" + fileName).stat().st_size

relations = []


# File assumed to be in tsv format and not include any '/' sign 
for line in kb:
    line = line.split('\t')
    with open(problemDirName + "/" + line[1] + ".facts", "a+") as file:
        file.write(line[0] + "\t" + line[2]) 

#determine relevant relations
pairs = []
for filename in os.listdir(problemDirName):
    if filename.endswith(".facts"):
        if Path(problemDirName + "/" + filename).stat().st_size > kbSize * relevancethreshhold:
            relations.append(filename.split(".")[0])
        #pairs.append((filename.split(".")[0], Path(problemDirName + "/" + filename).stat().st_size))
#pairs.sort(key= lambda s: s[0], reverse=True)

if multipleRelations:
    outputRelations = deepcopy(relations)
else:
    outputRelations = []
    outputRelations.append(outputRelation)
print("Converted kb into souffle syntax")

for rel in outputRelations:
    starttime = time.time()
    outputRelation = rel
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

    relationtypes = {}

    if types != None:
        print("Type analysis")
        with open(problemDirName + "/" + types) as typeFile:
            for line in typeFile:
                if len(line.split()) >= 3:
                    elements = line.split()
                    if elements[1] == "rdfs:domain":
                        if elements[0] not in relationtypes.keys():
                            relationtypes[elements[0]] = [elements[2], ""]
                        else:
                            relationtypes[elements[0]][0] = elements[2]
                    elif elements[1] == "rdfs:range":
                        if elements[0] not in relationtypes.keys():
                            relationtypes[elements[0]] = ["", elements[2]]
                        else:
                            relationtypes[elements[0]][1] = elements[2]
        if outputRelation in relationtypes.keys():
            relationtypes["I" + outputRelation] = relationtypes[outputRelation]

    #delete previous rules
    with open(problemDirName + "/rules.dl", "w") as file:
        pass

    subprocess.run(["./scripts/rule-gen/generate-fast", problemDirName, str(width)], stdin=subprocess.PIPE, stdout=subprocess.PIPE,  universal_newlines=True)
    relationPattern = re.compile('([a-zA-Z0-9_]+)\((v\d+), (v\d+)\)')

    print(relationtypes)
  
    # Remove rules of the form A(x,y) :- A(x,y), B(x,y) as they don't offer any additional information
    with open(problemDirName + "/rules.dl", "r+") as ruleFile:
        with open(problemDirName + "/tmp.dl", "w") as tmp:
            with open(problemDirName + "/tmp2.dl", "w") as tmp2:
                for line in ruleFile:
                    if ":-" in line:
                        type_error = False
                        # Remove all lines where head (before :) appears also in the body. [:-1] is necessary as there is a 
                        # blankspace after the head, but a comma in the body.
                        if line.count(line.split(":")[0][:-1]) >= 2:
                            tmp2.write("Head twice \n")
                            tmp2.write(line)
                            continue
                        # prevent v(x, y) :- v(y,x) and v(x,y) :- Iv(y,x) from occuring
                        if "I" + outputRelation + "(v1, v0)" in line:
                            tmp2.write("input prevent\n")
                            tmp2.write(line)
                            continue
                        # same as previously but with invented predicates
                        if re.match("inv_\d+\(v0, v1\)", line) != None:
                            if "I" + outputRelation + "(v1, v0)" in line:
                                tmp2.write("invent_error\n")
                                tmp2.write(line)
                                continue
                            if "I" + outputRelation + "(v0, v1)" in line:
                                tmp2.write("invent_error\n")
                                tmp2.write(line)
                                continue
                        if "inv" in line and "I" + outputRelation in line:
                            continue
                        if not isConnected(line):
                            tmp2.write("Not connected\n")
                            tmp2.write(line)
                            continue
                        #remove obviously false rules as the types don't match
                        result = re.findall(relationPattern, line)
                        designatedtypes = {}
                        for match in result:
                            if match[0] not in relationtypes.keys():
                                continue
                            if match[1] in designatedtypes.keys():
                                if relationtypes[match[0]][0] != "":
                                    designatedtypes[match[1]].add(relationtypes[match[0]][0])
                            else:
                                if relationtypes[match[0]][0] != "":
                                    designatedtypes[match[1]] = {relationtypes[match[0]][0]}
                            if match[2] in designatedtypes.keys():
                                if relationtypes[match[0]][1] != "":
                                    designatedtypes[match[2]].add(relationtypes[match[0]][1])
                            else:
                                if relationtypes[match[0]][1] != "":
                                    designatedtypes[match[2]] = {relationtypes[match[0]][1]}
                        for relation in designatedtypes.keys():
                            if len(designatedtypes[relation]) >= 2:
                                type_error = True
                                break
                        if type_error:
                            tmp2.write("type error\n")
                            tmp2.write(line)
                            continue 
                    tmp.write(line)

    with open(problemDirName + "/tmp.dl", "r") as tmp:
        with open(problemDirName + "/rules.dl", "w") as ruleFile:
            for line in tmp:
                ruleFile.write(line)

    print("generatedRules")

    if os.path.exists(problemDirName + "\souffle.small.out"):
        os.remove(problemDirName + "\souffle.small.out")

    subprocess.run(["./scripts/prepare", problemDirName, "souffle.small.out", "rules.dl"], stdin=subprocess.PIPE, stdout=subprocess.PIPE,  universal_newlines=True)
    
    #taken from prosynth
    def runSouffle(command):
        with subprocess.Popen([ problemDirName + command, '-F', problemDirName, '-D', problemDirName, '-j', '5000' ], \
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

    
    #generate ruleHelperRelation
    with open(problemDirName + "/Rule.facts", "w") as file:
        num_lines = sum(1 for line in open(problemDirName + '/rules.dl'))
        for i in range(1, num_lines):
            file.write(str(i)+ "\n")
    
   
    print("Preparation finished!")

    subprocess.run(["./scripts/prosynth", problemDirName, "0", "1", "data.log"], stdin=subprocess.PIPE, stdout=subprocess.PIPE,  universal_newlines=True)

    print("finished Mining")

    endtime = time.time() - starttime

    #evaluate
    with open(problemDirName + "/evaluation_" +  outputRelation + ".txt", "w") as evFile:
        #evaluate whole program
        subprocess.run(["./scripts/prepare", problemDirName, "program.small.out", "solution.dl"],\
            stdin=subprocess.PIPE, stdout=subprocess.PIPE,  universal_newlines=True)

        runSouffle("/program.small.out")

        rules = []
        prefix = []
        prefixdef = True

        with open(problemDirName + "/solution.dl") as solFile:
            for line in solFile:
                if ":-" in line:
                    prefixdef = False
                evFile.write(line + "\n")
                if prefixdef:
                    prefix.append(line + "\n")
                else:
                    rules.append(line + "\n")
        produced = set(open(problemDirName + "/" + outputRelation + ".csv"))
        expected = set(open(problemDirName + "/test.csv"))
        

        if len(expected) == 0:
            continue

        truePredictions = len(expected.intersection(produced))

        expectedEntities = {element.split("\t")[0] for element in produced}
        trueEntities = {element.split("\t")[0] for element in  expected.intersection(produced)}
        
        falsePredictions = len(entities.intersection(expectedEntities)) - len(trueEntities)

        evFile.write("True predictions:\t" + str(truePredictions) + "\n")
        evFile.write("False predictions:\t" + str(falsePredictions) + "\n")
        evFile.write("Unknown predictions:\t" + str(len(produced)- truePredictions - falsePredictions) + "\n")

        evFile.write("Retrieved:\t" + str(truePredictions/len(expected)) + "\n" )
        
        with open(problemDirName + "/" + outputRelation + ".csv", "w") as file:
            pass

        #evaluate single rules
        for rule in rules:
            if "inv" in rule:
                continue

            #support
            with open(problemDirName + "/rule.dl", "w") as ruleFile:
                for line in prefix:
                    ruleFile.write(line)
                ruleFile.write(rule + "\n")
            subprocess.run(["./scripts/prepare", problemDirName, "rule.small.out", "rule.dl"],\
            stdin=subprocess.PIPE, stdout=subprocess.PIPE,  universal_newlines=True)

            runSouffle("/rule.small.out")

            support = 0
            with open(problemDirName + "/" + outputRelation + ".csv", "r") as file:
                for line in file:
                    support = support + 1
            evFile.write(rule + " Support: " + str(support) + "\n")
            
            if support == 0:
                continue

            #confidence
            with open(problemDirName + "/rule.dl", "w") as ruleFile:
                for line in prefix:
                    ruleFile.write(line)
                ruleFile.write(".decl out(v0: V, v1: V)\n" + ".output out\n\n")
                ruleFile.write("out(v0, v1):" + rule.split(":")[1].split(".")[0] + ", " + outputRelation + "(v0, v1).\n")
            subprocess.run(["./scripts/prepare", problemDirName, "rule.small.out", "rule.dl"],\
            stdin=subprocess.PIPE, stdout=subprocess.PIPE,  universal_newlines=True)

            confidence = 0
            with open(problemDirName + "/" + outputRelation + ".csv", "r") as file:
                for line in file:
                    confidence = confidence + 1
            confidence = confidence / support
            evFile.write(" Confidence: " + str(confidence) + "\n")

        relations.remove("I" + outputRelation)

        evFile.write("Time spent (in min): " +str(endtime / 60))
        evFile.write("Time spent (in s): " +str(endtime ))

