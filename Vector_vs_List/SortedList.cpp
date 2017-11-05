#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();

}

SortedList::~SortedList()
{
    Node::reset();
}

int SortedList::size() const { return data.size(); }

bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedList::prepend(const long value)
{
	data.push_front(value);

}

void SortedList::append(const long value)
{
	data.push_back(value);

}

void SortedList::remove(const int index)
{
	list<Node>::iterator it = data.begin();
	advance(it,index);
	data.erase(it);

}

void SortedList::insert(const long value)
{

	if (data.size() == 0)
	{
		data.push_front(value);
	}
	else
	{
		list<Node>::iterator it;
		for (it = data.begin() ; it != data.end() ; it++)
		{
			if ((*it).get_value() > value)
			{
				data.insert(it,value);
				break;
			}
		}
		if (it == data.end())
		{
			data.insert(it,value);
		}

	}

}

Node SortedList::at(const int index)
{
	list<Node>::iterator it = data.begin();
	advance(it,index);

	return *it;
}

/*
list<Node>::iterator SortedList::position(const int index)
{
	list<Node>::iterator it = data.begin();
	advance(it,index);

	return it;
}
*/
