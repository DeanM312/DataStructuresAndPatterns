
#include "IntVector.h";
#include <stdexcept>

using namespace std;

IntVector::IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
{
    fNumberOfElements = aNumberOfElements;
    fElements = new int[fNumberOfElements];

    for (size_t i = 0; i < fNumberOfElements; i++)
    {
        fElements[i] = aArrayOfIntegers[i];
    }
}


IntVector::~IntVector() {
    delete fElements;
}


size_t IntVector::size() const {
    return fNumberOfElements;
}


const int IntVector::get(size_t aIndex) const {
    return fElements[aIndex];
}


void IntVector::swap(size_t aSourceIndex, size_t aTargetIndex) {

    
  

    if (aSourceIndex < fNumberOfElements && aTargetIndex < fNumberOfElements) {
        int first = fElements[aSourceIndex];
        fElements[aSourceIndex] = fElements[aTargetIndex];
        fElements[aTargetIndex] = first;
    }
    else {
        throw out_of_range("Illegal Vector Indices");
    }
   
   
    

    
}


const int IntVector::operator[](size_t aIndex) const {
    if (aIndex < fNumberOfElements) {
        return (*this).get(aIndex);
    }
    else {
        throw out_of_range("Illegal Vector Index");
    }
}