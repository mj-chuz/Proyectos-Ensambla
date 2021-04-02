all:
	nasm -g -f elf64 -o proyecto_pinguinos_ensambla.o proyecto_pinguinos_ensambla.asm
	g++ -c -g -o proyecto_pinguinos.o proyecto_pinguinos.cpp
	g++ -g -o casm proyecto_pinguinos_ensambla.o proyecto_pinguinos.o

debug:
	nasm -g -f elf64 -o hello.o stack.asm
	ld -o stack hello.o

clean:
	rm *.o