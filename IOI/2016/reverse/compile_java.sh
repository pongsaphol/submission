#!/bin/bash

problem=reverse

rm -f grader.jar
javac grader.java $problem.java
jar cfe $problem.jar grader *.class
