#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Book.h"

/***** Complete this file. *****/

using namespace std;

/**
 * Find the book in the catalog with the given ISBN.
 * Use a binary search.
 * @param isbn the ISBN.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found, else return -1.
 */
int find(const string isbn, const vector<Book>& catalog)
{
	int mid = (catalog.size()-1)/2;
	int high = catalog.size() - 1;
	int low = 0;

	vector<Book> temp = catalog;

	while (low <= high)
	{

		if (isbn == temp[mid].get_isbn())
		{
			return mid;
		}

		if (isbn > temp[mid].get_isbn())
		{
			low = mid;
			break;
		}

		if (isbn < temp[mid].get_isbn())
		{
			high = mid;
			break;
		}

		mid = (high+low)/2;
	}
	return -1;
}

/*
 * Print the ouput of the catalog operation
 * @i location in the vector type book
 * @catalog the vector where the output is stored
 */
/*
void print_output(int i, vector<Book>& catalog)
{
	cout << " Book{ISBN=" << catalog[i].get_isbn() << ", last=" << catalog[i].get_last() << ", first=" << catalog[i].get_first() << ", title=" << catalog[i].get_title() << ", category="<<  << "}" << endl;
}
*/
/*
 * insert entry to the vector
 * @input read values from file
 * @catalog vector of book data type
 * @command insert command
 */
void insert_entry(ifstream& input, vector<Book>& catalog, char command)
{
	Book b;
	input >> b;

	if (catalog.size() == 0)
	{
	    	catalog.push_back(b);
	    	cout << endl;
		cout << command << " Inserted at index 0:" ;
		cout << " Book{ISBN=" << catalog[0].get_isbn() << ", last=" << catalog[0].get_last() << ", first=" << catalog[0].get_first() << ", title=" << catalog[0].get_title() << ", category="<< catalog[0].get_category() << "}" << endl;
	 }
	 else
	 {
		 int loop = catalog.size();
		 int check = 0;
		 for (int i = 0 ; i < loop ; i++)
		 {
			 if ( catalog[i].get_isbn() == b.get_isbn() )
			 {
				 check = 1;
				 cout << command << " Inserted at index " << i << ":" ;
				 //cout << " Book{ISBN=" << catalog[i].get_isbn() << ", last=" << catalog[i].get_last() << ", first=" << catalog[i].get_first() << ", title=" << catalog[i].get_title() << ", category="<< catalog[i].get_category() << "}" << endl;
				 //print_output(i, catalog);
				 cout << catalog[i];
				 cout <<"*** Duplicate ISDN ***" <<endl;
				 break;
			 }

			 if (catalog[i].get_isbn() > b.get_isbn())
			 {	check = 1;
			 	 catalog.insert(catalog.begin() + i, b);
			 	 cout << command << " Inserted at index " << i << ":" ;
	    			//cout << " Book{ISBN=" << catalog[i].get_isbn() << ", last=" << catalog[i].get_last() << ", first=" << catalog[i].get_first() << ", title=" << catalog[i].get_title() << ", category="<< catalog[i].get_category() << "}" << endl;
			 	 //print_output(i, catalog);
			 	cout << catalog[i];
	    			break;
			 }
		}
		 if (check == 0 )
		 {
			 catalog.push_back(b);
			 cout << command << " Inserted at index " << loop << ":" ;
			 //cout << " Book{ISBN=" << catalog[loop].get_isbn() << ", last=" << catalog[loop].get_last() << ", first=" << catalog[loop].get_first() << ", title=" << catalog[loop].get_title() << ", category="<< catalog[loop].get_category() << "}" << endl;
			 //print_output(loop, catalog);
			 cout << catalog[loop];
		}
	 }

	cout << endl;
}

/*
 * search entry based on input parameter
 * @input search_field from input file
 * @catalog vector of book data type
 * @command perform search entry
 */
