#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Book.h"

using namespace std;

Book::Book() : isbn(" "), last (" "), first(" "), title(" "), category( Category::NONE)
{}

Book::Book(string isbn, string last, string first, string title, Category category) : isbn(isbn), last(last), first(first), title(title), category(category)
{}

Book::~Book()
{}

void Book::remove_entry(string isbn)
{}



istream& operator >> ( istream& in, Book& book)
{
	string s;
	string cat;
	getline(in, s ,' ');
	getline(in, book.isbn, ',');
	getline(in, book.last, ',');
	getline(in, book.first, ',');
	getline(in, book.title, ',');
	getline(in, cat, '\n');

	if (cat == "fiction")
	{
		book.category = Book::Category::FICTION;
	}
	else if (cat == "history")
	{
		book.category = Book::Category::HISTORY;
	}
	else if (cat == "technical")
	{
		book.category = Book::Category::TECHNICAL;
	}
	else
	{
		book.category = Book::Category::NONE;
	}

	return in;
}

ostream& operator << ( ostream& out , const Book::Category& category)
{
	switch(category)
	{
	case Book::Category::FICTION: out << "fiction" ; break ;
	case Book::Category::HISTORY: out << "history" ; break ;
	case Book::Category::NONE: out << "none" ; break ;
	case Book::Category::TECHNICAL: out << "technical" ; break ;
	}

	return out;
}

ostream& operator << (ostream& outs, const Book& book)
{
	outs << "Book{ISBN=" << book.get_isbn() << ", last=" << book.get_last() << ", first=" << book.get_first() << ", title=" << book.get_title() << ", category=" << book.get_category() << "}";
	return outs;
}



