all:
	nasm -g -f elf64 -o tareaMusica.o tareaMusica.asm
	g++ -c -g -no-pie -o tareaMusicaCPP.o tareaMusicaCPP.cpp -I/usr/include/python3.7m -lpython3.7m
	g++ -I/usr/include/python3.7m -lpython3.7m -g -o casm tareaMusica.o tareaMusicaCPP.o 

clean:
	rm *.o



