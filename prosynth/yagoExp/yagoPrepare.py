#!/usr/bin/python
import sys

file = sys.argv[1]

with open(file, "r") as input:
    with open("output", "w") as output:
        for line in input:
            line = line.split("\t")
            output.write(line[1] + "\t" + line[2]) 