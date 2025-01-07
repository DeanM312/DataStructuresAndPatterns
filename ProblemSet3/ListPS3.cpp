#include "ListPS3.h";



using namespace std;


List::List() {

}

bool List::empty() const;
size_t List::size() const;                		// list size

void List::push_front(const T& aElement);	    // adds aElement at front

Iterator List::begin() const;                     // return a forward iterator
Iterator List::end() const;                       // return a forward end iterator
Iterator List::rbegin() const;                    // return a backwards iterator
Iterator List::rend() const;                      // return a backwards end iterator




