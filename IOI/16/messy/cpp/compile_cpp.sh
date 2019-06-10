#!/bin/bash

problem=messy

g++-8 -O2 -std=c++11 -static -o $problem grader.cpp $problem.cpp
