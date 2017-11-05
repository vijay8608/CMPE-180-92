#ifndef BOOKLIST_H_
#define BOOKLIST_H_

#include<string>

#include "BookNode.h"

using namespace std;

class BookList
{
public:
    /**
     * Constructor.
     * @param name the name of this list.
     */
    BookList(const string name);

    BookList();

    /**
     * Print the list.
     */
    void print();
    /*
     * create new node
     * @book create new node with book data
     */
    void createnewnode( Book& book);
    /*
     * link new node to already existin code
     * @book add data book to the new node
     */
    void linknewnode(Book& book);
    /*
     * setter for name
     */
    string get_name() {return name;}
    /*
     * print merged lists
     */
    void merge_print();

    //void sortlist();
    /*
     * setter for head variable
     */
    void set_head (BookNode * temp) {head = temp;}
    /*
     * print book details for authors starting from A..M
     */
    void authors_print_am();
    /*
     * print book details for authors starting from N..Z
     */
    void authors_print_nz();


    /*
     * create nodes
     */
    void create();

    /*
     * count to keep track of number of nodes in the list
     */
    static int count;
    /*
     * getter for head
     */
    BookNode * get_head(){return head;}
    /*
     * getter for tail
     */
    BookNode * get_tail(){return tail;}


    void set_tail(BookNode * node){ tail = node;}



private:
    string name;      // name of this book list
    BookNode *head;   // head of the list of book nodes
    BookNode *tail;   // tail of the list of book nodes

};

#endif /* BOOKLIST_H_ */
