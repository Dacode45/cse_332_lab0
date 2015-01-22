David Ayeke, ayekedavidr@wustl.edu
CSE 332 Lab 0: Basic C++ Program Structure and Data Movement

Program Parses rank suit pairs to print the full card name
Ex
7C  => Seven of Clubs
kS  => King of Spades
10D => 10 of Diamonds
AH  => Ace of Hearts



//Compilation Errors and Warnings
There were none.
//
Test card_file.txt
Downloaded from website. Ran fast with no errors as expected. Returned 0.
in.txt
File with 500 cards. Ran fast with no errors as expected. Returned 0.
in_ws.txt
File with 500 cards. Random white space, tabs, and line breaks between definitions. Ran with no errors as expected. Returned 0.
in_format.txt
First Card had several commas ,,,, and gibberish. Program ran as expected printing out the other cards it could parse.
//Important Note
I have designed this program to only parse rank suite pairs. 
7fjafD7H44g will only output 7 of hearts not 7 of Diamonds && 7 of Hearts.
rank and suite must be together. that is why k,,D will not work and ,,,,kD will.

Extra Credit.
ayekedavidr@shell ~
Makefile would not work because I used cpp 11 features like scoped enums.
So I compiled with the command g++ -std=c++11 -pedantic -Wall -o lab0.out cards.cpp cse_332_lab0.cpp

Both the in.txt and in_ws.txt ran fine.
The in_format.txt ran infinitely. It turns out linux does not provide an
endoffile bit in c++ and I have a while loop that checks for when this bit 
occurs and ends reading of the file once it does. 
I had to change my loop from while(!in.eof())
to 
in >> std::ws;
char rankChar
while(in.get(rankChar))
	if(in.eof())
		break;

This fixed everything and in_format.txt ran the same as it did on windows.
I am not quite sure why in.txt and in_ws.txt ran despite this issue. It is
possible that my use of in.unget() whenever the file is improperly formatted
was at play. 
