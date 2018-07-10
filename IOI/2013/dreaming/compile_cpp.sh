#!/bin/bash

NAME=dreaming

g++ -DEVAL -static -O2 -o $NAME grader.c $NAME.cpp
