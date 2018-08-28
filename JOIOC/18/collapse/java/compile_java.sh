#!/bin/bash

TASK=collapse

javac ${TASK}.java grader.java
jar cf ${TASK}.jar *.class
