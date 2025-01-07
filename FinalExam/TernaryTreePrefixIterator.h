
// COS30008, Final Exam, 2022

#pragma once

#include "TernaryTree.h"

#include <stack>

template<typename T>
class TernaryTreePrefixIterator
{
private:
    using TTree = TernaryTree<T>;
    using TTreeNode = TTree*;
    using TTreeStack = std::stack<const TTree*>; 
    
    const TTree* fTTree;                // ternary tree
    TTreeStack fStack;                  // traversal stack

public:

    using Iterator = TernaryTreePrefixIterator<T>;
       
    Iterator operator++(int)
    {
        Iterator old = *this;

        ++(*this);
           
        return old;
    }
       
    bool operator!=( const Iterator& aOtherIter ) const
    {
        return !(*this == aOtherIter);
    }

/////////////////////////////////////////////////////////////////////////
// Problem 4: TernaryTree Prefix Iterator

private:
    
    // push subtree of aNode
    void push_subtrees(const TTree* aNode)
    {
        while (aNode->getLeft().empty())
        {
            fStack.push(&aNode->getLeft());
            aNode = &aNode->getLeft();
        }
    }

public:
    
	// iterator constructor
    TernaryTreePrefixIterator(const TTree* aTTree) : fTTree(aTTree)
    {
        if (fTTree->empty())
        {
            fStack.push(fTTree);
        }

        push_subtrees(fTTree);
    }

	// iterator dereference
    const T& operator*() const
    {
        return fStack.top()->operator*();
  
    }

    // prefix increment
    Iterator& operator++()
    {
        const TTree* previous = fStack.top();
        fStack.pop();


        if (!previous->getMiddle()->empty())
        {
            fStack.push(previous->getMiddle());
            push_subtrees(previous->getMiddle());
        }
        else if (!previous->getRight()->empty())
        {
            fStack.push(previous->getRight());
            push_subtrees(previous->getRight());
        }

        return *this;
    }

	// iterator equivalence
    bool operator==(const Iterator& aOtherIter) const
    {
        return fStack.size() == aOtherIter.fStack.size();
    }

	// auxiliaries
    Iterator begin() const
    {
        TernaryTreePrefixIterator Result = *this;
        return Result;
    }
    Iterator end() const
    {
        TernaryTreePrefixIterator Result = *this;
        Result.fStack = std::stack<const TTree*>();
        return Result;
    }
};
