#!/bin/bash

problem=cycle

g++ -std=gnu++14 -O2 -pipe -o $problem grader.cpp $problem.cpp
