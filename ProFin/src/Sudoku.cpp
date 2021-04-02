#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string.h>
#include "Sudoku.h"
//#include "Convert.h"

/*void Sudoku::readMatrixFromBinaryFile()
{

}*/

/*void Sudoku:: readMatrixFromTextFile(const char* input_filename)
{
	std::ifstream file;
	file.open(input_filename, std::fstream::out);
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
}
*/

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
/*

void Sudoku::printMatrixToBinaryFile()
{

}
*/
void Sudoku::printSudoku(){
	for(int i = 0; i < this->limit; i++){
		for(int j = 0; j < this->limit; j++){
		    std::cout << this->vect[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
/*
void Sudoku::printMatrixToTextFile(const char* output_filename)
{
	std::ofstream file;
	file.open(output_filename. std::fstream::out);
	if (!file)
	{
		std::cerr <<  "Unable to open file" << output_filename << ".txt";
	}else{
		//std::string auxiliar;
		//int secAuxiliar=0;
		for (int i=0; i<this->limit; i++)
		{
			for(int j=0; j<this->limit; j++)
			{
				output_filename << this->vect[i][j];
			}
		}
		output_filename<< std::endl;
	}
	output_filename.close();
}
*/

/*
void Sudoku::analyzeArguments(int argc, char* argv[])
{

	for ( int arg_index = 1; arg_index < argc; ++arg_index )
	{
		int input=0;
		int output=0;
		///Conver convertor;
		if ( strcmp( argv[arg_index], "-ib") == 0 ){
			input=1;
			//readMatrixFromBinaryFile();
			///convertor.convertFile(input, 2);
			///input=2;
		}else{
			if ( strcmp( argv[arg_index], "-it") == 0 ){
				input=2;
				//puse este parametro porque en el main.cpp del valcon original el profe manda de parametro eso
				//cuando necesita enviar el input_filename a la funcion
				readMatrixFromTextFile(argv[arg_index]);
			}
			else
			{
				if ( strcmp( argv[arg_index], "-c") == 0 ){
					//readMatrix();
					Sudoku::readMatrix();
					//readMatrixFromTextFile(argv[arg_index]);
				}
			}
		}
		if(Sudoku::solveSudoku())
		{


		//Depemdiendo de lo que se reciba, tener una varaible y dependiendo de
		//la salida hacer o no las conversiones correspodientes

			if ( strcmp( argv[arg_index], "-ob") == 0 ){
				//convertor.convertFile(input, output);
				output=1;
				//printMatrixToBinaryFile();
			}else{
				if ( strcmp( argv[arg_index], "-ot") == 0 ){
					///convertor.convertFile(input, output);
					output=2;
					//printMatrixToTextFile();
				}else{
					if ( strcmp( argv[arg_index], "-c") == 0 ){
						///convertor.convertFile(input,output);
						//printMatrixToTextFile();
						Sudoku::printSudoku();
					}
				}
			}
		}else{
			std::cout << "invalid";
		}

	}

}*/