#!/bin/bash

NAME=tournament

/usr/bin/g++ -O2 -o $NAME grader.cpp $NAME.cpp -std=c++11
