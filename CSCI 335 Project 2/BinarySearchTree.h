#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "dsexceptions.h"
#include <algorithm>
#include <utility>
using namespace std;       

// BinarySearchTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// void queryTree( x )    --> Prints Enzyme Acronym associated with X
// int size( )            --> Returns an integer containing the number of nodes in the tree
// int aDepth( )          --> Returns an integer containing the averagge depth of the tree
// pair find( x )         --> Finds x and returns a pair <bool, int> on wether it found it and how many recursion calls.
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class BinarySearchTree
{
  public:
    BinarySearchTree( ) : root{ nullptr }
    {
    }

    /**
     * Copy constructor
     */
    BinarySearchTree( const BinarySearchTree & rhs ) : root{ nullptr }
    {
        root = clone( rhs.root );
    }

    /**
     * Move constructor
     */
    BinarySearchTree( BinarySearchTree && rhs ) : root{ rhs.root }
    {
        rhs.root = nullptr;
    }
    
    /**
     * Destructor for the tree
     */
    ~BinarySearchTree( )
    {
        makeEmpty( );
    }

    /**
     * Copy assignment
     */
    BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        BinarySearchTree copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    /**
     * Move assignment
     */
    BinarySearchTree & operator=( BinarySearchTree && rhs )
    {
        std::swap( root, rhs.root );       
        return *this;
    }
    
    
    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMin( root )->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMax( root )->element;
    }

    /**
     * Returns true if x is found in the tree.
     */
    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty( ) const
    {
        return root == nullptr;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void printTree( ostream & out = cout ) const
    {
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            printTree( root, out );
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    {
        makeEmpty( root );
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( const Comparable & x )
    {
        insert( x, root );
    }
     
    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( Comparable && x )
    {
        insert( std::move( x ), root );
    }
    
    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove( const Comparable & x )
    {
        remove( x, root );
    }

    /**
     * Prints the enzye associated with Recognition Sequence in string x.
     */
    void QueryTree( const string x )
    {
        QueryTree( x, root );
    }

    /**
     * Returns the number of nodes in the tree
     */
    int size() {
        return size( root );
    }

    /**
     * Returns the number of nodes in the tree
     */
    int aDepth() {
        int sumDepth = 0;
        return aDepth ( root, sumDepth );
    }

    /**
     * Returns a pair if it found x and how many recursive calls it took
     */
    pair<bool, int> find( const string x ) {
        pair<bool, int> results(false, 0);
        return find( x, root, results);
    }

    /**
     * Returns a pair of wether it removed it and how many recursive calls it took
     */
    pair<bool, int> del( const string x ) {
        pair<bool, int> result(false, 0);
        return del( x, root, result );
    }

  private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
          : element{ theElement }, left{ lt }, right{ rt } { }
        
        BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt )
          : element{ std::move( theElement ) }, left{ lt }, right{ rt } { }
    };

    BinaryNode *root;


    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, BinaryNode * & t )
    {
        if( t == nullptr )
            t = new BinaryNode{ x, nullptr, nullptr };
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        else if(t->element == x )
            t->element.Merge(x);  // Duplicate; 
    }
    
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( Comparable && x, BinaryNode * & t )
    {
        if( t == nullptr )
            t = new BinaryNode{ std::move( x ), nullptr, nullptr };
        else if( x < t->element )
            insert( std::move( x ), t->left );
        else if( t->element < x )
            insert( std::move( x ), t->right );
        else if( t->element == x )
            t.element.Merge( x );  // Duplicate;
    }

    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove( const Comparable & x, BinaryNode * & t )
    {
        if( t == nullptr )
            return;   // Item not found; do nothing
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            BinaryNode *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            delete oldNode;
        }
    }

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    BinaryNode * findMin( BinaryNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        if( t->left == nullptr )
            return t;
        return findMin( t->left );
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    BinaryNode * findMax( BinaryNode *t ) const
    {
        if( t != nullptr )
            while( t->right != nullptr )
                t = t->right;
        return t;
    }


    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
    bool contains( const Comparable & x, BinaryNode *t ) const
    {
        if( t == nullptr )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else if( t->element == x )
            return true;    // Match
    }
/****** NONRECURSIVE VERSION*************************
    bool contains( const Comparable & x, BinaryNode *t ) const
    {
        while( t != nullptr )
            if( x < t->element )
                t = t->left;
            else if( t->element < x )
                t = t->right;
            else
                return true;    // Match

        return false;   // No match
    }
*****************************************************/

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( BinaryNode * & t )
    {
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree( BinaryNode *t, ostream & out ) const
    {
        if( t != nullptr )
        {
            printTree( t->left, out );
            out << t->element << endl;
            printTree( t->right, out );
        }
    }

    void QueryTree( const string x , BinaryNode *t ) 
    {   
        if( t == nullptr ){
            cout  << "Not Found" << endl;
        }
        else if( x.compare(t->element.getRecSeq()) < 0 ){
            QueryTree( x, t->left );
        }
        else if( x.compare(t->element.getRecSeq()) > 0 ){
            QueryTree( x, t->right );
        }
        else if( x.compare(t->element.getRecSeq()) == 0 ){
            cout << "found: " << t->element << endl; 
        }
    }

    int size( BinaryNode *t )
    {
        if( t == nullptr ){
            return 0;
        } else {
            return size( t->left ) + size( t->right ) + 1; 
        }
    }

    int aDepth( BinaryNode *t, int sumDepth ) 
    {
        if( t == nullptr ){
            return 0;
        } else {
            return sumDepth + aDepth( t->left, sumDepth + 1 ) + aDepth( t->right, sumDepth + 1 );
        }
    }

    pair<bool, int> find( const string x , BinaryNode *t, pair<bool, int> result ) 
    {   
        if( t == nullptr ){
            result.first = false;
            result.second = result.second + 1;
            pair<bool, int> other (result);
            return other;
        }
        else if( x.compare(t->element.getRecSeq()) < 0 ){
            result.second = result.second + 1;
            find( x, t->left, result );
        }
        else if( x.compare(t->element.getRecSeq()) > 0 ){
            result.second = result.second + 1;
            find( x, t->right, result );
        }
        else if( x.compare(t->element.getRecSeq()) == 0 ){
           result.first = true;
           result.second = result.second + 1;
           pair<bool, int> other (result);
           return other;
        }
    }

    pair<bool, int> del( const string x, BinaryNode * & t, pair<bool, int> result )
    {
        if( t == nullptr ) {
            result.first = false;
            result.second += 1;
            return result;
        }
        if( x.compare(t->element.getRecSeq()) < 0 ){
            result.second += 1;
            del( x, t->left, result );
        }
        else if( x.compare(t->element.getRecSeq()) > 0 ){
            result.second += 1;
            del( x, t->right, result );
        }
        else if( t->left != nullptr && t->right != nullptr ){ // Two children
            t->element = findMin( t->right )->element;
            result.second += 1;
            del( x, t->right, result );
        } else {
            BinaryNode *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            result.first = true;
            result.second += 1;
            delete oldNode;
            return result;
        }
    }

    /**
     * Internal method to clone subtree.
     */
    BinaryNode * clone( BinaryNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        else
            return new BinaryNode{ t->element, clone( t->left ), clone( t->right ) };
    }
};

#endif
