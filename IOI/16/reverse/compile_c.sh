#!/bin/bash

problem=reverse

gcc -O2 -std=c11 -static -o $problem grader.c $problem.c