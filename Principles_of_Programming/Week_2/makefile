# Labsheet
run: build
	./build/LabSheet2

build: LabSheet2.o
	gcc -o build/LabSheet2 build/LabSheet2.o -lm

LabSheet2.o: LabSheet2.c
	mkdir -p build
	gcc -c LabSheet2.c -o build/LabSheet2.o -lm

# Return Problem
run_return_problem: build_return_problem
	./build/Week2ReturnProblem

build_return_problem: Week2ReturnProblem.o
	gcc -o build/Week2ReturnProblem build/Week2ReturnProblem.o

Week2ReturnProblem.o: Week2ReturnProblem.c
	mkdir -p build
	gcc -c Week2ReturnProblem.c -o build/Week2ReturnProblem.o

clean:
	rm -r build
	echo "Clean Complete"


