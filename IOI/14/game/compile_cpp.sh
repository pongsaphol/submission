#!/bin/bash

NAME=game

/usr/bin/g++  -O2 -std=c++11 -o $NAME grader.cpp $NAME.cpp
