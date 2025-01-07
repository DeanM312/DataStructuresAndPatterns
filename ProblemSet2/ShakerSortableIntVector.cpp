#include "ShakerSortableIntVector.h";

using namespace std;

ShakerSortableIntVector::ShakerSortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements) : SortableIntVector(aArrayOfIntegers, aNumberOfElements) {

}

void ShakerSortableIntVector::sort(Comparable aOrderFunction) {
    int beginIndex = 0;
    int endIndex = size() - 1;

    while (beginIndex < endIndex) {
        for (size_t i = beginIndex; aOrderFunction(i, endIndex - 1); i++) {
            if (get(i) < get(i + 1)) {
                swap(i, i + 1);
            }
        }

        endIndex = endIndex - 1;

        for (size_t i = endIndex; i >= beginIndex + 1;i--) {
            if (get(i) > get(i - 1)) {
                swap(i, i - 1);
            }
        }

        beginIndex = beginIndex + 1;
    }
}