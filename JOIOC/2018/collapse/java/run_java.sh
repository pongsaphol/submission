#!/bin/bash

TASK=collapse

java -Xmx512M -Xss64M -cp ${TASK}.jar grader
