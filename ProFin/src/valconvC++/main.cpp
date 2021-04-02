#include <iostream>
#include <vector>
#include <cmath>
 
#include "Sudoku.h"

 
int main(int argc, char* argv[])
{
	int size=0;
	std::cin>>size;
	size=size*size;
	std::vector<std::vector<int>> vect(size, std::vector<int>(size));
	Sudoku sudoku(size, vect);
	//char* argv1[]=argv;
	sudoku.analyzeArguments(argc, argv);

	return 0;
}
