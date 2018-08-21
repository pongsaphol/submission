#!/bin/bash

problem=tetris

fpc -XS -O2 -o$problem grader.pas
