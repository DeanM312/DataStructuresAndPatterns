
#include "VigenereForwardIterator.h"

using namespace std;



VigenereForwardIterator::VigenereForwardIterator(iVigenereStream& aIStream) : fIStream(aIStream), fEOF(false) {
	fIStream >> fCurrentChar;
}


char VigenereForwardIterator::operator*() const {
	return fCurrentChar;
}
VigenereForwardIterator& VigenereForwardIterator::operator++() {
	fIStream >> fCurrentChar;
	
	
	fEOF = fIStream.eof();


	return *this;
}
VigenereForwardIterator VigenereForwardIterator::operator++(int) {
	VigenereForwardIterator Result = *this;

	++(*this);

	return Result;
}

bool VigenereForwardIterator::operator==(const VigenereForwardIterator& aOther) const {
	


	bool Result;

	if (*aOther == fCurrentChar && aOther.fEOF == fEOF) {
		Result = true;
	}
	else {
		Result = false;
	}

	
	return Result;
	
}
bool VigenereForwardIterator::operator!=(const VigenereForwardIterator& aOther) const {
	bool Result;

	if (aOther.fEOF != fEOF) {
		Result = true;
	}
	else {
		Result = false;
	}

	return Result;


}

VigenereForwardIterator VigenereForwardIterator::begin() const {
	fIStream.reset();
	fIStream.seekstart();
	return *this;
}
VigenereForwardIterator VigenereForwardIterator::end() const {
	VigenereForwardIterator Result = *this;

	Result.fEOF = true;
	return Result;
}
