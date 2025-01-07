
// COS30008, Problem Set 4, Problem 3, 2022

#pragma once

#include "BinarySearchTree.h"

#include <stack>

template<typename T>
class BinarySearchTreeIterator
{
private:
    
    using BSTree = BinarySearchTree<T>;
    using BNode = BinaryTreeNode<T>;
    using BTreeNode = BNode*;
    using BTNStack = std::stack<BTreeNode>;

    const BSTree& fBSTree;		// binary search tree
    BTNStack fStack;			// DFS traversal stack
    
    void pushLeft(BTreeNode aNode)
    {
        while (!aNode->left->empty())
        {
            fStack.push(aNode->left);
            aNode = aNode->left;
        }
        

    }
    
public:
    
    using Iterator = BinarySearchTreeIterator<T>;
    
    BinarySearchTreeIterator(const BSTree& aBSTree) : fBSTree(aBSTree)
    {
        if (!fBSTree.fRoot->empty())
        {
            fStack.push(fBSTree.fRoot);
        }

      
        pushLeft(fStack.top());
        

    }

    const T& operator*() const
    {
        return fStack.top()->key;
    }
    Iterator& operator++()
    {
        BTreeNode previous = fStack.top();
        fStack.pop();

        if (!previous->right->empty())
        {
            fStack.push(previous->right);
            pushLeft(previous->right);
        }

        
        
        

        return *this;
    }
    Iterator operator++(int)
    {
        BinarySearchTreeIterator result = *this;

        ++(*this);

        return result;
    }
    bool operator==(const Iterator& aOtherIter) const
    {
        //cout << "| " << fStack.size() << "/" << aOtherIter.fStack.size() << " |";
        return fStack.size() == aOtherIter.fStack.size();
    }
    bool operator!=(const Iterator& aOtherIter) const 
    {
        return !(*this == aOtherIter);
    }
    
    Iterator begin() const
    {
        BinarySearchTreeIterator Result = *this;
        return Result;
    }
    Iterator end() const
    {
        BinarySearchTreeIterator Result = *this;
        Result.fStack = std::stack<BTreeNode>();
        return Result;
    }
};
