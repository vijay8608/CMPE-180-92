#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}

int SortedVector::size() const { return data.size(); }

bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedVector::prepend(const long value)
{
    data.insert(data.begin(),value);
}

void SortedVector::append(const long value)
{
    data.push_back(value);

}

void SortedVector::remove(const int index)
{
	if (index != 0)
		data.erase(data.begin() + (index - 1));
	else
		data.erase(data.begin());

    /***** Complete this function. *****/
}

void SortedVector::insert(const long value)
{
	if (data.size() == 0)
	{
		data.push_back(value);
	}
	else
	{
		int temp = data.size();
		for (int i = 0 ; i < temp ; i++)
		{
			if (data[i].get_value() > value)
			{
				vector<Node>::iterator it = data.begin();
				advance(it,i);
				it = data.insert(it , value);
				break;
			}
		}
		if (temp == data.size())
		{
			data.push_back(value);
		}
	}
}

Node SortedVector::at(const int index) const
{
	return data[index];
}
