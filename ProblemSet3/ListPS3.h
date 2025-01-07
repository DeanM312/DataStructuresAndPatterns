
// COS30008, List, Problem Set 3, 2022

#pragma once

#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

using namespace std;
#include <stdexcept>



template<typename T>
class List
{
private:
	// auxiliary definition to simplify node usage
	using Node = DoublyLinkedList<T>;

	Node* fRoot;	// the first element in the list
	size_t fCount;	// number of elements in the list

public:
	// auxiliary definition to simplify iterator usage
    using Iterator = DoublyLinkedListIterator<T>;

	~List()                                                             // destructor - frees all nodes
    {
        while ( fRoot != nullptr )
        {
            if ( fRoot != &fRoot->getPrevious() )                       // more than one element
            {
                Node* lTemp = const_cast<Node*>(&fRoot->getPrevious()); // select last
                
                lTemp->isolate();                                       // remove from list
                delete lTemp;                                           // free
            }
            else
            {
                delete fRoot;                                           // free last
                break;                                                  // stop loop
            }
        }
    }

    void remove( const T& aElement )	                                // remove first match from list
    {
        Node* lNode = fRoot;                                            // start at first
        
        while ( lNode != nullptr )                                      // Are there still nodes available?
        {
            if ( **lNode == aElement )                                  // Have we found the node?
            {
                break;                                                  // stop the search
            }

            if ( lNode != &fRoot->getPrevious() )                       // not reached last
            {
                lNode = const_cast<Node*>(&lNode->getNext());           // go to next
            }
            else
            {
                lNode = nullptr;                                        // stop search
            }
        }
        
        // At this point we have either reached the end or found the node.
        if ( lNode != nullptr )                                         // We have found the node.
        {
            if ( fCount != 1 )                                          // not the last element
            {
                if ( lNode == fRoot )
                {
                    fRoot = const_cast<Node*>(&fRoot->getNext());       // make next root
                }
            }
            else
            {
                fRoot = nullptr;                                        // list becomes empty
            }
            
            lNode->isolate();                                           // isolate node
            delete lNode;                                               // release node's memory
            fCount--;                                                   // decrement count
        }
    }

	//////////////////////////////////////////////////////////////////
    //// PS3
    //////////////////////////////////////////////////////////////////
    
	// P1

    List() {
        fCount = 0;
        fRoot = nullptr;
       

    }

    bool empty() const                       // Is list empty?
    {
        if (fCount == 0) {
            return true;
        }
        else {
            return false;
        }
    }
	size_t size() const               		// list size
    {
        return fCount;
    }

	void push_front( const T& aElement )    // adds aElement at front
    {
        if (empty()) {
            fRoot = new Node(aElement);
        }
        else {
            Node* lNode = new Node(aElement);
            fRoot->push_front(*lNode);
            fRoot = lNode;
        }
        fCount++;
    }

    Iterator begin() const                     // return a forward iterator
    {
        Iterator lIterator(fRoot);
        return lIterator.begin();
    }
    Iterator end() const                       // return a forward end iterator
    {
        Iterator lIterator(fRoot);
        return lIterator.end();
    }
    Iterator rbegin() const                    // return a backwards iterator
    {
        Iterator lIterator(fRoot);
        return lIterator.rbegin();
    }
    Iterator rend() const                      // return a backwards end iterator
    {
        Iterator lIterator(fRoot);
        return lIterator.rend();

    }

	// P2
	
	void push_back( const T& aElement )        // adds aElement at back
    {

        Node* lNode = new Node(aElement);
        Node* lTemp = const_cast<Node*>(&fRoot->getPrevious());
        lTemp->push_back(*lNode);
        

        
        

        fCount++;
    }

	// P3

    const T& operator[]( size_t aIndex ) const	// list indexer
    {
        Iterator lIterator(fRoot);

        
        
        for (size_t i = 0; i < aIndex+1; i++) {

            if (i > fCount) {
                throw out_of_range("Index out of bounds.");
            }


            else if (i == aIndex) {
                return *lIterator;
            }

            lIterator++;
        }

    }

	// P4
	
    List( const List& aOtherList )             // copy constructor
    {
        fCount = 0;
        fRoot = nullptr;
        
        *this = aOtherList;
       


    }
    List& operator=(const List& aOtherList)	// assignment operator
    {

        if (&aOtherList != this) {

           
            this->~List();
            fCount = 0;
            

            for (size_t i = aOtherList.size(); i > 0; i--) {
                push_front(aOtherList[i - 1]);
            }

        }



        return *this;

    }
    
	// P5

    List( List&& aOtherList )       		// move constructor
    {
        
        
        fRoot = std::move(aOtherList.fRoot);
        fCount = std::move(aOtherList.fCount);
 
        aOtherList.fRoot = nullptr;
        aOtherList.fCount = 0;
       
        
        
        
    }
 
    List& operator=( List&& aOtherList ) noexcept      // move assignment operator
    {
        if (&aOtherList != this) {
            this->~List();
            fRoot = std::move(aOtherList.fRoot);
            fCount = std::move(aOtherList.fCount);
            
            aOtherList.fRoot = nullptr;
            aOtherList.fCount = 0;

        }
        

        return *this;
    }
 

    void push_front( T&& aElement )			// move push_front
    {
        T lElement = std::move(aElement);
        push_front(lElement);
    }
    void push_back( T&& aElement )				// move push_back
    {
        T lElement = std::move(aElement);
        push_back(lElement);
    }
};

