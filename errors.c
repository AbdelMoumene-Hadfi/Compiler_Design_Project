#include "errors.h"


// Error messages


char* errors[ERRORS_NUMBER] = {
    "if() expression cannot be executed.", 
    "object is missing in the code.",
    "non-numeric argument to a binary operator.",  // 1+"one" : number + char
    "could not find function.",
    " unexpected symbol",  //Error: unexpected symbol in "5x" => 5*x # OK  or x + 2 y * 3## Error: unexpected symbol in "x + 2 y" => x + 2; y * 3 # OK
    "unexpected symbol in 'if ' use ()", //if x > 0 {} ## Error: unexpected symbol in "if x" if(x > 0) {} # OK
    " unexpected 'else'", //In an if-else statement, the keyword else must appear on the same line as the end of the if block.
    "unexpected '='",  //'=' instead of '=='
    " unexpected numeric constant", //  c(1 2) => c(1,2)
    " Error: unexpected ')' in 'path'",// Not quoting file paths 'path.expand("")
    "unexpected symbol, Quotes inside strings", //Error: unexpected symbol in ""x"y"   "x\"y" # OK 'x"y'  # OK 
    "unexpected '}'" , // {}}
    "unexpected '{'", // {{}
    "(list) object cannot be coerced to type ‘double’", // when you’ve got an list of numeric strings which you want R to treat as numbers.
    "missing value where TRUE/FALSE needed", // when you sending a missing value (Null or N/A) to a field where a Boolean True / False is required

};

/*
 * Function called to raise an errors generated by
 * the compiler
 */

int current_line;

void raise_error(error_code ec) {
	if (ec >= ERRORS_NUMBER)
		printf("Error number %i: error without a message yet on line %i \n", ec, current_line);
	else 
		printf("Error number %i: %s on line %i \n", ec, errors[ec], current_line);
}