/*
cards.cpp
David Ayeke, ayekedavidr@wustl.edu
Implementation of definitions from cards.h
*/

#include "stdafx.h"
#include "cards.h"

//Initializing mapping
const char* Card::suitMap[4] = { "Clubs", "Diamonds", "Hearts", "Spades" };
const char* Card::rankMap[13] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };


int getRankFromChar(char rChar, Card::RANK &rank){
	int toReturn;
	switch (rChar){
		case '2':
			rank = Card::RANK::two;
			toReturn =  SUCCESS;
		break;

		case '3':
			rank = Card::RANK::three;
			toReturn = SUCCESS;
		break;

		case '4':
			rank = Card::RANK::four;
			toReturn = SUCCESS;
		break;

		case '5':
			rank = Card::RANK::five;
			toReturn = SUCCESS;
		break;

		case '6':
			rank = Card::RANK::six;
			toReturn = SUCCESS;
		break;

		case '7':
			rank = Card::RANK::seven;
			toReturn = SUCCESS;
		break;

		case '8':
			rank = Card::RANK::eight;
			toReturn = SUCCESS;
		break;

		case '9':
			rank = Card::RANK::nine;
			toReturn = SUCCESS;
		break;

		case '0':
			rank = Card::RANK::ten;
			toReturn = SUCCESS;
		break;

		case 'J':
		case 'j':
			rank = Card::RANK::jack;
			toReturn = SUCCESS;
		break;

		case 'Q':
		case 'q':
			rank = Card::RANK::queen;
			toReturn = SUCCESS;
		break;

		case 'K':
		case 'k':
			rank = Card::RANK::king;
			toReturn = SUCCESS;
		break;

		case 'A':
		case 'a':
			rank = Card::RANK::ace;
			toReturn = SUCCESS;
		break;

		default:
			//std::cout << "end " << rChar << "e";
			toReturn = IMPROPERFILEFORMAT;
		break;

	}

	return toReturn;
}

int getSuitFromChar(const char sChar, Card::SUIT &suit){
	switch (sChar)
	{
	case 'c':
	case 'C':
		suit = Card::SUIT::clubs;
		return SUCCESS;
	break;

	case 'd':
	case 'D':
		suit = Card::SUIT::diamonds;
		return SUCCESS;
	break;

	case 'h':
	case 'H':
		suit = Card::SUIT::hearts;
		return SUCCESS;
	break;

	case 's':
	case 'S':
		suit = Card::SUIT::spades;
		return SUCCESS;
	break;


	default:
		return IMPROPERFILEFORMAT;
		break;
	}

	return IMPROPERFILEFORMAT;
}

int parseCardFile(const char* filename, std::vector<Card> &cards){
	//Which Error to Return
	int toReturn = SUCCESS;
	std::string white_space_buffer; // used for skipping whitespace
	std::ifstream in(filename);
	
	if (in.is_open()){
		
		while (!in.eof()){
				
			if (in.fail()){
				in.clear();
				toReturn = ERRORDURINGFILEREADING;
			}
			else{

				in >> std::ws;
				char rankChar;
				in.get(rankChar);
				in >> std::ws;
				char suitChar;
				
				in.get(suitChar);
				in >> std::ws;
				if (suitChar == '0'){
					rankChar = '0';
					in.get(suitChar);
					in >> std::ws;
				}
				//line break

			
				
					Card::RANK rank;
					Card::SUIT suit;
					//std::cout << rankChar << suitChar;
					int rErr =getRankFromChar(rankChar, rank);
					int sErr = getSuitFromChar(suitChar, suit);
					if (rErr || sErr){
						/*
						Explaination.
						First it checks that there were no errors in parsing rank and suit.
						toReturn is initizlized to SUCCESS which is 0. so if this is the 
						first time an error happens, toReturn will equal a Parsing error.
						If this is not the first time there was an error, this will not 
						be evaluated. Notice i didn't do this for the previous ERRORDURINGFILEREADING;
						This error in my mind is a higher rank than a parsing error as the file might 
						be currupt so it gets precidence.
						*/
						//std::cout << "error\n";
						if (!toReturn){
							
							if (rErr){
								toReturn = rErr;
							}
							else{
								toReturn = sErr;
							}

						}

						//If the second character had the error, push the stream back one.
						//Ex parsing 77h
						//Rank will fall through as 7 suite wil try to be 7 error will be thrown.
						//Instead of the stream being h... and causing further errors it is now
						//7h which is completely vailid
						in.unget();
							
						
					}
					else{
						cards.push_back(Card(suit, rank));
					}

					
				}

			
		}
		in.close();
		return toReturn;
	}
	else{
		return CANTOPENFILE;
	}
}

int printCards(const std::vector<Card> &cards){
	//EX Three of Diamonds
	try{
		for (Card c : cards){
			std::cout << Card::rankMap[c.rank] << " of " << Card::suitMap[c.suit] << std::endl;
		}
		return SUCCESS;
	}
	catch (int e){
		std::cout << "C++ Error " << e;
		return FAILEDTOPRINTCARDS;
	}
	
}

int usageMessage(const char* programName){
	try{

		std::printf("Usage: %s card_file.txt", programName);
		return PRINTEDUSAGEMESSAGE;
	}
	catch (int e){
		std::cout << "C++ Error " << e;
		return FAILEDTOPRINTUSAGE;
	}
	
}

void handleErrMessages(const char* pName, int err){
	std::cout << std::endl;
	switch (err){
	case 0:// SUCCESS:

		break;
	case 1://CANTOPENFILE:
		std::cout << "Couldn't Open File. May not Exist\n";
		usageMessage(pName);
		break;
	case 2://IMPROPERFILEFORMAT:
		std::cout << "Card Format incorrect. Check Readme on the format\n";
		break;
	case 3:// ERRORDURINGFILEREADING:
		std::cout << "File opened, but there was an error while reading. File may be currupt\n";
		break;
	case 4://FAILEDTOPRINTUSAGE:
		std::cout << "This should never ever happen. Failed to print usage message\n";
		break;
	case 5://PRINTEDUSAGEMESSAGE:
		std::cout << "Printed Usage Message \n";
		break;

	case 6: //FAILEDTOPRINTCARDS
		std::cout << "This should not happen. C++ error: Unable to access vector<Cards>.\n";
		break;
	default:
		break;
	}
}