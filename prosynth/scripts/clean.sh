#!usr/bin/bash

mv yago/kb.tsv kb.tsv
rm -r yago
mkdir yago
mv kb.tsv yago/kb.tsv
