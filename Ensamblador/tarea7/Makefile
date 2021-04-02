all:
	nasm -g -f elf64 -o tarea7.o tarea7.asm
	g++ -c -g -no-pie -o tarea7Cpp.o tarea7Cpp.cpp
	g++ -g -no-pie -o casm tarea7.o tarea7Cpp.o

clean:
	rm *.o
