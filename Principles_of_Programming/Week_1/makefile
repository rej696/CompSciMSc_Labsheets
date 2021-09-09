run: build
	./build/LabSheet1

build: LabSheet1.o
	gcc -o build/LabSheet1 build/LabSheet1.o

LabSheet1.o: LabSheet1.c
	mkdir -p build
	gcc -c LabSheet1.c -o build/LabSheet1.o

clean:
	rm -r build
	echo "Clean Complete"


