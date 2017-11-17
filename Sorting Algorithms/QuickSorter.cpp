#include <iostream>
#include "QuickSorter.h"
using namespace std;

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
void QuickSorter::quicksort(const int left, const int right)
{
    /***** Complete this member function. *****/

	if (left < right)
	{
		Element pivot = choose_pivot(left,right);
		int pivot_value = partition(left,right,pivot);
		quicksort(left, pivot_value - 1 );
		quicksort(pivot_value + 1, right);
	}

}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */
int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
    /***** Complete this member function. *****/

	//Reference D S Malik 2nd Edition

	int index, smallIndex;


	if (left >= 0 )
	{
		if (left < size)
		{
			if ( pivot.get_value() != data[left].get_value())
			{
				compare_count++;
				if (data[right].get_value() != pivot.get_value())
				{
					swap(left, (left+right)/2);
				}
				else
				{
					swap(left, right);
				}
			}
		}
	}

	smallIndex = left;

	for (index = left + 1; index <= right; index++)
	{
		if (data[index] < pivot)
		{
			smallIndex++;
			swap(smallIndex, index);
		}
	}

	swap(left, smallIndex);

	return smallIndex;

}
