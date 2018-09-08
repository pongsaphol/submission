#!/bin/bash

TASK=combo

javac ${TASK}.java grader.java
jar cf ${TASK}.jar *.class
