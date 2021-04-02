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

		void readMatrixFromBinaryFile(const char* input_filename);

		void readMatrixFromTextFile(const char* input_filename);

		bool findBlank(int& row, int& col);

		bool checkRow(int row, int num);  

		bool checkCol(int col, int num);  

		bool checkMiniMatrix(int miniRow, int miniCol, int num); 

		bool solutionWorks(int row, int col, int num);  

		bool solveSudoku(int r, int y);  

		void printSudoku(); 

		void printMatrixToBinaryFile(const char* input_filename);
		
		void printMatrixToTextFile(const char* input_filename);

		void analyzeArguments(int argc, char* argv[]);
		
};

#endif