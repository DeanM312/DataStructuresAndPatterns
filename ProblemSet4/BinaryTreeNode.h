
// COS30008, Problem Set 4, Problem 1, 2022

#pragma once

#include <stdexcept>
#include <algorithm>

template<typename T>
struct BinaryTreeNode
{
    using BNode = BinaryTreeNode<T>;
    using BTreeNode = BNode*;
    
    T key;
    BTreeNode left;
    BTreeNode right;
    
    static BNode NIL;
    
    const T& findMax() const
    {
        if ( empty() )
        {
            throw std::domain_error( "Empty tree encountered." );
        }
        
        return right->empty() ? key : right->findMax();
    }

    const T& findMin() const
    {
        if ( empty() )
        {
            throw std::domain_error( "Empty tree encountered." );
        }
        
        return left->empty() ? key : left->findMin();
    }

    bool remove( const T& aKey, BTreeNode aParent )
    {
        BTreeNode x = this;
        BTreeNode y = aParent;

        while ( !x->empty() )
        {
            if ( aKey == x->key )
            {
                break;
            }

            y = x;                                      // new parent
            
            x = aKey < x->key ? x->left : x->right;
        }

        if ( x->empty() )
        {
            return false;                               // delete failed
        }
        
        if ( !x->left->empty() )
        {
            const T& lKey = x->left->findMax();         // find max to left
            x->key = lKey;
            x->left->remove( lKey, x );
        }
        else
        {
            if ( !x->right->empty() )
            {
                const T& lKey = x->right->findMin();    // find min to right
                x->key = lKey;
                x->right->remove( lKey, x );
            }
            else
            {
                if ( y != &NIL )                        // y can be NIL
                {
                    if ( y->left == x )
                    {
                        y->left = &NIL;
                    }
                    else
                    {
                        y->right = &NIL;
                    }
                }
                
                delete x;                               // free deleted node
            }
        }

        return true;
    }

    // PS4 starts here
    
    BinaryTreeNode() : key(T()), left(&NIL), right(&NIL) {

    }
    BinaryTreeNode(const T& aKey) : key(aKey), left(&NIL), right(&NIL) {

    }
    BinaryTreeNode(T&& aKey) : key(std::move(aKey)), left(&NIL), right(&NIL) {
        
    }

    ~BinaryTreeNode() {
        if (!left->empty()) {
            delete left;
        }
        if (!right->empty()) {
            delete right;
        }
        
    }
    
    bool empty() const {
        return this == &NIL;
    }
    bool leaf() const {
        if (left->empty() && right->empty()) {
            return true;
        }
        return false;
    }
    size_t height() const {



        if (this->empty()) {
            throw std::domain_error("Empty tree encountered.");
        }
        else
        {
            if (!left->empty() && !right->empty())
            {
                size_t lDepth = left->height();
                size_t rDepth = right->height();


                return lDepth > rDepth ? lDepth + 1 : rDepth + 1;

                
            }
            else if (!left->empty()) {
                size_t lDepth = left->height();

                return lDepth + 1;

            }
            else if (!right->empty()) {
                size_t rDepth = right->height();

                return rDepth + 1;
            }
            else
            {
                return 0;
            }
    

        }


      
    }

    bool insert(const T& aKey) {
        BTreeNode x = this;
        BTreeNode y = &NIL;

        while (!x->empty())
        {
            y = x;


            if (aKey == x->key)
            {
                return false;
            }

                                             

            x = aKey < x->key ? x->left : x->right;
           
        }

        BTreeNode z = new BinaryTreeNode<T>(aKey);


        if (y->empty())
        {
            return false;
        }
        else
        {
            if (aKey < y->key)
            {
                y->left = z;
            }
            else
            {
                y->right = z;
            }


        }


        
        
    }
};

template<typename T>
BinaryTreeNode<T> BinaryTreeNode<T>::NIL;
