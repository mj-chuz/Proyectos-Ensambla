#include "string.h"
#include "convert.h"
#include "Sudoku.h"
#include <iostream>
#include <fstream.h>


void Convert::convert_file(const char* input_filename, int signal, std::vector<std::vector<int>> vect1)
{
	if (signal==0){
		Convert::convert_file_with_extension(input_filename, "in", "out", "txt",  signal, std::vector<std::vector<int>> vect1);
	}else{
		Convert::convert_file_with_extension(input_filename, "in", "out", "bin",signal, std::vector<std::vector<int>> vect1);
	}
}

char* Convert::find_extension_ptr(char* filename)
{
	char* last_dot = NULL;
	while ( *filename )
	{
		if ( *filename == '.' )
			last_dot = filename;

		++filename; 
	}
	return last_dot ? last_dot + 1 : last_dot;
}

char* Convert::replace_file_extension(const char* filename, const char* new_extension, char* output_filename)
{
	String str;
	int length = str.string_length(filename);
	str.string_copy(output_filename, filename, length);
	char* extension = Convert::find_extension_ptr(output_filename);
	str.string_copy(extension, new_extension, str.string_length(new_extension));
	return output_filename;
}


int Convert::convert_binary_contents_to_text(std::ifstream &input_file, std::ofstream &output_file, std::vector<std::vector<int>> vect1)
{
	//double aux=0;
	for (int i=0; i<vect1.size(); i++)
	{
		for (int j=0; j<vect1.size(); j++)
		{
			input_file.read((char*) (&v[i][j]), sizeof(v[i][j]));
		}
	}


	for (int i=0; i<vect1.size(); i++)
	{
		for (int j=0; j<vect1.size(); j++)
		{
			output_file << v[i][j] << " "
		}
		output_file << std::endl;
	}
	/*
	while(input_file >>aux)
	{
		aux=aux/15;
		output_file<<aux<<" ";
	}
	
	_t value_count = 0;

	if ( fread(&value_count, sizeof(value_count), 1, input_file) != 1 )
		return 51;
	
	// size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream )
	if (fprintf(output_file, "%zu\n\n", value_count) <= 0 )
		return 52;
	
	for ( size_t index = 0; index < value_count; ++index )
	{
		double value = 0.0;
		if ( fread(&value, sizeof(double), 1, input_file) != 1 )
			return 53;

//		fprintf(stderr, "\t%zu[%lg]\n", index, value);
		if ( fprintf(output_file, "%.15lf\n", value) <= 0 )
			return 54;
	}*/
	
	return 0;
}


int Convert::convert_text_contents_to_binary(std::ifstream& input_file, std::ofstream& output_file, std::vector<std::vector<int>> vect1)
{
	//double aux=0;
	for (int i=0; i<vect1.size(); i++)
	{
		for (int j=0; j<vect1.size(); j++)
		{
			input_file >> vect1[i][j];
		}
	}




	for (int i=0; i<vect1.size(); i++)
	{
		for (int j=0; j<vect1.size(); j++)
		{
			output_file.write((char*)(&v[i][j]). sizeof(v[i][j]));
		}
	}
	/*
	int aux=0;
	while(input_file>>aux)
	{
		output_file << &aux << " ";
	}
	
	size_t value_count = 0;
	if ( fscanf(input_file, "%zu", &value_count) != 1 )
		return 41;

	if ( fwrite( &value_count, sizeof(value_count), 1, output_file ) != 1 )
		return 42;

	for ( size_t index = 0; index < value_count; ++index )
	{
		double value = 0.0;
		if ( fscanf(input_file, "%lg", &value) != 1 )
			return 43;
		
		if ( fwrite(&value, sizeof(double), 1, output_file) != 1 )
			return 44;
	}
	*/
	return 0;
}

int Convert::convert_file_with_extension(const char* input_filename, const char* input_mode, const char* output_mode, const char* target_extension, int signal, std::vector<std::vector<int>> vect1)
{
    String str;
	int error = 0;
	std::ifstream input_file;
	if (signal==0){
		input_file.open(input_filename, std::fstream::in, std::fstream::binary);
	}else{
		input_file.open(input_filename, std::fstream::in);
	}
	//FILE* input_file = fopen(input_filename, input_mode);
	if ( input_file )
	{

		char output_filename[ str.string_length(input_filename) + 1 ];
		Convert::replace_file_extension(input_filename, target_extension, output_filename);
		std::ofstream output_file;
		if (signal==1){
			output_file. open(output_filename, std::fstream::out, std::fstream::binary);
		}else{
			output_file.open(output_filename, std::fstream::out);
		}
		//FILE* output_file = fopen(output_filename, output_mode);
		if ( output_file )
		{

			if (signal==0)
			{
				Convert::convert_binary_contents_to_text(input_file, output_file);
			}else{
				Convert::convert_text_contents_to_binary(input_file, output_file);
			}
			output_file.close();
			//fclose(output_file);
		}
		else
		{
            std::cout<<"error: could not create "<< output_filename<<std::endl;
			error = 31;
		}
		input_file.close();
		//fclose(input_file);
	}
	else
	{
		std::cout<<"error: could not open "<<input_filename<<std::endl;
		error = 30;
	}

	return error;
}

