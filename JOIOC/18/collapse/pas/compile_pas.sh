#!/bin/bash

TASK=collapse

fpc -XS -O2 -o${TASK} grader.pas
