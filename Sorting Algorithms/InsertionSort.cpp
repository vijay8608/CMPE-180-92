#include "InsertionSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
// referenced from http://www.geeksforgeeks.org/insertion-sort/

void InsertionSort::run_sort_algorithm() throw (string)
{
	int i, j;

	for ( i = 1; i < size; i++)
	{
		j = i-1;
		Element element = data[i];

		compare_count++;
		while (j >= 0 && data[j ] > element)
	    {
			move_count++;
	    		data[j+1] = data[j];
	    		j = j -1;
	    		compare_count++;
	    }

		move_count++;
		data[j+1] = element;
	}

}



