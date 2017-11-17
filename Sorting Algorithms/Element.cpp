#include <iostream>
#include "Element.h"

using namespace std;

long Element::copy_count;
long Element::destructor_count;

/**
 * Default constructor.
 */
Element::Element() : value(0) {}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) : value(val) {}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Element::Element(const Element& other)
{
    this->value = other.value;
    this->copy_count++;
}

/**
 * Destructor.
 */
Element::~Element()
{
    this->destructor_count++;
}

/**
 * Getter.
 * @return the value.
 */
long Element::get_value() const { return value; }

void Element::reset()
{
	copy_count = 0;
	destructor_count = 0;
}

 bool operator < (const Element & e1, const Element & e2)
{

	if (e1.value < e2.value)
		return true;
	else
		return false;

}

bool operator > (const Element & e1, const Element & e2)
{
	if (e1.value > e2.value)
		return true;
	else
		return false;

}


ostream& operator <<(ostream& out, const Element& e)
{
   out << e.value;
   return out;
}



