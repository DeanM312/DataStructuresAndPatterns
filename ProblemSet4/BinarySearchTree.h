
// COS30008, Problem Set 4, Problem 2, 2022

#pragma once

#include "BinaryTreeNode.h"

#include <stdexcept>

// Problem 3 requirement
template<typename T>
class BinarySearchTreeIterator;

template<typename T>
class BinarySearchTree
{
private:

    using BNode = BinaryTreeNode<T>;
    using BTreeNode = BNode*;

    BTreeNode fRoot;
    
public:

    BinarySearchTree() : fRoot()
    {
       
    }

    ~BinarySearchTree()
    {
        delete fRoot;
    }

    bool empty() const
    {
        fRoot->empty();
    }
    size_t height() const
    {
        if (fRoot != nullptr)
        {
            return fRoot->height();
        }
        return 0;
    }
    
    bool insert(const T& aKey)
    {
        if (fRoot != nullptr)
        {
            return fRoot->insert(aKey);
        }
        else
        {
            fRoot = new BinaryTreeNode<T>(aKey);
        }
    }
    bool remove(const T& aKey) {
        if (!fRoot->leaf()) {
            return fRoot->remove(aKey, fRoot);
        }
        else
        {
            fRoot = NULL;
        }
    }

	// Problem 3 methods
    
    using Iterator = BinarySearchTreeIterator<T>;

    // Allow iterator to access private member variables
    friend class BinarySearchTreeIterator<T>;

    Iterator begin() const
    {
        Iterator Result(*this);
        return Result.begin();
    }
    Iterator end() const
    {
        Iterator Result(*this);
        return Result.end();
    }
};
