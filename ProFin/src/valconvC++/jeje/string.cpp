#include "string.h"

bool String::string_equals(const char* text1, const char* text2)
{
	return String::string_compare(text1, text2) == 0;
}

int String::string_compare(const char* text1, const char* text2)
{
	int index = 0;
	//char* ptr;
	while ( text1[index] && text2[index] )
	{
		if ( text1[index] != text2[index] )
			return text1[index] - text2[index];
		//  return 105 - 73
		++index;
	}
	//     0            - 103 = -103
	return text1[index] - text2[index];
}

int String::string_compare_ptr(const char* text1, const char* text2)
{
//	while ( *text1 && *text2 && *text1++ == *text2++ )
	while ( *text1 && *text2 && *text1 == *text2 )
		++text1, ++text2;

	return *text1 - *text2;
}


int String::string_length(const char* text)
{
	int length = 0;
	while ( text[length] )
		++length;
	return length;
}

int String::string_copy_index(char* target, const char* source, int max_length)
{
	int index = 0;
	for ( ; source[index] && index < max_length; ++index )
		target[index] = source[index];

	target[index] = '\0';
	return index;
}

int String::string_copy(char* target, const char* source, int max_length)
{
	int counter = 0;
	while ( counter < max_length && (*target++ = *source++) )
		++counter;
	
	if ( counter == max_length )
		*target = '\0';
		
	return counter;
}

/*
	if ( input_filename[extension_index] == 'b'
		&& input_filename[extension_index + 1] == 'i'
		&& input_filename[extension_index + 2] == 'n'
		&& input_filename[extension_index + 3] == '\0' )

	if ( *extension == 'b'
		&& *(extension + 1) == 'i'
		&& *(extension + 2) == 'n'
		&& *(extension + 3) == '\0' )

	if ( extension[0] == 'b'
		&& extension[1] == 'i'
		&& extension[2] == 'n'
		&& extension[3] == '\0' )

	if ( *extension == 'b'
		&& *++extension == 'i'
		&& *++extension == 'n'
		&& *++extension == '\0'



	if ( condition )
		true-sentence;
	else
		false-sentence;

	condition ? true-expression : false-expression
*/
