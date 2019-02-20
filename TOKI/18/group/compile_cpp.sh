#!/bin/bash

NAME=group

g++-8 -o $NAME grader.cpp $NAME.cpp -O2 -lm -std=c++11
