void readSudokuFromTextFile(const char* input_filename, int sign);

void ConvertManager:: readSudokuFromTextFile(const char* input_filename, int sign)
{
	std::ifstream file;
	file.open(input_filename, std::ios::in);
	int sudokuDimension = 0;
	int sudokuLimit=0;
	if (!file.is_open())
	{
    	std::cerr << "Unable to open file" << input_filename << ".txt";
    	exit(1); 
	}else
	{      
		file >> sudokuDimension;
        this->sudoku.setDimension(sudokuDimension);
        sudokuLimit = sudokuDimension * sudokuDimension;
		this->sudoku.setLimit(sudokuLimit); 
		std::string auxiliar;
		int secAuxiliar = 0;
		for (int i = 0; i < sudokuLimit; i++) {  
			std::vector<int> board;  
			for (int j = 0; j < sudokuLimit; j++){   
		    	file >> auxiliar ;   
		    	if (auxiliar == ".")
		    	{
		       		board.push_back(0);
		    	}else
				{
					secAuxiliar = std::stoi(auxiliar);
					board.push_back(secAuxiliar);
				}
			}
			this->sudoku.setBoard(board);
		}  
	}
	file.close();
	if (sign==0){
		if(!this->sudoku.solveSudoku(0,0))
		{
			std::cout<< "unsolvable";
		}
	}
}
