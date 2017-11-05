#ifndef BOOK_H_
#define BOOK_H_

#include <string>
using namespace std;



/***** Complete this file. *****/

/**
 * The Book class.
 */
class Book
{
public:
    /**
     * Book categories.
     */
    //enum class Category { FICTION, HISTORY, TECHNICAL, NONE };

    /**
     * Default constructor.
     */
    Book();

    /**
     * Constructor.
     */
    Book(string isbn, string last, string first, string title);

    /**
     * Destructor.
     */
    ~Book();



    friend istream& operator >> ( istream& in, Book& book);
    friend ostream& operator << ( ostream& out , Book& book);

     void remove_entry(string isbn);


    void set_isbn(string isbn);
    void set_last(string last);
    void set_first(string first);
    void set_title(string title);
    //void set_category(string category);

    string get_isbn() { return isbn;}
    string get_last() { return last;}
    string get_first(){ return first;}
    string get_title(){ return title;}
    //string get_category(){ return category;}




private:

    string isbn;
    string last;
    string first;
    string title;
    //string category;
};



#endif /* EMPLOYEE_H_ */
