#include <iostream>
#include <vector>
#include <string>
#include "WordVector.h"

/***** Complete this file. *****/

using namespace std;

WordVector::WordVector()
{
    /***** Complete this member function. *****/
}

WordVector::~WordVector()
{
    /***** Complete this member function. *****/
}

Word *WordVector::insert(const string text)
{
    vector<Word>::iterator it = data.begin();

    if (data.size() == 0)
    {
    		data.push_back(Word(text));
    }
    else
    {
    		while ((it != data.end()) && (text > it->get_text())) it++;

    		if ( it->get_text() == text)
    		{
    			it->increase_count();
    		}
    		else if (it->get_text() > text)
    		{
    			data.insert(it, Word(text));
    		}
    		else if (it->get_text() < text)
    		{
    			//data.push_back(Word(text));
    			data.insert(it, Word(text));
    		}
    }
/*
    vector<Word>::iterator itt;
    for (itt = data.begin(); itt != data.end() ; itt++)
    {
    		cout << itt->get_text() << " " << itt->get_count() << endl;
    }
*/
    return &(*it);
}

Word *WordVector::search(const string text)
{
	vector<Word>::iterator it = data.begin();

	while (it != data.end())
	{
		if ( it->get_text() == text)
		{
			return &(*it);
		}
		it++;
	}

	return nullptr;
}
