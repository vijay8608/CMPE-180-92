/**
 * Test the binary search tree and AVL tree implementations.
 * The AVL tree is derived from the binary search tree.
 *
 * Create a tree of height 5 and then repeatedly
 * delete the root. The AVL tree should remain balanced
 * after each node insertion and deletion.
 *
 */
#include <iostream>
#include <vector>
#include <time.h>

#include "BinarySearchTree.h"
#include "AvlTree.h"
#include "BinaryTreeChecker.h"
#include "BinaryTreePrinter.h"

using namespace std;

const bool DO_DUMP = false;

enum class TreeType
{
    BST, AVL
};

/**
 * Print the tree type.
 */
ostream& operator <<(ostream& out, const TreeType& type);

/**
 * Run the test with a binary search tree.
 */
void testBST();

/**
 * Run the test with an AVL tree.
 */
void testAVL();

/**
 * Build a binary search tree containing unique random integer data items.
 * @param tree the tree to build.
 * @param checker the binary tree checker to use.
 * @param printer the binary tree printer to use.
 * @param type the type of tree (BST or AVL).
 */
void build_tree(BinarySearchTree& tree,
                BinaryTreeChecker& checker,
                BinaryTreePrinter& printer,
                TreeType type);

/**
 * Dismantle a binary tree.
 * @param tree the tree to test.
 * @param checker the binary tree checker to use.
 * @param printer the binary tree printer to use.
 */
void dismantle_tree(BinarySearchTree& tree,
                    BinaryTreeChecker& checker,
                    BinaryTreePrinter& printer);

/**
 * Main.
 */
int main( )
{
    testBST();
    testAVL();
}

ostream& operator <<(ostream& out, const TreeType& type)
{
    out << (type == TreeType::BST ? "BST" : "AVL");
    return out;
}

void testBST()
{
    cout << endl;
    cout << "**********************" << endl;
    cout << "* BINARY SEARCH TREE *" << endl;
    cout << "**********************" << endl;

    BinarySearchTree  tree;
    BinaryTreeChecker checker(tree);
    BinaryTreePrinter printer(tree);

    build_tree(tree, checker, printer, TreeType::BST);
    dismantle_tree(tree, checker, printer);
}

void testAVL()
{
    cout << endl;
    cout << "************" << endl;
    cout << "* AVL TREE *" << endl;
    cout << "************" << endl;

    AvlTree tree;
    BinaryTreeChecker checker(tree);
    BinaryTreePrinter printer(tree);

    build_tree(tree, checker, printer, TreeType::AVL);
    dismantle_tree(tree, checker, printer);
}

static const long VALUES[] = {
    62,71,29,88,11,41,21,66,57,27,39,40,77,20,51,49,82,37,
    94,63,76,91,70,64,60,90,12,80,23,10,52,35,96,75,28
};

void build_tree(BinarySearchTree& tree,
                BinaryTreeChecker& checker,
                BinaryTreePrinter& printer,
                TreeType type)
{
    for (long n : VALUES)
    {
        cout << endl << "Inserting node " << n << ":" << endl;

        tree.insert(n);  // insert into tree
        checker.add(n);  // store with the tree checker

        cout << endl;
        printer.print();
    }

    cout << endl;
    cout << "*****" << endl;
    cout << "***** COMPLETED " << type << " TREE:" << endl;
    cout << "*****" << endl << endl;
    printer.print();
}

void dismantle_tree(BinarySearchTree& tree,
                    BinaryTreeChecker& checker,
                    BinaryTreePrinter& printer)
{
    TreeStatus status = TreeStatus::NO_ERROR;

    // Delete the root node each time through the loop.
    // Print the tree after each deletion.
    while (!tree.isEmpty())
    {
        BinaryNode *root = tree.getRoot();
        long data = root->data;
        cout << endl << "Deleting root node " << data << ":" << endl;

        tree.remove(data);
        checker.remove(data);

        cout << endl;
        printer.print();

        status = checker.check(DO_DUMP);
        if (status != TreeStatus::NO_ERROR) break;
    }

    // What was the status?
    cout << status << endl;
}
