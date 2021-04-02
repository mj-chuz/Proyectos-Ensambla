#ifndef STRING_H
#define STRING_H

#include <stdbool.h>

class String{

public:

	bool string_equals(const char* text1, const char* text2);

	int string_compare(const char* text1, const char* text2);

	int string_compare_ptr(const char* text1, const char* text2);

	int string_length(const char* text);

	int string_copy(char* target, const char* source, int max_length);

	int string_copy_index(char* target, const char* source, int max_length);

};

/*
bool string_equals(const char* text1, const char* text2);

int string_compare(const char* text1, const char* text2);

int string_compare_ptr(const char* text1, const char* text2);

int string_length(const char* text);

int string_copy(char* target, const char* source, int max_length);

int string_copy_index(char* target, const char* source, int max_length);

*/
#endif // STRING_H
