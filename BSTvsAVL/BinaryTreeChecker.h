/**
 * A binary tree checker for those of us who are paranoid
 * about getting binary trees correct. It maintains a running
 * copy of a tree's node data in set elements. A tree node
 * deletion has a corresponding set element deletion. The tree
 * node data is compared to the set elements. Print both the
 * tree node data and the set elements to verify they match.
 *
 * Author: Ron Mak
 *         Department of Computer Engineering
 *         San Jose State University
 */
#ifndef BINARY_TREE_CHECKER_H
#define BINARY_TREE_CHECKER_H

#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
#include "BinaryNode.h"
#include "BinarySearchTree.h"

enum class TreeStatus
{
    NO_ERROR, DATA_MISMATCH, INSUFFICIENT_DATA, REMAINING_DATA
};

ostream& operator <<(ostream& out, const TreeStatus& status);

class BinaryTreeChecker
{
public:
    /**
     * Constructor.
     * @param tree the tree to check.
     */
    BinaryTreeChecker(BinarySearchTree& tree);

    /**
     * Destructor.
     */
    virtual ~BinaryTreeChecker();

    /**
     * Clear the cache.
     */
    void clear();

    /**
     * Add a tree node's data item to the cache.
     * @param data the data item to add.
     */
    void add(const int data);

    /**
     * Remove a data item from the cache.
     * @param data the data item to remove.
     */
    void remove(const int data);

    /**
     * Check the tree's current data items against the cache.
     * @param do_dump true to dump the tree and cache data items.
     * @return the tree status.
     */
    TreeStatus check(bool do_dump);

private:
    BinarySearchTree& tree;  // the tree to check
    set<int> cache;          // the cache of data items
    set<int> data;           // the tree's data items

    /**
     * Do an inorder walk of the tree to collect its data items.
     * @param node the root node of the subtree to walk (initially the tree root).
     */
    void walk(BinaryNode *node);

    /**
     * Compare the tree's data items against the data items in the cache.
     * @param do_dump true to dump the tree and cache data items.
     * @return the tree status.
     */
    TreeStatus compare(bool do_dump);
};

#endif // BINARY_TREE_CHECKER_H
