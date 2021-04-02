all:
	nasm -g -f elf64 -o calcularTemp.o calcularTemp.asm
	g++ -c -g -no-pie -o tempCpp.o tempCpp.cpp
	g++ -g -no-pie -o casm calcularTemp.o tempCpp.o

clean:
	rm *.o
