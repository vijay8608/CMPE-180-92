/**
    CMPE 180-92, Prime_Spirals.cpp
    Purpose: Print elements using assignment 3a and 3b and instead of arrays using vectors that print "#" and "."
    in place of prime and composite numbers respectively, starting from the center of the matrix and moving outwards in
    spiral motion in anti-clockwise direction.

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

//void compute_primes(vector<int> &vector3,int n, int start);

void compute_primes( bool array[], int n , int start);

//void prime_spiral(vector<vector<int> > &vector1,vector<vector<string> > &vector2, vector<int> &vector3, int n , int start);

void prime_spiral(vector<vector<int> > &vector1,vector<vector<string> > &vector2, bool array[], int n , int start);

void do_prime_spiral(const int n, const int start);

void make_spiral(vector<vector<int> > &vector1,int n, int start);

void print_spiral(vector<vector<string> > &vector2,int n, int start);


int main()
{
    do_prime_spiral(5, 1);
    do_prime_spiral(25, 11);
    do_prime_spiral(35, 0);
    do_prime_spiral(50, 31);
    do_prime_spiral(101, 41);

    return 0;
}

void do_prime_spiral( const int n, const int start)
{
	vector<vector<int> > vector1(n,vector<int>(n));
	vector<vector<string> > vector2(n,vector<string>(n));
//	vector<int> vector3(((n*n) + start));
	bool array[(n*n)+start];

	for (int i = 2 ; i < (n*n)+start ; i++)	// set array elements as true.
	{
		array[i] = true;
	}
	array[0] = 0;
/*
	for (int i = 2 ; i < ((n*n)+start) ; i++)	// set array elements as true.
	{
				vector3[i] = 1;
	}

	vector3[0] = vector3[1] = 0;
*/
	if ( start <= MAX_START || start > 0)
	{
		if (n%2 != 0)
		{
			make_spiral( vector1, n,  start);
			compute_primes(array, n, start);
//			compute_primes(vector3, n , start);
//			prime_spiral(vector1,vector2, vector3, n , start);
			prime_spiral(vector1,vector2, array, n , start);
		}

		print_spiral(vector2, n, start);
	}


}

void make_spiral( vector<vector<int> > &vector1 , int n , int start)
{

	int center = (n-1)/2;
	int row = center;
	int column = center;
	int i = 0;


	vector1[center][center] = start;

	int number = start;

	int count = 1;
	bool trip = false;
	int l;

	while ( i < (n-1)/2)
	{
		if(!trip)
		column = column + 1;

		// upward movement
		for ( l = row ; l >= row - count ; l-- )
		{
			number = number + 1;
			vector1[l][column] = number ;
		}

		row = l+1;
		column = column - 1;

		//left movement
		for(l = column ; l >= column - count ; l--)
		{
			number = number + 1;
			vector1[row][l] = number;
		}

		column = l+1;
		row = row + 1;

		// down movement
		for ( l = row ; l <= row + count ; l++ )
		{
			number = number + 1;
			vector1[l][column] = number;
		}

		row = l-1;
		column = column + 1;

		// right movement
		for (l = column ; l <= column + count ; l++)
		{
			number = number + 1;
			vector1[row][l] = number;
		}

		column = l;

		i++;
		count = count +2;
		trip = true;
	}

}
/*
void compute_primes(vector<int> &vector3,int n, int start)
{

	for (int i = 2 ; i < ((n*n) + start); i++)
	{
		if (vector3[i] == 1)
		{
			for(int j = 2 ; i*j < n*n ; j++)
			{
				vector3[i*j] = 0;
			}
		}
	}
}

*/
void compute_primes( bool array[], int n, int start)	// set composite locations of array to false.(except 0 and 1 as we start printing from 2 ignoring 0 and 1)
{
	array[0] = array[1] = 0;
	for (int i = 2 ; i < ((n*n) + start); i++)
		{
			if (array[i] == true)
			{
				for(int j = 2 ; i*j < ((n*n) + start) ; j++)
				{
					array[i*j] = false;
				}
			}
		}
}


void prime_spiral(vector<vector<int> > &vector1,vector<vector<string> > &vector2, bool array[], int n , int start)
{
	for(int i = start ; i < ((n*n) + start) ; i++)
	{
		if(array[i] == 1)
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
		else if(array[i] == 0)
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

void print_spiral(vector<vector<string> > &vector2,int n, int start)
{

	cout << "Prime Spiral of size " << n << " starting at " << start << endl;

	if (n%2 != 0 && start > 0 && start <= MAX_START)
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
