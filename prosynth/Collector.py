#!/usr/bin/env python3
# Collect the evidence from the various subfolders
import sys
import os
from statistics import mean, stdev

problemDir = sys.argv[1]

retrieved = open(problemDir + "/" + "Retrieved.txt", "w+")
confidence = open(problemDir + "/" +"Confidence.txt", "w+")
examples = open(problemDir + "/" +"examples.txt", "w+")
correctness = open(problemDir + "/" +"Corectness.txt", "w+")
invited = open(problemDir + "/" + "InvitedPredicates.txt", "w+")

true = 0
false = 0

for file in os.listdir(problemDir):
    if file.endswith(".txt") and "evaluation" in file:
         with open(problemDir + "/" + file, "r") as currFile:
            for line in currFile:
                if "Retrieved:" in line:
                    number = float(line.split("\t")[1])
                    retrieved.write(str(number) + "\n")
                elif "Positive Examples" in line:
                    number = float(line.split(" ")[3])
                    examples.write(str(number)+ "\n")
                elif "inv" in line:
                    invited.write(line)
                elif "Confidence" in line:
                    number = float(line.split(" ")[1])
                    confidence.write(str(number)+ "\n")
                elif "True" in line:
                    number = float(line.split("\t")[1])
                    true = number
                elif "False" in line:
                    number = float(line.split("\t")[1])
                    false = number
                elif "Unknown" in line:
                    number = float(line.split("\t")[1])
                    if number == 0:
                        continue

                    correctness.write(str(true / (true + false + number)) + "\t" + 
                        str(false / (true + false + number)) + "\t" +
                        str(number / (true + false + number)) + "\n")
retrieved.close()
confidence.close()
examples.close()
correctness.close()
invited.close()


def getAverage(file):
    var = []
    with open(problemDir + "/" + file, "r") as currFile:
        for line in currFile:
            #print("!")
            var.append(float(line))
        #print(var)
    #return (mean(var), stdev(var))
    return mean(var)

def getAverageCorrectness(file):
    t = []
    f = []
    u = []
    with open(problemDir + "/" + file, "r") as currFile:
        for line in currFile:
            triple = line.split("\t")
            t.append(float(triple[0]))
            f.append(float(triple[1]))
            u.append(float(triple[2]))
    result = []
    std = []
    result.append(mean(t))
    result.append(mean(f))
    result.append(mean(u))
    #std.append(stdev(t))
    #std.append(stdev(f))
    #std.append(stdev(u))

    return (result, std)

with open(problemDir + "/Summary.txt" , "w") as currFile:
    currFile.write("Retrieved: " + str(getAverage("Retrieved.txt")) + "\n")
    currFile.write("Correctness: " + str(getAverageCorrectness("Corectness.txt")))



                

