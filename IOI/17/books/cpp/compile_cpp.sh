#!/bin/bash

problem=books

g++ -std=gnu++14 -O2 -pipe -o $problem grader.cpp $problem.cpp
