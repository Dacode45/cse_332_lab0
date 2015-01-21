/*
cards.cpp
David Ayeke, ayekedavidr@wustl.edu
Definitions of playing cards and functions to use them
*/
#ifndef CARDS_H
#define CARDS_H


const int expected_argument_count = 2;
enum command_line_argument:int{pragram_name, file_name};

struct Card{
	enum  SUIT:int{clubs, diamonds, hearts, spades};
	//map { "Clubs", "Diamonds", "Hearts", "Spades" };
	static const char* suitMap[4]; 
	//made the underlying type an int so that I could compare two cards rank easilly
	enum  RANK:int{two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace}; 
	// map Ranks to string
	static const char* rankMap[13];
	SUIT suit;
	RANK rank;

	Card(SUIT s, RANK r){
		suit = s;
		rank = r;
	}

};

//Parses ; file, and puts contents into a vector. Returns Success or Error.
int parseCardFile(const char* filename, std::vector<Card> &cards);
//Print out cards in vector
int printCards(const std::vector<Card> &cards);
//Usage Message 
int usageMessage(const char* programName);
//couts error message
void handleErrMessages(const char* pName, int err);


#define SUCCESS 0;
#define CANTOPENFILE 1;
#define IMPROPERFILEFORMAT 2;
#define ERRORDURINGFILEREADING 3;
#define FAILEDTOPRINTUSAGE  4;
#define PRINTEDUSAGEMESSAGE 5;
#define FAILEDTOPRINTCARDS 6;

#endif // !CARDS_H
