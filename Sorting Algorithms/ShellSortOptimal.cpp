#include "ShellSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) :VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
void ShellSortOptimal::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
	int length = size;
	int j, g;
	//Element temp;

	for ( g = 1 ; g < length ; g = 3*g + 1)
	{
		//cout << g << endl;
	}

	g = (g-1)/3;

	for (int i = g; i > 0 ; i = (i-1)/3)
	{
		for ( j = i; j < length ; j++)
		{
			Element temp = data[j];
			int k;
			compare_count++;
			for (k = j ; k >= i && data[k - i] > temp; k -=i )
			{
				move_count++;
				data[k] = data[k-i];
			}
			move_count++;
			data[k] = temp;
		}
	}
}
