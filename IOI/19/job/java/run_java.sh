#!/bin/bash

problem=job
memory=435

java -XX:+UseSerialGC -Xbatch -XX:-TieredCompilation -XX:CICompilerCount=1 -Xmx${memory}M -Xss64M -cp $problem.jar grader
