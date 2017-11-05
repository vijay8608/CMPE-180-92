#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Book.h"

using namespace std;

Book::Book()
{

}

Book::Book(string isbn, string last, string first, string title)
{
	this->isbn = isbn;
	this->last = last;
	this->first = first;
	this->title = title;
	//this->category = category;
}

Book::~Book()
{

}

void Book::remove_entry(string isbn)
{

}

/*
 * operator >> overlaoding
 */
istream& operator >> ( istream& in, Book& book)
{
	//string s;
	//getline(in, s ,' ');

	getline(in, book.isbn, ',');
	getline(in, book.last, ',');
	getline(in, book.first, ',');
	getline(in, book.title);
	//getline(in, book.category, '\n');


	/*
	cout << book.isbn << endl;
	cout << book.last << endl;
	cout << book.first << endl;
	cout << book.title << endl;
	*/
	return in;
}


/*
 * operator << overloading
 */
ostream& operator << ( ostream& out , Book& book)
{
	out << "Book{ISBN=" << book.get_isbn() << ", last=" << book.get_last() << ", first=" << book.get_first() << ", title=" << book.get_title() << "}";
	return out;
}


