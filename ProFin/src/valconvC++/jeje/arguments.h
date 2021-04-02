#ifndef ARGUMENTS_H
#define ARGUMENTS_H
#include <iostream>
#include <stdbool.h>

class Arguments
{
private:
	bool help_asked;            // 1 @8000
	bool version_asked;         // 1 @8001
	//conversion_t convert_to; 
	int convert_to;   // 4 @8004, 8008, ...
	bool is_valid;
	const char* output_format; 

public:
	Arguments()
	:help_asked(false)
	,version_asked{false}
	,convert_to{0}
	,is_valid{true}
	,output_format{nullptr}

{}

	int print_help(void);

	int print_version(void);

	bool isValid();

	bool helpAsked();

	bool versionAsked();

	//1void init_arguments(arguments_t* arguments);

	void analyze_arguments(int argc, char* argv[]);

	void analyze_conversion_type(int destination, int complement);

	//void analyze_conversion_type(arguments_t* arguments, conversion_t destination, conversion_t complement);

};


///int print_help(void);

///int print_version(void);

//typedef unsigned long int size_t;
/*
typedef enum
{
	TO_UNKNOWN, // 0
	TO_BINARY,
	TO_TEXT,
} conversion_t;


typedef struct // @8000
{
	bool help_asked;            // 1 @8000
	bool version_asked;         // 1 @8001
	conversion_t convert_to;    // 4 @8004, 8008, ...
	bool is_valid;
	const char* output_format;  // 8 @8008, 8016, ...
} arguments_t;


void init_arguments(arguments_t* arguments);

arguments_t analyze_arguments(int argc, char* argv[]);

void analyze_conversion_type(arguments_t* arguments, conversion_t destination, conversion_t complement);
*/
#endif // ARGUMENTS_H
