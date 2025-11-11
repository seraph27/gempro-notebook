#!/bin/bash

mkdir -p out
pdflatex -shell-escape --output-directory=./out/ --jobname=gempro-notebook content/main.tex && evince out/gempro-notebook.pdf
