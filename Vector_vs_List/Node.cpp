#include <iostream>
#include "Node.h"

using namespace std;

long Node::copy_count = 0;
long Node::destructor_count = 0;
long Node::constructor_count = 0;

Node::Node(long int the_value)
{
	this->value = the_value;
	constructor_count++;
}

Node::Node(const Node & other)
{
	this->value = other.value;
	this->copy_count++;
}

Node::~Node()
{
	this->destructor_count++;
}

bool Node::operator ==(const Node & other) const
{
	if (this->value == other.value)
		return true;
	else
		return false;
}

bool Node::operator >(const Node & other) const
{
	if ( this->value > other.value)
		return true;
	else
		return false;
}

