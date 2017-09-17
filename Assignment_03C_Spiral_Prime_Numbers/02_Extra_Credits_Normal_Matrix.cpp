/**
    CMPE 180-92, Extra_Credits_Normal_Matrix.cpp
    Purpose: Print elements using assignment 3a and 3b and instead of arrays using vectors that print "#" and "."
    in place of prime and composite numbers respectively. Like the normal matrix pattern as shown below:

    			1  2  3  4  5
    			6  7  8  9  10
    			11 12 13 14 15
    			16 17 18 19 20
    			21 22 23 24 25


    			Normal Matrix

	Pattern Description : A thick line appears from below top left corner to little before bottom right corner.


    @author Vijay Yadav
    @student_id 011463192
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
 * Uses Vector1 with numbers and vector3 with prime locations to deduce a prime_matrix with "#" instead of prime numbers and
 * "." in place of composite numbers
 *
 * @param vector1. Vector1 is used to check for prime numbers in the matrix.
 * @param vector2. Vector2 stores "#" and "." in place of prime and composite numbers respectively.
 * @param vector3. Vector3 is used to compare matrix values with vector3 locations of value 1.
 * @param n. Helps in the loop to keep the determined size.
*/
void prime_matrix(vector<vector<int> > &vector1,vector<vector<string> > &vector2, vector<int> &vector3, int n , int start);

/**
 * Calls function make_matrix and print_matrix to compute and print a matrix of size 'n' and starting number 'start'.
 *
 * @param n. Constant integer n , specifying the size of the n*n matrix. Example: if n = 5 , matrix size is 5*5.
 * @param start. Specifies the starting integer that should be placed at the starting of the matrix.
*/
void do_prime_matrix(const int n, const int start);

/**
 * Make a  matrix of size n with start as the starting integer at location 0,0
 *
 * @param vector1. vector where the elements to be printed are stored.
 * @param n. Constant integer n , specifying the size of the n*n matrix. Example: if n = 5 , matrix size is 5*5.
 * @param start. Specifies the starting integer that should be placed at the starting of the matrix.
*/
void make_matrix(vector<vector<int> > &vector1,int n, int start);

/**
 * Print matrix of size n with start as the starting integer.
 *
 * @param vector2. vector where the elements - "#" or "." to be printed are stored.
 * @param n. Constant integer n , specifying the size of the n*n matrix. Example: if n = 5 , matrix size is 5*5.
 * @param start. Specifies the starting integer that should be placed at the start of the matrix.
 *
*/
void print_matrix(vector<vector<string> > &vector2,int n, int start);


int main()
{
    do_prime_matrix(5, 1);
    do_prime_matrix(25, 11);
    do_prime_matrix(35, 0);
    do_prime_matrix(50, 31);
    do_prime_matrix(101, 41);

    return 0;
}

void do_prime_matrix( const int n, const int start)
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
			make_matrix( vector1, n,  start);
			compute_primes(vector3, n , start);
			prime_matrix(vector1,vector2, vector3, n , start);
		}

		print_matrix(vector2, n, start);
	}


}

void make_matrix( vector<vector<int> > &vector1 , int n , int start)
{

	int number = start;


	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			vector1[i][j]  = number ++;
		}
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


void prime_matrix(vector<vector<int> > &vector1,vector<vector<string> > &vector2, vector<int> &vector3, int n , int start)
{
	for(int i = start ; i < ((n*n) + start) ; i++)		// computing prime spiral and storing in vector2
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
		else if(vector3[i] == 0)							// computing composite spiral and storing in vector2
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


void print_matrix(vector<vector<string> > &vector2,int n, int start)
{

	cout << "Prime matrix of size " << n << " starting at " << start << endl;

	if (n%2 != 0 && start > 0 && start <= MAX_START)			// printing prime and composite matrix of "#" and "." respectively
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

