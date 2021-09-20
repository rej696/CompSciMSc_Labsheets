# Labsheet
run: build
	./build/LabSheet3

build: LabSheet3.o
	gcc -o build/LabSheet3 build/LabSheet3.o -lm

LabSheet3.o: LabSheet3.c
	mkdir -p build
	gcc -c LabSheet3.c -o build/LabSheet3.o -lm

clean:
	rm -r build
	echo "Clean Complete"


