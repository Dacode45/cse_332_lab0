// cse_332_lab0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cards.h"

#include<vector>
#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
	int toReturn = SUCCESS;

	const char* program_name = argv[command_line_argument::pragram_name];

	if (argc != expected_argument_count){
		int usageErr = usageMessage(program_name);
		handleErrMessages(program_name, usageErr);
		return usageErr;
	}

	const char* file_name = argv[command_line_argument::file_name];
	vector<Card> cards;
	int parseErr = parseCardFile(file_name, cards);
	if (parseErr){
		handleErrMessages(program_name, parseErr);
	}

	int printErr = printCards(cards);
	if (printErr){
		toReturn = printErr;
		handleErrMessages(program_name, printErr);
	}

	//a parsing error is ranked higher than any other errors
	//so I will return it before any other errors.
	return (parseErr)? parseErr: toReturn;
}

