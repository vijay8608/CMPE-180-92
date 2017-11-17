#ifndef DATA_H_
#define DATA_H_

#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
    Element();
    Element(long val);
    Element(const Element& other);
    virtual ~Element();

    long get_value() const;

    friend bool operator < (const Element & e1, const Element & e2);

    friend bool operator > (const Element & e1, const Element & e2);

    friend ostream& operator << (ostream & out, const Element & e);



    static void reset();
    static long get_destructor_count(){return destructor_count;}
    static long get_copy_count(){return copy_count;}



    /***** Complete this class. *****/

private:
    long value;
    static long copy_count;
    static long destructor_count;
};

#endif /* DATA_H_ */
