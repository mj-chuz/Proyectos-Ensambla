#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku
{
	private:
		int limit=0;

		std::vector<std::vector<int>>vect;

	public:
		Sudoku(int size, std::vector<std::vector<int>> vect1)
			:limit(size)

			,vect{vect1}
		{}

		void readMatrix();

		//void readMatrixFromBinaryFile();

		//void readMatrixFromTextFile(const char* input_filename);

		bool findBlank(int& row, int& col);

		bool checkRow(int row, int num);  

		bool checkCol(int col, int num);  

		bool checkMiniMatrix(int miniRow, int miniCol, int num); 

		bool solutionWorks(int row, int col, int num);  

		bool solveSudoku();  

		void printSudoku(); 

		//void printMatrixToBinaryFile();
		
		//void printMatrixToTextFile();

		//void analyzeArguments(int argc, char* argv[]);
		
};

#endif