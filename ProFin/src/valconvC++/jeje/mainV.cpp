#include "arguments.h"
#include "arguments.h"
#include "convert.h"
#include "string.h"
#include "string.h"

//const size_t MAX_SIZE_T = ((size_t)-1);
//#define MAX_SIZE_T ((size_t)-1);

//int main(int argument_count, char* argument_vector[])
int main(int argc, char* argv[])
{
	// arguments_t r1;
	Arguments arguments;
	Convert convert;
	arguments.analyze_arguments(argc, argv);
	//arguments_t arguments = analyze_arguments(argc, argv);
	
	if ( ! arguments.isValid() )
		return 1;
	if ( arguments.helpAsked() )
		return arguments.print_help();
	if ( arguments.versionAsked() )
		return arguments.print_version();
	
	for ( int arg_index = 1; arg_index < argc; ++arg_index )
		/*valconv.so:*/convert.convert_file( argv[arg_index], 0 );

	return 0;
}
