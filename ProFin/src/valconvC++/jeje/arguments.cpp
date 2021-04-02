#include <stdio.h>
#include <string.h>

#include "arguments.h"

#include <iostream>

/*void init_arguments(arguments_t* arguments)
{
	(*arguments).help_asked = false;
	arguments->version_asked = false;
	arguments->convert_to = TO_UNKNOWN;
	arguments->is_valid = true;
	arguments->output_format = NULL;
}
*/
void Arguments::analyze_arguments(int argc, char* argv[])
{
	//arguments_t arguments;
	//init_arguments(&arguments);
	// printf("sizeof(arguments) = %zu\n", sizeof(arguments));

	for ( int arg_index = 1; arg_index < argc; ++arg_index )
	{
		if ( strcmp( argv[arg_index], "--help") == 0 )
			this->help_asked = true;
		if ( strcmp( argv[arg_index], "--version") == 0 )
			this->version_asked = true;
		if ( strcmp( argv[arg_index], "-b") == 0 )
			analyze_conversion_type(1, 2);
		if ( strcmp( argv[arg_index], "-t") == 0 )
			analyze_conversion_type(2, 1);
	}

}


/*
arguments_t analyze_arguments(int argc, char* argv[])
{
	arguments_t arguments;
	init_arguments(&arguments);
	// printf("sizeof(arguments) = %zu\n", sizeof(arguments));

	for ( int arg_index = 1; arg_index < argc; ++arg_index )
	{
		if ( strcmp( argv[arg_index], "--help") == 0 )
			arguments.help_asked = true;
		if ( strcmp( argv[arg_index], "--version") == 0 )
			arguments.version_asked = true;
		if ( strcmp( argv[arg_index], "-b") == 0 )
			analyze_conversion_type(&arguments, 1, 2);
		if ( strcmp( argv[arg_index], "-t") == 0 )
			analyze_conversion_type(&arguments, 2, 1);
	}

	return arguments;
}

*/

///void analyze_conversion_type(arguments_t* arguments, conversion_t destination, conversion_t complement)
void Arguments::analyze_conversion_type(int destination, int complement)
{
	if (this-> convert_to != complement)
	///if ( arguments->convert_to != complement )
		this-> convert_to = destination;
		//arguments->convert_to = destination;
	else
	{
		fprintf(stderr, "valconv: error: only a conversion type is allowed\n");
		//arguments->is_valid = false;
		this->is_valid = false;
	}
}

bool Arguments::isValid()
{
	bool valid=false;
	if (this->is_valid)
	{
		valid=true;
	}
	return valid;
}

bool Arguments::helpAsked()
{
	bool help=false;
	if (this->help_asked)
	{
		help=true;
	}
	return help;
}

bool Arguments::versionAsked()
{
	bool version=false;
	if (this->version_asked)
	{
		version=true;
	}
	return version;
}

/*onst char* const valconv_help =
	"usage: valconv [options] files...\n"
	"\n"
	"Options:\n"
	"  -b       Converts all files to binary\n"
	"  -t       Converts all files to text format\n"
	"\n"
	"If no conversion type is given, the file extension will be used\n";
*/
int Arguments::print_help(void)
{
	const char* const valconv_help =
	"usage: valconv [options] files...\n"
	"\n"
	"Options:\n"
	"  -b       Converts all files to binary\n"
	"  -t       Converts all files to text format\n"
	"\n"
	"If no conversion type is given, the file extension will be used\n";
	//printf("%s", valconv_help);
	std::cout << valconv_help;

	return 0;
}


int Arguments::print_version(void)
{
	std::cout << "valconv v1.1 20200515 ECCI-UCR" << std::endl;
	//printf("valconv v1.1 20200515 ECCI-UCR\n");
	std::cout << "This is free software. Use it at your own risk" << std::endl;
	///printf("This is free software. Use it at your own risk\n");
	return 0;
}
