#ifndef NODE_H_
#define NODE_H_

#include "Element.h"

/**
 * A node of the linked list for mergesort.
 */
class Node
{
public:
    Node();
    Node(Element e);
    virtual ~Node();
    Node *next;

    Element element;
};

#endif /* NODE_H_ */
