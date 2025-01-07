#include "KeyProvider.h"
using namespace std;


KeyProvider::KeyProvider(const std::string& aKeyword) {
	initialize(aKeyword);
}


KeyProvider::~KeyProvider() {
	delete fKeyword;
}


void KeyProvider::initialize(const std::string& aKeyword) {
	fSize = aKeyword.length();
	fIndex = 0;

	delete fKeyword;
	fKeyword = new char[fSize];


	for (size_t i = 0; i < fSize; i++) {
		fKeyword[i] = toupper(aKeyword[i]);
	}

	
}


char KeyProvider::operator*() const {
	return fKeyword[fIndex];
}


KeyProvider& KeyProvider::operator<<(char aKeyCharacter) {
	
	fKeyword[fIndex] = toupper(aKeyCharacter);

	fIndex = fIndex + 1;

	if (fIndex >= fSize) {
		fIndex = 0;
	}

	return *this;
}