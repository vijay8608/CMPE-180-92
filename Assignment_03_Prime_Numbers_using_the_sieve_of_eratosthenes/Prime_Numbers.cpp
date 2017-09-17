/**
    CMPE 180-92, Prime_Numbers.cpp
    Purpose: Compute and print the prime numbers up to MAX_NUMBER using Sieve of Eratosthenes algorithm.

    @author Vijay Yadav
    @student_id 011463192
    @date 09/10/2017
*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing

/**
    Computes prime numbers using the specified array.

    @param array. A boolean array initialized as true.
*/
void compute_primes( bool array[]);

/**
    Print prime numbers in rows of size 20.

    @param array. With elements at prime location set as true.
*/
void print_primes( bool array[]);


int main()
{
	bool array[MAX_NUMBER];		// boolean array of maximum size MAX_NUMBER.

	for (int i = 2 ; i < MAX_NUMBER ; i++)	// set array elements as true.
	{
		array[i] = true;
	}

	compute_primes(array);					// computes prime numbers using the specified array.

	print_primes(array);						// print prime numbers in rows of size 20.

	return 0;
}

void compute_primes( bool array[])	// set composite locations of array to false.(except 0 and 1 as we start printing from 2 ignoring 0 and 1)
{
	for (unsigned int i = 2 ; i < sqrt(MAX_NUMBER); i++)
	{
		if (array[i] == true)
		{
			for(int j = 2 ; i*j < MAX_NUMBER ; j++)
			{
				array[i*j] = false;
			}
		}
	}
}

void print_primes(bool array[])	// print elements that are true
{
	int count = 0;
	int total_prime_numbers = 0;;

	for (unsigned int i = 2; i < MAX_NUMBER ; i++)
	{
		if (array[i] == true )
		{
			cout << right << setw(4)<< i ;
			count ++;
			total_prime_numbers++;
		}
		if (count == ROW_SIZE)
		{
			cout << endl;
			count = 0;
		}
	}

	cout << endl << endl << "Done!" ;

	//cout << endl << "Total Prime Numbers : " <<total_prime_numbers;

}
