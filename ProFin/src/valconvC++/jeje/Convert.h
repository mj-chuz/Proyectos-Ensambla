#ifndef CONVERT_H
#define CONVERT_H
#include <iostream>
#include <stdio.h>
#include <fstream.h>
#include <Sudoku.h>

/**
@brief Convert a text file containing floating point numbers to its binary form or viceversa
@param input_filename The path and name of the file to be converted
@return An error code, 0 for success
*/
class Convert
{

public:
	void convert_file(const char* input_filename, int signal, std::vector<std::vector<int>> vect1);

	//int find_extension_index(const char* filename);

	char* find_extension_ptr(char* filename);

	//int convert_binary_file_to_text(const char* input_filename);

	//int convert_text_file_to_binary(const char* input_filename);

	int convert_text_contents_to_binary(std::ifstream& input_file, std::ofstream& output_file, std::vector<std::vector<int>> vect1);

	char* replace_file_extension(const char* filename, const char* new_extension, char* output_filename);

	int convert_binary_contents_to_text(std::ifstream& input_file, std::ofstream& output_file, std::vector<std::vector<int>> vect1);

	int convert_file_with_extension(const char* input_filename, const char* input_mode, const char* output_mode, const char* target_extension, int signal, std::vector<std::vector<int>> vect1);
	};



#endif // CONVERT_H
