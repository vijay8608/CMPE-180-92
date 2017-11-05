#include<iostream>
#include<vector>
#include<string>
#include<fstream>

#include"BookList.h"
#include"BookNode.h"

using namespace std;


/*
 * name of file with categories
 */
const string CATEGORIES_FILE_NAME = "categories.txt";


/*
 * function to merge lists
 * @list vector of type BookList list that needs to merge
 */
void merge_list(vector<BookList> list)
{
/*
	for (int i = 0 ; i < list.size() ; i++)
	{
		if ((i+1) < list.size())
		{
			list[i].get_tail()->set_next(list[i+1].get_head());
			list[i].set_tail(nullptr);
		}
	}
*/

	//merge list[0] and list[1]

	BookNode *p, *q, *sorting;
	BookNode * new_head = nullptr;


	p = list[0].get_head();
	q = list[1].get_head();

	if ( p && q)
	{
		if (p->get_book().get_isbn() < q->get_book().get_isbn())
		{
			sorting = p;
			p = sorting->get_next();
		}
		else
		{
			sorting = q;
			q = sorting->get_next();
		}
	}


	list[1].set_head(sorting);

	while (p && q)
	{

		if (p->get_book().get_isbn() < q->get_book().get_isbn())
		{
			sorting->set_next(p);
			sorting = p;
			p = sorting->get_next();
		}
		else
		{
			sorting->set_next(q);
			sorting = q;
			q = sorting->get_next();
		}


	}

	if (p == nullptr)
		sorting->set_next(q);
	if (q == nullptr)
		sorting->set_next(p);

	//merge list list[2] and list[3]


	BookNode *p1, *q1, *sorting1;
		BookNode * new_head1 = nullptr;


		p1 = list[2].get_head();
		q1 = list[3].get_head();

		if ( p1 && q1)
		{
			if (p1->get_book().get_isbn() < q1->get_book().get_isbn())
			{
				sorting1 = p1;
				p1 = sorting1->get_next();
			}
			else
			{
				sorting1 = q1;
				q1 = sorting1->get_next();
			}
		}


		list[3].set_head(sorting1);

		while (p1 && q1)
		{

			if (p1->get_book().get_isbn() < q1->get_book().get_isbn())
			{
				sorting1->set_next(p1);
				sorting1 = p1;
				p1 = sorting1->get_next();
			}
			else
			{
				sorting1->set_next(q1);
				sorting1 = q1;
				q1 = sorting1->get_next();
			}


		}

		if (p1 == nullptr)
			sorting1->set_next(q1);
		if (q1 == nullptr)
			sorting1->set_next(p1);


		//merge list list[1] and list[3] to get final one merged list

		BookNode *p2, *q2, *sorting2;
			BookNode * new_head2 = nullptr;


			p2 = list[1].get_head();
			q2 = list[3].get_head();

			if ( p2 && q2)
			{
				if (p2->get_book().get_isbn() < q2->get_book().get_isbn())
				{
					sorting2 = p2;
					p2 = sorting2->get_next();
				}
				else
				{
					sorting2 = q2;
					q2 = sorting2->get_next();
				}
			}


			list[3].set_head(sorting2);

			while (p2 && q2)
			{

				if (p2->get_book().get_isbn() < q2->get_book().get_isbn())
				{
					sorting2->set_next(p2);
					sorting2 = p2;
					p2 = sorting2->get_next();
				}
				else
				{
					sorting2->set_next(q2);
					sorting2 = q2;
					q2 = sorting2->get_next();
				}


			}

			if (p2 == nullptr)
				sorting2->set_next(q2);
			if (q2 == nullptr)
				sorting1->set_next(p2);




	cout << endl<<"Book list: MERGED" << endl<<endl;


	// print merged list
	list[3].merge_print();


}

int main()
{
	// input stream and read categories.txt file

	ifstream input_category;
	input_category.open(CATEGORIES_FILE_NAME);

	if (input_category.fail())
	{
		cout << "Failed to open : " << CATEGORIES_FILE_NAME << endl;
		return -1;
	}

	vector<BookList> list;

	string category;

	input_category >> category;

	// create vector of type BookList

	while (!input_category.fail())
	{
		list.push_back(category);

		input_category >> category;
	}


	//print book elements

	for (int i = 0 ; i < list.size() ; i++)
	{
		list[i].print();
	}

	merge_list(list);

	//print according to authors last name A to M


	list[3].authors_print_am();

	// print according to authors last name N to Z

	list[3].authors_print_nz();


    return 0;
}
