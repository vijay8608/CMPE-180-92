#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

#include "BookList.h"
#include "Book.h"
#include "BookNode.h"

using namespace std;

int BookList::count = 1;


BookList::BookList(): name(""), head(nullptr), tail(nullptr)
{

}

BookList::BookList(const string name): name(name), head(nullptr), tail(nullptr)
{
	//cout << name << endl;
    create();
    count = 0;
}

/*
 * print list of book list elements
 */

void BookList::print()
{
	cout << endl;
	BookNode * temp;
	int cnt = 0;
	temp = head;

	cout << "Book List: " << this->name <<endl<<endl;

	Book b;
	b = temp->get_book();
	cout << "  "<< b << endl;
	cnt++;

	while (temp != this->tail)
	{
		temp = temp->get_next();
		b = temp->get_book();

		cout << "  " << b << endl;
		cnt++;
	}

	cout << "  "<< "  "<<"(" << cnt << " books"<<")"<<endl;


}

/*
 * print merged list
 */

void BookList::merge_print()
{
	//cout << "in merge print"<< endl;

	BookNode * temp;
	int cnt = 0;
	temp = head;
	Book b;
	b = temp->get_book();
	cout << "  "<< b << endl;
	cnt++;
	while (temp->get_next() != nullptr )
	{
		temp = temp->get_next();
		b = temp->get_book();

		cout << "  " << b << endl;
		cnt++;
	}

	cout << "  "<< "  "<<"(" << cnt << " books"<<")"<< endl<<endl;


}

/*
 * create nodes in the book list
 */


void BookList::create()
{
	//cout << "there" << endl;
	ifstream inp;
	inp.open(BookList::name+".txt");

	if (inp.fail())
	{
		cout << "Failed to open : " << BookList::name << endl;
	}

	Book book;
	inp >> book;

	while (!inp.fail())
	{
		if (head == nullptr)
		{
			//cout << "new node" << endl;
			createnewnode(book);

		}
		else
		{
			//cout << "link new node" << endl;
			linknewnode(book);
			//cout << "here" << endl;

		}
		inp >> book;
		//cout << this->name << endl;


	}
}

/*
 * create new node in the list
 */

void BookList::createnewnode(Book& book)
{
	head = new BookNode(book);
	//cout << head->get_book().get_isbn() << endl;

	tail = head;
	//head->next = nullptr;
	//count = 1;

	//cout << "first node created" << endl;
	//cout << "first node isbn is " << head->get_book().get_isbn() << endl;
	//cout << "create new node" << endl;


}

/*
 *create add new nodes to the already existing node and form a list
 */

void BookList::linknewnode(Book& book)
{
	//cout << "link nodes" << endl;
	BookNode * temp = new BookNode(book);

	//cout << "temp has" << temp->get_book().get_isbn() << endl;

	BookNode * location , *previous_location;

	int check = 0;
	int duplicate = 0;

	BookNode * t;
	int loop = count;

	//duplicate = temp->check_duplicate_isbn(t, temp);

	for ( t = head ; loop > 0; t = t->get_next())
	{
		//cout << t->get_book().get_isbn() << endl;
		//cout << temp->get_book().get_isbn() << endl;
		if ( t->get_book().get_isbn() == temp->get_book().get_isbn())
		{
			duplicate = 1;
			break;
		}

		loop--;
	}

	//cout << duplicate << endl;
	if (duplicate == 0)
	{

		for ( location = head ; location && location->get_book().get_isbn() < temp->get_book().get_isbn() ; location = location->get_next() )
		{
			check ++;
			//cout << "location points to " << location->get_book().get_isbn() << endl;
		}

		check --;

		for (previous_location = head ; check > 0 ; previous_location = previous_location->get_next())
		{
			check --;
		}

		if (location == nullptr)
		{
			tail->set_next(temp);
			tail = temp;
			tail->set_next(nullptr);
			//cout << "adding at last " << tail->get_book().get_isbn() << endl;
			count++;
		}
		else if (location == head)
		{
			temp->set_next(location);
			head = temp;
			//cout << "adding at the start " << head->get_book().get_isbn() << endl;
			count++;
		}
		else
		{
			temp->set_next(location);
			previous_location->set_next(temp);
			//cout << "adding in between" << previous_location->get_next()->get_book().get_isbn()<< endl;
			count++;
		}
	}
	else
	{
		delete temp;

	}
	//cout << head->get_book().get_isbn() << endl;

}

/*
void BookList::sortlist()
{
	BookNode * temp, *temp2;
	temp = head;

	int cnt = 0;
	while (temp)
	{
		temp = temp->get_next();
		cnt++;
	}

	temp = head;
	temp2 = temp->get_next();
	string str;
	Book b, t;

	for (int i = 0 ; i < cnt ; i++)
	{
		b = temp->get_book();
		while (temp2->get_next())
		{
			if ( b.get_isbn() > temp2->get_book().get_isbn())
			{
				t = b;
				b = temp2->get_book();
				temp2->set_book() = t;
				temp2 = temp->get_next();
			}

			temp2 = temp2->get_next();


		}


	}
}
*/

/*
 * print list according to authors name where last anme starts between A and M
 */

void BookList::authors_print_am()
{

	BookNode * temp;
	int cnt = 0;
	temp = head;
	string str;

	Book b;
	b = temp->get_book();
	str = b.get_last();

	cout << "Book List: AUTHORS A-M" <<endl<<endl;

	if ( str[0] >= 'A' && str[0] <= 'M')
	{
		cout << "  "<< b << endl;
		cnt++;
	}
	while (temp->get_next() != nullptr )
	{
		temp = temp->get_next();
		b = temp->get_book();
		str = b.get_last();


		if ( str[0] >= 'A' && str[0] <= 'M')
		{
			cout << "  " << b << endl;
			cnt++;
		}


	}

	cout << "  "<< "  "<<"(" << cnt << " books"<<")"<< endl<<endl;

}


/*
 * print list with author names between N and Z
 */

void BookList::authors_print_nz()
{

	BookNode * temp;
	int cnt = 0;
	temp = head;
	string str;

	Book b;
	b = temp->get_book();
	str = b.get_last();

	cout << "Book List: AUTHORS N_Z" <<endl<<endl;

	if ( str[0] >= 'N' && str[0] <= 'Z')
	{
		cout << "  "<< b << endl;
		cnt++;
	}
	while (temp->get_next() != nullptr )
	{
		temp = temp->get_next();
		b = temp->get_book();
		str = b.get_last();


		if ( str[0] >= 'N' && str[0] <= 'Z')
		{
			cout << "  " << b << endl;
			cnt++;
		}


	}

	cout << "  "<< "  "<<"(" << cnt << " books"<<")"<< endl<<endl;

}

