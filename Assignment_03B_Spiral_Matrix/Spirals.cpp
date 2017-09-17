/**
    CMPE 180-92, Spiral.cpp
    Purpose: Print elements using a 2d array in spiral form starting from the
    center of the n*n matrix and going outwards in anti-clock wise direction.

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

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

/**
    Calls function make_spiral and print_spiral to compute adnd print a 2d array of size 'n' and starting number 'start'.

    @param n. Constant integer n , specifying the size of the n*n matrix. Example: if n = 5 , matrix size is 5*5.
    @param start. Specifies the starting integer that should be placed at the center of the matrix.
*/
void do_spiral(const int n, const int start);

/**
    Make a spiral matrix of size n with start as the central starting integer.

	@param array[][MAX_SIZE]. array where the elements to be printed are stored.
    @param n. Constant integer n , specifying the size of the n*n matrix. Example: if n = 5 , matrix size is 5*5.
    @param start. Specifies the starting integer that should be placed at the center of the matrix.
*/
void make_spiral(int array[][MAX_SIZE],int n, int start);

/**
    Print spiral matrix of size n with start as the central starting integer.

	@param array[][MAX_SIZE]. array where the elements to be printed are stored.
    @param n. Constant integer n , specifying the size of the n*n matrix. Example: if n = 5 , matrix size is 5*5.
    @param start. Specifies the starting integer that should be placed at the center of the matrix.
*/
void print_spiral(int array[][MAX_SIZE],int n, int start);


int main()
{
	do_spiral(1, 1);
	do_spiral(5, 1);
	do_spiral(9, 11);
	do_spiral(12, 13);
	do_spiral(15, 17);

	return 0;

}

void do_spiral( const int n, const int start)
{
	int array[MAX_SIZE][MAX_SIZE];	// array of size MAX_SIZE.

	if ( n <= MAX_SIZE || start <= 50)
	{
		if (n%2 != 0)						// checking if matrix size is odd or even
		{
			make_spiral( array, n,  start);	// calling function to compute spiral matrix
		}

		print_spiral(array, n, start);	// calling function to print spiral matrix

	}
	else
		cout << "Enter a size less then " << MAX_SIZE << " and and starting integer as less then " << start <<"." <<endl;


}

void make_spiral( int array[][MAX_SIZE] , int n , int start)
{

	int center = (n-1)/2;
	int row = center;
	int column = center;
	int i = 0;

	array[center][center] = start;	// initializing array center with value of start.

	int number = start;

	int count = 1;
	bool trip = false;
	int l;

	while ( i < (n-1)/2)
	{
		if(!trip)
		column = column + 1;

		// upward movement in the matrix
		for ( l = row ; l >= row - count ; l-- )
		{
			number = number + 1;
			array[l][column] = number ;
		}

		row = l+1;
		column = column - 1;

		//left movement in the matrix
		for(l = column ; l >= column - count ; l--)
		{
			number = number + 1;
			array[row][l] = number;
		}

		column = l+1;
		row = row + 1;

		// down movement in the matrix
		for ( l = row ; l <= row + count ; l++ )
		{
			number = number + 1;
			array[l][column] = number;
		}

		row = l-1;
		column = column + 1;

		// right movement in the matrix
		for (l = column ; l <= column + count ; l++)
		{
			number = number + 1;
			array[row][l] = number;
		}

		column = l;

		i++;
		count = count +2;
		trip = true;
	}

}

void print_spiral(int array[][MAX_SIZE],int n, int start)
{

	cout << "Spiral of size " << n << " starting at " << start << endl;

	if (n%2 != 0)
	{
		cout << endl;
		for (int i = 0; i < n ; i++)
			{
				for(int j = 0 ; j < n ; j++)
				{
					cout << setw(4) << array[i][j] ;
				}
				cout << endl ;
			}
		cout << endl;
	}
	else
		cout << "***** Error: Size " << n << " must be odd." << endl << endl;

}







