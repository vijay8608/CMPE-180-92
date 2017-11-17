#include "Node.h"
#include "Element.h"

Node::Node()
{
	Element();
	next = nullptr;
}

Node::~Node()
{

}

Node::Node(Element e)
{
	element = e;
}
