#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "BookNode.h"
#include "Book.h"

using namespace std;

BookNode::BookNode(Book book)
{
	this->book = book;
	this->next = nullptr;
}

/*
 ostream& operator << ( ostream& out , BookNode& book)
{
	 while (book.next != nullptr)
	 {
		 cout << "booknode"<<endl;
		 out << book.book << endl;

		 book.set_next(book.next);
	 }

	 return out;
}
*/


