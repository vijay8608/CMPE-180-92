#ifndef TIMEDCONTAINER_H_
#define TIMEDCONTAINER_H_

#include <string>
#include "Word.h"
#include <chrono>

/***** Modify this file as needed. *****/

using namespace std;

/**
 * Abstract base class for timing concordance
 * insertion and search operations.
 */
class TimedContainer
{
public:
    /**
     * Default constructor.
     */
    TimedContainer();

    /**
     * Destructor.
     */
    virtual ~TimedContainer();

    /**
     * Getter.
     * @return the elapsed time.
     */
    long get_elapsed_time() const { return elapsed_time;}

    /**
     * Reset the elapsed time to 0.
     */
    void reset_elapsed_time(){ elapsed_time = 0; }

    /**
     * Time the insertion operation and
     * add the time to elapsed_time.
     * @param text the text of the word to insert.
     * @return pointer to the inserted word element.
     */
    Word *timed_insert(const string text);

    /**
     * Time the search operation and
     * add the time to elapsed_time.
     * @param text the text of the word to insert.
     * @return pointer to the word element if found, else nullptr.
     */
    Word *timed_search(const string text);

    /**
     * The insertion operation to be implemented by subclasses.
     * @param text the text of the word to insert.
     * @return pointer to the inserted word element.
     */
    virtual Word *insert(const string text) = 0;

    /**
     * The search operation to be implemented by subclasses.
     * @param text the text of the word to insert.
     * @return pointer to the word element if found, else nullptr.
     */
    virtual Word *search(const string text) = 0;
    void increment_elapsed_time(const long time) { elapsed_time += time; }

private:
    long elapsed_time;
};

#endif /* TIMEDCONTAINER_H_ */
