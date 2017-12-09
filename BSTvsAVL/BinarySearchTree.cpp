#include <iostream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree() : root(nullptr)
{
}

BinarySearchTree::~BinarySearchTree()
{
    clear();
}

BinaryNode *BinarySearchTree::getRoot() const { return root; }

int BinarySearchTree::height() const { return height(root); }


/*
 * reference: https://stackoverflow.com/questions/2279147/calculate-height-of-a-tree
 */
int BinarySearchTree::height(const BinaryNode *ptr) const
{
	if (!ptr) return -1;

	return 1 + max(height(ptr->left), height(ptr->right));

}

long BinarySearchTree::findMin() const throw(string)
{
    if (isEmpty()) throw(string("Empty tree"));
    return findMin(root)->data;
}

BinaryNode *BinarySearchTree::findMin(BinaryNode *ptr) const
{
	if (ptr == nullptr) return nullptr;
	if (ptr->left == nullptr) return ptr;

	return findMin(ptr->left);
}

long BinarySearchTree::findMax() const throw(string)
{
    if (isEmpty()) throw(string("Empty tree"));
    return findMax(root)->data;
}

BinaryNode *BinarySearchTree::findMax(BinaryNode *ptr) const
{
    if (ptr != nullptr)
    {
    		while(ptr->right != nullptr) ptr = ptr->right;
    }

    return ptr;
}

void BinarySearchTree::clear()
{
    clear(root);
}

/*
 * reference : http://www.geeksforgeeks.org/write-a-c-program-to-delete-a-tree/
 */
void BinarySearchTree::clear(BinaryNode* &ptr)
{
    if (ptr == nullptr ) return ;

    clear(ptr->left);
    clear(ptr->right);

    ptr = nullptr;

}

bool BinarySearchTree::isEmpty() const
{
    return root == nullptr;
}

bool BinarySearchTree::contains(const long data) const
{
    return contains(data, root);
}

/*
 * reference: Prof Ron Mak slides
 */
bool BinarySearchTree::contains(const long data, BinaryNode *ptr) const
{
	while(ptr != nullptr)
	{
		if (data < ptr->data)
		{
			ptr = ptr->left;
		}
		else if (data > ptr->data)
		{
			ptr = ptr->right;
		}
		else if (data == ptr->data)
		{
			return true;
		}
	}

	return false;
}

void BinarySearchTree::insert(const long data)
{
    insert(data, root);
}

/*
 * reference: Prof Ron Mak slides
 */
void BinarySearchTree::insert(const long data, BinaryNode* &ptr)
{

    if (ptr == nullptr)
    {
    		ptr = new BinaryNode(data);
    }
    else if (data < ptr->data)
    {
    		insert(data, ptr->left);
    }
    else if (data > ptr->data)
    {
    		insert(data, ptr->right);
    }
}

void BinarySearchTree::remove(const long data)
{
    remove(data, root);
}

/*
 * reference: Prof Ron Mak slides
 */
void BinarySearchTree::remove(const long data, BinaryNode* &ptr)
{
	if (ptr == nullptr) return ;

	if (data < ptr->data)
	{
		remove (data, ptr->left);
	}
	else if ( data > ptr->data)
	{
		remove (data, ptr->right);
	}
	else if (ptr->left != nullptr && ptr->right != nullptr)
	{
		ptr->data = findMin(ptr->right)->data;
		remove(ptr->data, ptr->right);
	}
	else
	{
		BinaryNode * oldNode = ptr;
		ptr = (ptr->left != nullptr) ? ptr->left : ptr->right;

		delete oldNode;
	}
}
