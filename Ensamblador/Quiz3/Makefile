all:
	nasm -g -f elf64 -o quiz3Ensambla.o quiz3Ensambla.asm
	g++ -c -g -no-pie -o quiz3Cpp.o quiz3Cpp.cpp
	g++ -g -o casm quiz3Ensambla.o quiz3Cpp.o

clean:
	rm *.o
