
NAME=gondola

g++ -DEVAL -static -O2 -std=c++11 -o $NAME grader.cpp $NAME.cpp
