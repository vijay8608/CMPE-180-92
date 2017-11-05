#ifndef BOOKNODE_H_
#define BOOKNODE_H_

#include "Book.h"

/**
 * A book node in a linked list.
 */
class BookNode
{
public:
    /**
     * Constructor.
     * @param book this node's book.
     */
    BookNode(Book book);

    //int check_duplicate_isbn(BookNode *t, BookNode * temp);

    Book get_book() { return book;}

    //void set_book(Book * temp) { book = temp ;}

    BookNode * get_next() {return next;}

    void set_next(BookNode * temp) { next = temp;}

//    friend ostream& operator << ( ostream& out , BookNode& book);



private:
    Book book;       // this node's book
    BookNode *next;  // link to the next node in the list
};

#endif /* BOOKNODE_H_ */
