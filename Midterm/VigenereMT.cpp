

#include "Vigenere.h"

using namespace std;


Vigenere::Vigenere(const std::string& aKeyword) : fKeywordProvider(aKeyword), fKeyword(aKeyword) {
	initializeTable();
}





std::string Vigenere::getCurrentKeyword() {
	std::string Result;



	for (size_t i = 0; i < fKeyword.length(); i++) {
		Result += *fKeywordProvider;
		fKeywordProvider << *fKeywordProvider;
	}

	return Result;
}


void Vigenere::reset() {
	fKeywordProvider.initialize(fKeyword);
}


char Vigenere::encode(char aCharacter) {
	char Result;


	int characterIndex = (int)toupper(aCharacter) - 65;


	int keywordIndex = (int)*fKeywordProvider - 65;


	if (isalpha(aCharacter)) {
		Result = fMappingTable[keywordIndex][characterIndex];
		fKeywordProvider << aCharacter;
	}
	else {
		Result = aCharacter;
	}

	if (!isupper(aCharacter)) {
		Result = tolower(Result);
	}


	return Result;
}


char Vigenere::decode(char aCharacter) {
	char Result;





	int keywordIndex = (int)*fKeywordProvider - 65;


	if (isalpha(aCharacter)) {
		for (size_t i = 0; i < CHARACTERS; i++) {

			if (fMappingTable[keywordIndex][i] == toupper(aCharacter)) {
				Result = (char)(i + 65);
				fKeywordProvider << Result;
			}
		}

	}
	else {
		Result = aCharacter;
	}

	if (!isupper(aCharacter)) {
		Result = tolower(Result);
	}


	return Result;



}


