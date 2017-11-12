#include "TimedContainer.h"
#include "Word.h"

/***** Modify this file as needed. *****/
TimedContainer::TimedContainer()
{
	elapsed_time = 0;
}

TimedContainer::~TimedContainer()
{

}

Word *TimedContainer::timed_insert(const string text)
{
    // Start the timer.
    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();

    // Do the insertion.
    Word *word = insert(text);

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
    increment_elapsed_time(std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count());

    return word;
}

Word *TimedContainer::timed_search(const string text)
{
    // Start the timer.
    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();

    // Do the search.
    Word *word = search(text);

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
    long elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    increment_elapsed_time(elapsed);

    return word;
}
