David Ayeke, ayekedavidr@wustl.edu
CSE 332 Lab 0: Basic C++ Program Structure and Data Movement
Usage program card_file.txt

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

Extra Credit