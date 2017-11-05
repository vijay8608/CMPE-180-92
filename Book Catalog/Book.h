#ifndef BOOK_H_
#define BOOK_H_

#include <string>
using namespace std;


/**
 * The Book class.
 */
class Book
{
public:
    /**
     * Book categories.
     */
    enum class Category { FICTION, HISTORY, TECHNICAL, NONE };

    /**
     * Default constructor.
     */
    Book();

    /**
     * Constructor.
     */
    Book(string isbn, string last, string first, string title, Category category);

    /**
     * Destructor.
     */
    ~Book();

    friend istream& operator >> ( istream& in, Book& book);
    friend ostream& operator << ( ostream& out , Book& book);

    void remove_entry(string isbn);

    string get_isbn() const { return isbn;}
    string get_last() const { return last;}
    string get_first() const { return first;}
    string get_title() const { return title;}
    Book::Category get_category() const { return category;}

private:
    string isbn;
    string last;
    string first;
    string title;
    Category category;
};

ostream& operator <<(ostream& out, const Book::Category& category);


#endif /* EMPLOYEE_H_ */
