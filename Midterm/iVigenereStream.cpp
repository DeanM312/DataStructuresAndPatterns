#include "iVigenereStream.h"
using namespace std;



iVigenereStream::iVigenereStream(Cipher aCipher, const std::string& aKeyword, const char* aFileName) : fCipher(aCipher), fCipherProvider(aKeyword) {
	open(aFileName);
}
iVigenereStream::~iVigenereStream() {
	close();
}

void iVigenereStream::open(const char* aFileName) {
	if (aFileName != nullptr) {
		fIStream.open(aFileName, ofstream::binary);
	}
}
void iVigenereStream::close() {
	fIStream.clear();
	fIStream.close();
}
void iVigenereStream::reset() {
	fCipherProvider.reset();
	seekstart();
}



bool iVigenereStream::good() const {
	return fIStream.good();
}
bool iVigenereStream::is_open() const {
	return fIStream.is_open();
}
bool iVigenereStream::eof() const {
	return fIStream.eof();
}

iVigenereStream& iVigenereStream::operator>>(char& aCharacter) {
	if (!eof()) {
		aCharacter = fCipher(fCipherProvider, fIStream.get());
	}


	return *this;
}