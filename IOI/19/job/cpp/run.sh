g++ -std=c++11 gen.cpp -o gen
g++ -std=c++11 job.cpp grader.cpp -o job
g++ -std=c++11 jobs.cpp grader.cpp -o jobs

while [ ! -s df ];
do
	./gen > in
	./job < in > o1
	./jobs < in > o2
	echo hello
	diff o1 o2 > df
done

