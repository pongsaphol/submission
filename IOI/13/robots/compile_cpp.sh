#!/bin/bash

NAME=robots

g++ -DEVAL -static -O2 -o $NAME grader.c $NAME.cpp