void search_entry(ifstream& input, vector<Book>& catalog, char command)
{
	string temp;
	getline(input, temp);
	string search_type = "",search_value = "";

	if (temp == "") {}
	else
	{
		size_t location = temp.find("=");
		search_type = temp.substr(1,location -1);
		search_value = temp.substr(location +1);
	}

	if (search_type == "" )
	{
		cout << "? All books in the catalog: " << endl;
		for (int i = 0 ; i < catalog.size() ; i++)
		{
			//cout << "Book{ISBN=" << catalog[i].get_isbn() << ", last=" << catalog[i].get_last() << ", first=" << catalog[i].get_first() << ", title=" << catalog[i].get_title() << ", category="<< catalog[i].get_category() << "}" << endl;
			//print_output(i, catalog);
			cout << catalog[i];
		}

	}
	else
	{
		if (search_type == "author")
		{
			cout << command << " Books by author " << search_value << ":" << endl;
			for (int i = 0 ; i < catalog.size() ; i++)
			{
				if ( search_value == catalog[i].get_last())
	    			{
					//cout << "Book{ISBN=" << catalog[i].get_isbn() << ", last=" << catalog[i].get_last() << ", first=" << catalog[i].get_first() << ", title=" << catalog[i].get_title() << ", category="<< catalog[i].get_category() << "}" << endl;
	    				//print_output(i, catalog);
					cout << catalog[i];
	    			}
	    		}
		}

		if (search_type == "category")
		{
			cout << command << " Books in category " << search_value << ":" << endl;

			Book::Category category;
			Book::Category category1;
/*
			if (search_value == "fiction")
				category = Book::Category::FICTION;
			else if (search_value == "history")
				category = Book::Category::HISTORY;
			else if (search_value == "technical")
				category = Book::Category::TECHNICAL;
			else if (search_value == "none")
				category = Book::Category::NONE;


			for (int i = 0 ; i < catalog.size() ; i++)
			{
	//			category1 = catalog[i].get_category();
		//		if ( category == category1)

					//cout << "Book{ISBN=" << catalog[i].get_isbn() << ", last=" << catalog[i].get_last() << ", first=" << catalog[i].get_first() << ", title=" << catalog[i].get_title() << ", category="<< catalog[i].get_category() << "}" << endl;
					//print_output(i, catalog);
					//cout << catalog[i];

			}
*/
		}

		if (search_type == "isbn")
		{
			int loc = find(search_value, catalog);
			if (loc == -1)
			{
				cout << "? Book with ISBN " << search_value << ":" << endl;
	    		}
			else
			{
				cout << command << " Book with ISBN " << search_value << ":" << endl;
				//cout << "Book{ISBN=" << catalog[loc].get_isbn() << ", last=" << catalog[loc].get_last() << ", first=" << catalog[loc].get_first() << ", title=" << catalog[loc].get_title() << ", category="<< catalog[loc].get_category() << "}" << endl;
	    			//print_output(loc, catalog);
				cout << catalog[loc];
			}
		}
		//cout << endl;
	}
}

/*
 * remove entry from catalog
 * @input read input from file
 * @catalog vector of form catalog of type catalog
 * @command to remove entry
 */
void remove_entry(ifstream& input, vector<Book>& catalog, char command)
{
	string temp, temp1;
	getline(input, temp, ' ');
	getline(input , temp1 );
	//string string_without_space = temp.substr(1);

	cout << command <<" Removed ";
	//cout << string_without_space << endl;
	int check = 0;

	for (int i = 0 ; i < catalog.size() ; i++)
	{
		if (catalog[i].get_isbn() == temp1)
		{
			//cout << "Book{ISBN=" << temp1 << ", last=" << catalog[i].get_last() << ", first=" << catalog[i].get_first() << ", title=" << catalog[i].get_title() << ", category="<< catalog[i].get_category() << "}" << endl;
			//cout << "Book{ISBN=" << catalog[i].get_isbn() << ", last=" << catalog[i].get_last() << ", first=" << catalog[i].get_first() << ", title=" << catalog[i].get_title() << ", category="<< catalog[i].get_category() << "}" << endl;
			cout << catalog[i];
			catalog.erase(catalog.begin() + i);
			check = 1;
			break;
		}
	}
	if ( check == 0)
	{
	    	cout << "Book{ISBN=" << temp1 << ", last=, first=, title=, category=none}" << endl;
	    cout << "*** Book not found ***" << endl;
	}
	cout << endl;
}


const string INPUT_FILE_NAME = "commandsin.txt";

/**
 * The main. Open the command input file and loop to process commands.
 */
int main()
{
    // Open the input file.
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    vector<Book> catalog;  // book catalog
    char command;
    input >> command;

    string isbn, last, first, title, category, search;

    /*
     * Loop to read commands until the end of file.
     */
    while (!input.fail())
    {

    		if (command == '+')
    		{
    			insert_entry(input, catalog, command);
    		}
    		else if (command == '?')
    		{
    			search_entry(input,catalog,command);
    			cout << endl;
    		}
    		else if (command == '-')
    		{
    			remove_entry(input, catalog,command);
    		}
    		else
    		{
    			string temp;
    			getline(input, temp);

    			cout << command <<" *** Invalid command ***" << endl << endl;
    			//cout << temp << endl;
    		}

    		input >> command;
    }

    return 0;
}
