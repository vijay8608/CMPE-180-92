/**
    CMPE 180-92, Extra_Credit.cpp
    Purpose: Print elements using assignment 3a and 3b and instead of arrays using vectors that print "#" and "."
    in place of prime and composite numbers respectively. Like the diagonal pattern as shown below:

    			1  3  6  10 15
    			2  5  9  14 19
    			4  8  13 18 22
    			7  12 17 21 24
    			11 16 20 23 25


    			Diagonal Matrix


     Pattern Output Description :  A diagonal line of prime numbers represented by "#" seems to appear
     from top left corner to bootom right corner.

    @author Vijay Yadav
    @date 09/10/2017
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const int MAX_START = 50;   // maximum starting number

/**
 * Computes prime numbers using the specified vector.
 * @param vector3. An integer vector which will store 1 at prime locations of the array.
 * @param n. size of the vector.
 * @param start. the first value of the integer. Used here to determine the size of the vector and limit the loop size.
 *
*/
void compute_primes(vector<int> &vector3,int n, int start);

/**
 * Uses Vector1 with diagonal numbers and vector3 with prime locations to deduce a prime_diagonal with "#" instead of prime numbers and
 * "." in place of composite numbers
 *
 * @param vector1. Vector1 is used to check for prime numbers in the diagonal matrix.
 * @param vector2. Vector2 stores "#" and "." in place of prime and composite numbers respectively.
 * @param vector3. Vector3 is used to compare diagonal matrix values with vector3 locations of value 1.
 * @param n. Helps in the loop to keep the determined size.
*/
void prime_diagonal(vector<vector<int> > &vector1,vector<vector<string> > &vector2, vector<int> &vector3, int n , int start);

/**
 * Calls function make_diagonal and print_diagonal to compute and print a matrix of size 'n' and starting number 'start'.
 *
 * @param n. Constant integer n , specifying the size of the n*n matrix. Example: if n = 5 , matrix size is 5*5.
 * @param start. Specifies the starting integer that should be placed at the center of the matrix.
*/
void do_prime_diagonal(const int n, const int start);

/**
 * Make a diagonal matrix of size n with start as the central starting integer.
 *
 * @param vector1. vector where the elements to be printed are stored.
 * @param n. Constant integer n , specifying the size of the n*n matrix. Example: if n = 5 , matrix size is 5*5.
 * @param start. Specifies the starting integer that should be placed at the center of the matrix.
*/
void make_diagonal(vector<vector<int> > &vector1,int n, int start);

/**
 * Print diagonal matrix of size n with start as the central starting integer.
 *
 * @param vector2. vector where the elements - "#" or "." to be printed are stored.
 * @param n. Constant integer n , specifying the size of the n*n matrix. Example: if n = 5 , matrix size is 5*5.
 * @param start. Specifies the starting integer that should be placed at the center of the matrix.
 *
*/
void print_diagonal(vector<vector<string> > &vector2,int n, int start);


int main()
{
    do_prime_diagonal(5, 1);
    do_prime_diagonal(25, 11);
    do_prime_diagonal(35, 0);
    do_prime_diagonal(50, 31);
    do_prime_diagonal(101, 41);

    return 0;
}

void do_prime_diagonal( const int n, const int start)
{
	vector<vector<int> > vector1(n,vector<int>(n));
	vector<vector<string> > vector2(n,vector<string>(n));
	vector<int> vector3(((n*n) + start));

	for (int i = 2 ; i < ((n*n)+start) ; i++)	// initializing vector elements to 1
	{
				vector3[i] = 1;
	}

	vector3[0] = vector3[1] = 0;				// set vector element 0 and 1 to "0" as they are not primes.

	if ( start <= MAX_START || start > 0)	// checking the MAX_START is greater than start
	{
		if (n%2 != 0)
		{
			make_diagonal( vector1, n,  start);
			compute_primes(vector3, n , start);
			prime_diagonal(vector1,vector2, vector3, n , start);
		}

		print_diagonal(vector2, n, start);
	}


}

void make_diagonal( vector<vector<int> > &vector1 , int n , int start)
{
	int number = start;

    for (int i = 0; i < n ; i++)
    {
    		for (int j = 0 ; j < n ; j++)
    		{
    			vector1[i][j] = 1;
	    	}
    }

    for (int i = 0; i < n ; i++)
	{
    		int k = i;
		for (int j = 0 ; j < n ; j++)
		{
			vector1[k][j] = number;
			number++;
			if (k == 0)
			{
				break;
			}
			k--;
		}
	}

    int remaining = n-1;
    int m = 1;

	while(remaining )
	{
		int k = n-1;

		for (int j = m ; j < n ; j++)
		{
			vector1[k][j] = number;
			number++;
			k--;
			if (k == 0)
			{
				break;
			}
		}
		remaining --;
		m++;
	}

}

void compute_primes(vector<int> &vector3,int n, int start)
{

	for (int i = 2 ; i < ((n*n) + start); i++)				// set composite locations to "0"
	{
		if (vector3[i] == 1)
		{
			for(int j = 2 ; i*j < ((n*n) + start) ; j++)
			{
				vector3[i*j] = 0;
			}
		}
	}
}


void prime_diagonal(vector<vector<int> > &vector1,vector<vector<string> > &vector2, vector<int> &vector3, int n , int start)
{
	for(int i = start ; i < ((n*n) + start) ; i++)		// computing prime diagonal and storing in vector2
	{
		if(vector3[i] == 1)
		{
			for(int j = 0 ; j < vector1.size() ; j++)
			{
				for (int k =0 ; k < vector1.size(); k++)
				{
					if (vector1[j][k] == i)
					{
						vector2[j][k] = "#";
					}

				}
			}
		}
		else if(vector3[i] == 0)							// computing composite diagonal and storing in vector2
		{
			for(int j = 0 ; j < vector1.size() ; j++)
			{
				for (int k =0 ; k < vector1.size(); k++)
				{
					if (vector1[j][k] == i)
					{
						vector2[j][k] = ".";
					}

				}
			}
		}

	}

}


void print_diagonal(vector<vector<string> > &vector2,int n, int start)
{

	cout << "Prime diagonal of size " << n << " starting at " << start << endl;

	if (n%2 != 0 && start > 0 && start <= MAX_START)			// printing prime and composite diagonal as "#" and "." respectively
	{
		cout << endl;
		for (int i = 0; i < vector2.size() ; i++)
			{
				for(int j = 0 ; j < vector2.size() ; j++)
				{
					cout << setw(1) << vector2[i][j] ;
				}
				cout << endl ;
			}
		cout << endl;
	}
	else if ( start <= 0 )
		cout << "***** Error: Starting value " << start << " < 1 or > " << MAX_START << endl << endl;
	else
		cout << "***** Error: Size " << n << " must be odd." << endl << endl;

}

