#!/bin/bash

problem=reverse

fpc -XS -O2 -o$problem grader.pas
