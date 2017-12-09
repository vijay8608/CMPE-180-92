#include <iostream>
#include "BinaryTreeChecker.h"

using namespace std;

BinaryTreeChecker::BinaryTreeChecker(BinarySearchTree& tree)
    : tree(tree)
{
    cache.clear();
}

BinaryTreeChecker::~BinaryTreeChecker()
{
}

void BinaryTreeChecker::clear()
{
    cache.clear();
}

void BinaryTreeChecker::add(const int data)
{
    cache.insert(data);
}

void BinaryTreeChecker::remove(const int data)
{
    cache.erase(data);
}

TreeStatus BinaryTreeChecker::check(bool do_dump)
{
    data.clear();
    walk(tree.getRoot());

    return compare(do_dump);
}

void BinaryTreeChecker::walk(BinaryNode *node)
{
    if (node == nullptr) return;

    walk(node->left);
    data.insert(node->data);
    walk(node->right);
}

TreeStatus BinaryTreeChecker::compare(bool do_dump)
{
    typename set<int>::iterator itCache;
    typename set<int>::iterator itData;

    itCache = cache.begin();
    itData  = data.begin();

    if (do_dump) cout << endl;

    while (itCache != cache.end())
    {
        if (itData == data.end()) return TreeStatus::INSUFFICIENT_DATA;
        if (do_dump) cout << *itData << ":" << *itCache << " ";
        if (*itCache != *itData) return TreeStatus::DATA_MISMATCH;

        itCache++;
        itData++;
    }

    if (do_dump) cout << endl;
    if (itData != data.end()) return TreeStatus::REMAINING_DATA;

    return TreeStatus::NO_ERROR;
}

ostream& operator <<(ostream& out, const TreeStatus& status)
{
    switch (status)
    {
        case TreeStatus::NO_ERROR:
        {
            out << ">>>>> The tree is now empty.";
            return out;
        }
        case TreeStatus::DATA_MISMATCH:
        {
            out << ">>>>> Data mismatch.";
            return out;
        }
        case TreeStatus::INSUFFICIENT_DATA:
        {
            out << ">>>>> Data missing from tree.";
            return out;
        }
        case TreeStatus::REMAINING_DATA:
        {
            out << ">>>>> Data remaining in tree.";
            return out;
        }
    }
}
