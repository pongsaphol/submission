#!/bin/bash

TASK=xylophone

java -Xmx512M -Xss64M -cp ${TASK}.jar grader
