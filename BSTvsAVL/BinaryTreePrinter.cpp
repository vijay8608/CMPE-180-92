#include <iostream>
#include "BinaryTreePrinter.h"

using namespace std;

const int BinaryTreePrinter::POWERS_OF_2[] = {1, 2, 4, 8, 16, 32, 64, 128};

BinaryTreePrinter::BinaryTreePrinter(BinarySearchTree& tree)
    : tree(tree)
{
}

BinaryTreePrinter::~BinaryTreePrinter()
{
}

void BinaryTreePrinter::print()
{
    // Queue of nodes at this level.
    BinaryNode *thisLevelNodes[32];

    int height = tree.height();
    int offset = POWERS_OF_2[(height+1)]-1;

    thisLevelNodes[0] = tree.getRoot();

    // Loop to print each level of nodes.
    for (int level = 0; level <= height; level++)
    {
        if (level > MAX_LEVELS)
        {
            cout << "*** Too many levels to print. ***\n";
            break;
        }

        // Print node data.
        print_data(level, offset, thisLevelNodes);

        if (level != height)
        {
            // Print outgoing pointers /\ from each parent node->
            print_outgoing_pointers(level, offset, thisLevelNodes);

            offset = POWERS_OF_2[height - level] - 1;

            // Print connecting dashes ----
            if (level < height-1)
            {
                print_connecting_dashes(level, offset, thisLevelNodes);
            }

            // Print incoming pointers / and \ to each child node->
            print_incoming_pointers(level, offset, thisLevelNodes);

            // Prepare the next level of nodes.
            prepare_next_level(level, thisLevelNodes);
        }
    }
}

void BinaryTreePrinter::print_data(int level, int offset,
                                     BinaryNode *levelNodes[])
{
    print_spaces(offset);

    int k = POWERS_OF_2[level];
    for (int i = 0; i < k; i++)
    {
        BinaryNode *ptr = levelNodes[i];

        if (ptr != nullptr)
        {
            cout << setw(3) << ptr->data << " ";
        }
        else
        {
            cout << "    ";
        }

        // Space over to the next node in this level.
        if (i < k-1) print_spaces(2*offset - 2);
    }

    cout << endl;
}

void BinaryTreePrinter::print_outgoing_pointers(int level, int offset,
                                                 BinaryNode *levelNodes[])
{
    print_spaces(offset);

    int k = POWERS_OF_2[level];
    for (int i = 0; i < k; i++)
    {
        BinaryNode *ptr = levelNodes[i];

        // Has left child: print / forward slash
        if ((ptr != nullptr) && (ptr->left != nullptr))
        {
            cout << " /";
        }

        // No left child: print space
        else
        {
            cout << "  ";
        }

        // Has right child: print \ backward slash
        if ((ptr != nullptr) && (ptr->right != nullptr))
        {
            cout << "\\ ";
        }

        // No right child: print space
        else
        {
            cout << "  ";
        }

        // Space over to the next node in this level.
        if (i < k-1) print_spaces(2*offset-2);
    }

    cout << endl;
}

void BinaryTreePrinter::print_connecting_dashes(int level, int offset,
                                                 BinaryNode *levelNodes[])
{
    if (offset > 1) print_spaces(offset);

    int k = POWERS_OF_2[level];
    for (int i = 0; i < k; i++)
    {
        BinaryNode *ptr = levelNodes[i];

        // Has left child: print dashes
        if ((ptr != nullptr) && (ptr->left != nullptr))
        {
            print_spaces(3);
            print_dashes(offset-1);
        }

        // No left child: print spaces
        else
        {
            print_spaces(offset+2);
        }

        // Has right child: print dashes
        if ((ptr != nullptr) && (ptr->right != nullptr))
        {
            print_spaces(2);
            print_dashes(offset-1);
        }

        // No right child: print spaces
        else
        {
            print_spaces(offset+1);
        }

        // Space over to the next node in this level.
        if (i < k-1) print_spaces(2*offset+1);
    }

    cout << endl;
}

void BinaryTreePrinter::print_incoming_pointers(int level, int offset,
                                                 BinaryNode *levelNodes[])
{
    print_spaces(offset);

    int k = POWERS_OF_2[level];
    for (int i = 0; i < k; i++)
    {
        BinaryNode *ptr = levelNodes[i];

        // Left child: print /
        if ((ptr != nullptr) && (ptr->left != nullptr))
        {
            cout <<"  /";
        }

        // No left child: print spaces
        else
        {
            print_spaces(3);
        }

        // Right child: print \ backward slash
        if ((ptr != nullptr) && (ptr->right != nullptr))
        {
            print_spaces(2*offset);
            cout << "\\";
        }

        // No right child: print spaces
        else
        {
            print_spaces(2*offset+1);
        }

        // Space over to the next node in this level.
        if (i < k-1) print_spaces(2*offset);
    }

    cout << endl;
}

void BinaryTreePrinter::prepare_next_level(int level, BinaryNode *levelNodes[])
{
    int size = POWERS_OF_2[level+1];
    BinaryNode *nextLevel[size];

    for (int i = 0; i < POWERS_OF_2[level]; i++)
    {
        BinaryNode *ptr = levelNodes[i];

        // Queue the left child nodes of each non-null parent node->
        nextLevel[2*i] = (ptr != nullptr) && (ptr->left != nullptr)
                       ? ptr->left : nullptr;

        // Queue the right child nodes of each non-null parent node->
        nextLevel[2*i+1] = (ptr != nullptr) && (ptr->right != nullptr)
                         ? ptr->right : nullptr;
    }

    for (int i = 0; i < size; i++) levelNodes[i] = nextLevel[i];
}

void BinaryTreePrinter::print_spaces(int count)
{
    for (int i = 0; i < count; i++) cout << " ";
}

void BinaryTreePrinter::print_dashes(int count)
{
    for (int i = 0; i < count; i++) cout << "-";
}
