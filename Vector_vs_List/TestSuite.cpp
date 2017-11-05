#include <string>
#include "SortedVector.h"
#include "SortedList.h"
#include "Node.h"
#include "TestSuite.h"

using namespace std;

// How many times to do gets.
const int GETS_COUNT = 10000;

void vector_prepends(SortedVector& sv, const int size)
{

	for (int i = size-1 ; i >= 0 ; i--)
	{
		sv.prepend(i);
	}

	//cout << "In vector prepend" << endl;

}

void list_prepends(SortedList& sl, const int size)
{
	for (int i = size-1 ; i >= 0 ; i--)
		{
			sl.prepend(i);
		}

	//cout << "In list prepend" << endl;

}

void vector_appends(SortedVector& sv, const int size)
{

	for (int i = 0 ; i < size ; i++)
	{
		sv.append(i);
	}

	//cout << "In vector append" << endl;
}

void list_appends(SortedList& sl, const int size)
{
	for (int i = 0 ; i < size ; i++)
	{
		sl.append(i);
	}

	//cout << "In list append" << endl;
    /***** Complete this function. *****/
}

void vector_gets(SortedVector& sv, const int size) throw (string)
{
	//cout << "In vector get" << endl;

    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
        int index = rand()%size;
        long value = (sv.at(index)).get_value();

        if (index != value) throw string("Vector data mismatch!");
    }

}

void list_gets(SortedList& sl, const int size) throw (string)
{
	//cout << "In list get" << endl;

    // First fill the list data.
    list_appends(sl, size);
    Node::reset();

    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
        int index = rand()%size;
        long value = sl.at(index).get_value();

        // Make sure we got the correct node.
        if (index != value) throw string("List data mismatch!");
    }

}

void vector_removes(SortedVector& sv, const int size)
{
	//cout << "In vector remove" << endl;

    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    // Loop to remove a node at a random position
    // one at a time until the nodes are all gone.
    while (sv.size() > 0)
    {
        int index = rand()%(sv.size());
        sv.remove(index);
    }

}

void list_removes(SortedList& sl, const int size)
{
	//cout << "In list remove" << endl;

    // First fill the list data.
    list_appends(sl, size);
    Node::reset();

    while (sl.size() > 0)
    {
        int index = rand()%(sl.size());
        sl.remove(index);
    }
}

void vector_inserts(SortedVector& sv, const int size)
{
	long array[size];
	for (int i = 0 ; i < size ; i++)
	{
		long n;
		bool check;
		do
		{
			n = rand() % size;
			check = true;

			for (int j = 0 ; j < i ; j++)
			{
				if ( n == array[j])
				{
					check = false;
					break;
				}
			}

		}while (!check);

		array[i] = n;
	}

	for (int i = 0 ; i < size ; i++)
	{
		sv.insert(array[i]);
	}

}

void list_inserts(SortedList& sl, const int size)
{
	long array[size];
		for (int i = 0 ; i < size ; i++)
		{
			long n;
			bool check;
			do
			{
				n = rand() % size;
				check = true;

				for (int j = 0 ; j < i ; j++)
				{
					if ( n == array[j])
					{
						check = false;
						break;
					}
				}

			}while (!check);

			array[i] = n;
		}

		for (int i = 0 ; i < size ; i++)
		{
			sl.insert(array[i]);
		}
	//cout << "In list insert" << endl;
        /***** Complete this function. *****/
}
