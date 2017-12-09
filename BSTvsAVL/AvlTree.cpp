#include <iostream>
#include "AvlTree.h"

using namespace std;

AvlTree::AvlTree(): BinarySearchTree()
{
}

AvlTree::~AvlTree()
{
}

int AvlTree::height(const BinaryNode *ptr) const
{
    return ptr == nullptr ? -1 : ptr->height;
}

void AvlTree::insert(const long data, BinaryNode* &ptr)
{
    BinarySearchTree::insert(data, ptr);
    rebalance(ptr);
}

void AvlTree::remove(const long data, BinaryNode* &ptr)
{
    BinarySearchTree::remove(data, ptr);
    rebalance(ptr);
}

/*
 * Reference: Prof: Ron Maks slides
 */
BinaryNode *AvlTree::rebalance(BinaryNode* &ptr)
{
	if (ptr == nullptr) return ptr;

	// Left side too high.

	if (height(ptr->left) - height(ptr->right) > 1)
	{
		if (height(ptr->left->left) >= height(ptr->left->right))
		{
			ptr = singleRightRotation(ptr);
			cout << "    --- Single right rotation at " << ptr->data << endl;
		}
		else
		{
			ptr = doubleLeftRightRotation(ptr);
	        cout << "    --- Double left-right rotation at " << ptr->data << endl;
		}
	}
    else if (height(ptr->right) - height(ptr->left) > 1)
    {
        if (height(ptr->right->right) >= height(ptr->right->left))
        {
            ptr = singleLeftRotation(ptr);
            cout << "    --- Single left rotation at " << ptr->data << endl;
        }
        else
        {
            ptr = doubleRightLeftRotation(ptr);
            cout << "    --- Double right-left rotation at " << ptr->data << endl;
        }
    }

	ptr->height = (max(height(ptr->left), height(ptr->right)) + 1);

    // Recompute the node's height.
    //ptr->height = ...

    if (checkBalance(ptr) < 0)
    {
        cout << endl << "***** Tree unbalanced!" << endl;
    }

    return ptr;
}

/*
 * Reference: http://www.geeksforgeeks.org/avl-tree-set-1-insertion/
 */
BinaryNode *AvlTree::singleRightRotation(BinaryNode *k2)
{
	BinaryNode *x = k2->left;
	BinaryNode *T2 = x->right;

	// Perform rotation
	x->right = k2;
	k2->left = T2;

	// Update heights
	k2->height = (max(height(k2->left), height(k2->right)) + 1);
	x->height = (max(height(x->left), height(x->right)) +1 );

    // Return new root
	return x;
}

/*
 * reference: http://www.sanfoundry.com/cpp-program-implement-avl-trees/
 */
BinaryNode *AvlTree::doubleLeftRightRotation(BinaryNode *k3)
{
	BinaryNode * temp;
	temp = k3->left;
	k3->left = singleLeftRotation(temp);
	return singleRightRotation(k3);
}
/*
 * reference: http://www.sanfoundry.com/cpp-program-implement-avl-trees/
 */

BinaryNode *AvlTree::doubleRightLeftRotation(BinaryNode *k1)
{
	BinaryNode * temp;
	temp = k1->right;
	k1->right = singleRightRotation(temp);
	return singleLeftRotation(k1);

}
/*
 * reference: http://www.geeksforgeeks.org/avl-tree-set-1-insertion/
 */
BinaryNode *AvlTree::singleLeftRotation(BinaryNode *k1)
{
	BinaryNode *y = k1->right;
	BinaryNode *T2 = y->left;

	y->left = k1;
	k1->right = T2;

	k1->height = (max(height(k1->left), height(k1->right)) + 1);
	y->height = (max(height(y->left), height(y->right)) + 1);

	return y;

}

int AvlTree::checkBalance(BinaryNode *ptr)
{
    if (ptr == nullptr) return -1;

    int leftHeight  = checkBalance(ptr->left);
    int rightHeight = checkBalance(ptr->right);

    if ((abs(height(ptr->left) - height(ptr->right)) > 1)
        || (height(ptr->left)  != leftHeight)
        || (height(ptr->right) != rightHeight))
    {
        return -2;       // unbalanced
    }

    return height(ptr);  // balanced
}
