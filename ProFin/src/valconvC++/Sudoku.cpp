#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string.h>
#include "Sudoku.h"

void Sudoku::readMatrixFromBinaryFile(const char* input_filename)
{
	std::ifstream file;
	file.open(input_filename, std::ios::in | std::ios::binary);
	if(!file){
		std::cerr << "Unable to open file" << input_filename << ".txt";
    	exit(1); 
	}else{
		
		for (int i=0; i<this->limit; i++)
		{
			for (int j=0; j<this->limit; j++)
			{
				file.read((char*) (&this->vect[i][j]), sizeof(this->vect[i][j]));
			}
		}
	}


	std::ofstream textFile;
	textFile.open(input_filename, std::ios::in);

	if(!file){
		std::cerr << "Unable to open file" << input_filename << ".txt";
    	exit(1); 
	}else{
		for (int i=0; i<this->limit; i++)
		{
			for (int j=0; j<this->limit; j++)
			{
				textFile << this->vect[i][j] << " ";
			}
			textFile << std::endl;
		}

		Sudoku:: readMatrixFromTextFile(input_filename);
		file.close();
		textFile.close();
	}


}

void Sudoku:: readMatrixFromTextFile(const char* input_filename)
{
	std::ifstream file;
	file.open(input_filename, std::ios::in);
	if (!file)
	{
    	std::cerr << "Unable to open file" << input_filename << ".txt";
    	exit(1); 
	}else
	{
		std::string auxiliar;
		int secAuxiliar = 0;
		for (int i = 0; i < this->limit; i++) {    
			for (int j = 0; j < this->limit; j++){   
		    	file >> auxiliar ;   
		    	if (auxiliar==".")
		    	{
		       		this->vect[i][j]=0;
		    	}else
				{
					secAuxiliar = stoi(auxiliar);
					this->vect[i][j] = secAuxiliar;
				}
			}
		}  
	}
	file.close();
}


void Sudoku::readMatrix()
{
	std::string auxiliar;
	int secAuxiliar = 0;
	for (int i = 0; i < this->limit; i++) {    
		for (int j = 0; j < this->limit; j++){   
		    std::cin >> auxiliar ;   
		    if (auxiliar==".")
		    {
		        this->vect[i][j]=0;
		    }else
			{
				secAuxiliar = stoi(auxiliar);
				this->vect[i][j] = secAuxiliar;
			}
		}
	}  
}

bool Sudoku::findBlank(int& row, int& col)
{
	for(row = 0; row < this->limit; row++){
	    for(col = 0; col < this->limit; col++){
	        if(this->vect[row][col] == 0){
	            return true;
	        }
	    }
	}
	return false;

}

bool Sudoku::checkRow(int row, int num){
	//std::string number= std::to_string(num);
	for(int col = 0; col < this->limit; col++){
		if(this->vect[row][col] == num){
		    return true;
		}
	}
	return false;
}

bool Sudoku::checkCol(int col, int num){
	//std::string number= std::to_string(num);
	for(int row = 0; row < this->limit; row++){
		if(this->vect[row][col] == num){
		    return true;
		}
	}
	return false;
}

bool Sudoku::checkMiniMatrix(int miniRow, int miniCol, int num){
	//aqw2std::string number= std::to_string(num);
	for(int row = 0; row < sqrt(this->limit); row++){
		for(int col = 0; col < sqrt(this->limit); col++){
		    if(this->vect[row + miniRow][col + miniCol] == num){
		        return true;
		    }
		}
	}
	return false;
}

bool Sudoku::solutionWorks(int row, int col, int num){
	int dim = sqrt(this->limit);
	bool re = !Sudoku::checkRow (row, num) && !Sudoku::checkCol (col, num) && !Sudoku::checkMiniMatrix(row - (row % dim), col - (col % dim), num) && (vect[row][col] == 0);
	return re;
}

bool Sudoku::solveSudoku(){
	int row = 0;
    int col = 0;
    if(!findBlank(row, col)){
        return true;
    }
    for(int num = 1; num <= this->limit; num++){
        if(solutionWorks(row, col, num)){
            //std::string number = std::to_string(num);
            this->vect[row][col] = num;
            if(solveSudoku()){
                return true;
            }
            this->vect[row][col] = 0;
        }
    }
    return false;
 
}


void Sudoku::printMatrixToBinaryFile(const char* output_filename)
{
	std::ofstream file;
	file.open(output_filename, std::ios::out | std::ios::binary);
	if(!file){
		std::cerr << "Unable to open file" << output_filename << ".txt";
    	exit(1); 
	}else{

		for (int i=0; i<this->limit; i++)
		{
			for (int j=0; j<this->limit; j++)
			{
				file.write((char*)(&this->vect[i][j]), sizeof(this->vect[i][j]));
			}
		}
		file.close();
	}
}



void Sudoku::printSudoku(){
	for(int i = 0; i < this->limit; i++){
		for(int j = 0; j < this->limit; j++){
		    std::cout << this->vect[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


void Sudoku::printMatrixToTextFile(const char* output_filename)
{
	std::ofstream file;
	file.open(output_filename, std::ios::out);
	if (!file)
	{
		std::cerr <<  "Unable to open file" << output_filename << ".txt";
	}else{

		for (int i=0; i<this->limit; i++)
		{
			for(int j=0; j<this->limit; j++)
			{
				file << this->vect[i][j];
			}
		}
		file << std::endl;
	}
	file.close();
}



void Sudoku::analyzeArguments(int argc, char* argv[])
{

	for ( int arg_index = 1; arg_index <= argc; ++arg_index )
	{
		if ( strcmp( argv[arg_index], "-ib") == 0 ){
			//for ( int arg_index = 1; arg_index < argc; ++arg_index ){
				Sudoku::readMatrixFromBinaryFile(argv[arg_index+1]);
				arg_index=argc;
			//}
		}else{
			if ( strcmp( argv[arg_index], "-it") == 0 ){
				//for ( int arg_index = 1; arg_index < argc; ++arg_index ){
					Sudoku::readMatrixFromTextFile(argv[arg_index+1]);
					arg_index=argc;
				//}
			}
			else
			{
				if ( strcmp( argv[arg_index], "-c") == 0 ){
					Sudoku::readMatrix();
					arg_index=argc;
				}
			}
		}
	}

	for ( int arg_index = 1; arg_index <= argc; ++arg_index )
	{
		if(Sudoku::solveSudoku())
		{
			if ( strcmp( argv[arg_index], "-ob") == 0 ){
				//for ( int arg_index = 1; arg_index < argc; ++arg_index ){
					Sudoku::printMatrixToBinaryFile(argv[arg_index+1]);
					arg_index=argc;
				//}
			}else{
				if ( strcmp( argv[arg_index], "-ot") == 0 ){
					//for ( int arg_index = 1; arg_index < argc; ++arg_index ){
						Sudoku::printMatrixToTextFile(argv[arg_index+1]);
						arg_index=argc;
					//}
				}else{
					if ( strcmp( argv[arg_index], "-c") == 0 ){
						Sudoku::printSudoku();
						arg_index=argc;
					}
				}
			}
		}else{
			std::cout << "invalid";
		}

	}

}