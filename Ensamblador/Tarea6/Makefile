all:
	nasm -g -f elf64 -o tarea6Ensambla.o tarea6Ensambla.asm
	g++ -c -g -no-pie -o tarea6Cpp.o tarea6Cpp.cpp
	g++ -g -o casm tarea6Ensambla.o tarea6Cpp.o

clean:
	rm *.o
