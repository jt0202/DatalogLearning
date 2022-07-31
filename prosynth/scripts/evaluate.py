#!/usr/bin/env python3
import sys
import os
import subprocess
import re

scriptPath = sys.argv[0]
problemDirName = sys.argv[1]


#delete all previous facts
for file in os.listdir(problemDirName):
    if file.endswith(".facts"):
        with open(problemDirName + "/" + file, "w") as factfile:
            pass

entities = set()
kb = open(problemDirName + "/test.tsv", encoding = "utf-8")
# File assumed to be in tsv format and not include any '/' sign 
for line in kb:
    line = line.split('\t')
    with open(problemDirName + "/" + line[1] + ".facts", "a+") as file:
        file.write(line[0] + "\t" + line[2])
        entities.add(line[0])

solutionPattern = re.compile('sol_\w+.dl')

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

for file in os.listdir(problemDirName):
    if re.search(solutionPattern, file) == None:
        continue
    outputRelation = file.split("_")[1].split(".")[0]
    with open(problemDirName + "/evaluation_" +  outputRelation + ".txt", "a+") as evFile:
        #evaluate whole program
        subprocess.run(["./scripts/prepare", problemDirName, "program.small.out", file],\
            stdin=subprocess.PIPE, stdout=subprocess.PIPE,  universal_newlines=True)

        runSouffle("/program.small.out")

        rules = []
        prefix = []
        prefixdef = True

        with open(problemDirName + "/"+ file) as solFile:
            for line in solFile:
                if ":-" in line:
                    prefixdef = False
                evFile.write(line + "\n")
                if prefixdef:
                    prefix.append(line + "\n")
                else:
                    rules.append(line + "\n")
        produced = set(open(problemDirName + "/" + outputRelation + ".csv"))
        expected = set(open(problemDirName + "/" + outputRelation + ".facts"))
        

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
            evFile.write(rule + " Positive Examples: " + str(support) + "\n")
            
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

