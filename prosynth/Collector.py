#!/usr/bin/env python3
# Collect the evidence from the various subfolders
import sys
import os

problemDir = sys.argv[1]

retrieved = open(problemDir + "/" + "Retrieved.txt", "w+")
confidence = open(problemDir + "/" +"Confidence.txt", "w+")
examples = open(problemDir + "/" +"examples.txt", "w+")
correctness = open(problemDir + "/" +"Corectness.txt", "w+")
invited = open(problemDir + "/" + "InvitedPredicates.txt", "w+")

true = 0
false = 0

for file in os.listdir(problemDir):
    if file.endswith(".txt"):
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
                    number = float(line.split(" ")[2])
                    confidence.write(str(number)+ "\n")
                elif "True" in line:
                    number = float(line.split("\t")[1])
                    true = number
                elif "False" in line:
                    number = float(line.split("\t")[1])
                    false = number
                elif "Unknown" in line:
                    number = float(line.split("\t")[1])
                    correctness.write(str(true / (true + false + number)) + "\t" + 
                        str(false / (true + false + number)) + "\t" +
                        str(number / (true + false + number)) + "\n")

                

