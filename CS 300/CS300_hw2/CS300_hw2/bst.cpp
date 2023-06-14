#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


#include <iostream>
#include <string>
#include "binarysearchtree.h"

using namespace std;

/**
 * Construct the tree.
 */
template <class Comparable>
BinarySearchTree<Comparable>::
BinarySearchTree(const Comparable & notFound ) :
              ITEM_NOT_FOUND( notFound ), root( NULL )
{
}


/**
 * Internal method to get element field in node t.
 * Return the element field or ITEM_NOT_FOUND if t is NULL.
 */
template <class Comparable>
const Comparable & BinarySearchTree<Comparable>::
elementAt( BinaryNode<Comparable> *t ) const
{
    return t == NULL ? ITEM_NOT_FOUND : t->element;
}



/**
 * Find item x in the tree.
 * Return the matching item or ITEM_NOT_FOUND if not found.
 */
 template <class Comparable>
 const Comparable & BinarySearchTree<Comparable>::
 find( const Comparable & x ) const
 {
      return elementAt( find( x, root ) );
 }


/**
 * Internal method to find an item in a subtree.
 * x is item to search for.
 * t is the node that roots the tree.
 * Return node containing the matched item.
 */
template <class Comparable>
BinaryNode<Comparable> *
BinarySearchTree<Comparable>::
find( const Comparable & x, BinaryNode<Comparable> * t ) const
{
     if ( t == NULL )
          return NULL;
     else if( x < t->element )
          return find( x, t->left );
     else if( t->element < x )
          return find( x, t->right );
     else
          return t;    // Match
}
