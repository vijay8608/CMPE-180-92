#include <iostream>
#include <map>
#include "WordMap.h"

/***** Complete this file. *****/

using namespace std;

WordMap::WordMap()
{

}

WordMap::~WordMap()
{

}

Word *WordMap::insert(const string text)
{

	map<string, Word>::iterator it = data.find(text);

	if (it == data.end())
	{
		data.insert(std::pair<string, Word>(text, Word(text)));
	}
	else
	{
		(it->second).increase_count();
	}

	return &it->second;

}

Word *WordMap::search(const string text)
{
	std::map<string, Word>::iterator it = data.find(text);

	if (it == data.end())
		{
			return nullptr;
		}
	return &it->second;

}
