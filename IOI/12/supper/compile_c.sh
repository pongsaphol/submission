#!/bin/bash

NAME=supper

/usr/bin/gcc -DEVAL -Wall -static -O2 -o $NAME grader.c assistant.c advisor.c -lm
