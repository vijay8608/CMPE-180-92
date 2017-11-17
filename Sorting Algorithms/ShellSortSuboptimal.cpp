#include "ShellSortSuboptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortSuboptimal::ShellSortSuboptimal(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/

	//reference http://www.geeksforgeeks.org/shellsort/

	int length = size;
	int j;
	//Element temp;

	for (int i = length/2; i > 0 ; i = i/2)
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
