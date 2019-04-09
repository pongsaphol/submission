#!/bin/bash

NAME=city

g++-8 -DEVAL -Wall -static -O2 -o $NAME grader.cpp $NAME.cpp
