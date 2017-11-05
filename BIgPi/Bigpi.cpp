/**
	CMPE 180-92, BigPI.cpp
    Purpose: Compute and print the first thousand decimal places of pi using
    			 Borwein's algorithm ( Nonic Convergence algorithm ) and Newtons cube root method

    @author Vijay Yadav
    @student_id 011463192
    @date 09/20/2017
*/
#include <iostream>
#include <iomanip>
#include <mpir.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>

using namespace std;

const int MAX_ITERATIONS = 100;
const int PLACES         = 1000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal
const int BIT_COUNT  = 8;   // bits per machine word
const int BASE       = 10;  // base 10 numbers
const int BLOCK_SIZE = 10;                // print digits in blocks
const int GROUP_SIZE = 5;                 // line grouping size

/**
 * Compute the cube root of a positive integer.
 * @param x the number whose cube root to compute.
 */
void cube_root(mpf_t& x)
{
	mpf_t x0; mpf_init(x0);
	mpf_t x1; mpf_init(x1);

	mpf_set_d (x0 , 1.0);

	mpf_t temp; mpf_init(temp);
	mpf_t temp1; mpf_init(temp1);
	mpf_t temp2; mpf_init(temp2);
	mpf_t temp3; mpf_init(temp3);

	int count = MAX_ITERATIONS;
	int compare;

	while (count)
	{
		mpf_pow_ui (temp, x0, 2);		// temp = x0^2
		mpf_div (temp1, x, temp);		// temp1 = x / x0^2
		mpf_mul_ui (temp2, x0, 2);		// temp2 = 2*x0
		mpf_add (temp3, temp1, temp2);	// temp3 = (x / x0^2) + 2*x0
		mpf_div_ui (x1, temp3, 3);		// x1 = ((x / x0^2) + 2*x0) / 3

		compare = mpf_cmp(x1 , x0);		// if x1 == x0 break the loop

		if (compare == 0) break;

		mpf_set (x0, x1);				// x0 = x1

		count--;
	}
	mpf_set(x,x0);
}

/*
 * Print the precise PI value upto 100 decimal digits
 * @param str The c string with PI value
 */
void print_BigPi(char *str)
{
    cout << str[0] ;
    cout << ".";
    int l = 1;

    for (int k = 1 ; k <=2 ; k++)
    {
        for (int g = 1 ; g <= GROUP_SIZE ; g++)
        {
        		for (int h = 1 ; h <= 10 ; h++)
        		{
        			for (int j = 1; j <= BLOCK_SIZE ; j++)
        			{
        				cout << str[l] ;
        				l++;
        			}
        			cout << " ";
        		}
        		cout << endl << "  ";
        }
        cout << endl << "  ";
    }
}

/*
 * compute variable a0
 * @param a0 = 1.0 / 3.0
 */
void setting_a0(mpf_t& a0)
{
	// setting a0 = 1/3

    mpf_t a0_temp2; mpf_init(a0_temp2);
    mpf_t a0_temp3; mpf_init(a0_temp3);
    mpf_set_d (a0_temp2, 1.0);				// a0_temp2 = 1.0
    mpf_set_d (a0_temp3, 3.0);				// a0_temp3 = 3.0
    mpf_div (a0, a0_temp2, a0_temp3);		//  a0 = 1.0 / 3.0

}

/*
 * compute variable r0
 * @param r0 = (sqrt(3.0) - 1.0) / 2.0
 */
void setting_r0(mpf_t& r0)
{
	 // setting r0 = (square_root(3) - 1)/2

	mpf_t r0_temp1 ; mpf_init(r0_temp1);
    mpf_t r0_temp2 ; mpf_init(r0_temp2);
    mpf_t r0_temp3 ; mpf_init(r0_temp3);
    mpf_t r0_temp4 ; mpf_init(r0_temp4);

    mpf_set_d (r0_temp1 , 3.0);				// r0_temp1 = 3.0
    mpf_sqrt (r0_temp2, r0_temp1);			// r0_temp2 = sqrt(3.0)
    mpf_set_d (r0_temp3 , 1.0);				// r0_temp3 = 1.0
    mpf_set_d (r0_temp4 , 2.0);				// r0_temp4 = 2.0
    mpf_sub (r0, r0_temp2, r0_temp3);		// r0 = sqrt(3.0) - 1.0
    mpf_div (r0, r0, r0_temp4);				// r0 = (sqrt(3.0) - 1.0) / 2.0

}

/*
 * compute variable s0
 * @param s0 = (1 - r0*r0*r0)
 * @param r0 required for computation
 */
void setting_s0(mpf_t& s0, mpf_t& r0)
{
    // setting s0 = (1-r0^3)^(1/3)

    mpf_t s0_temp; mpf_init(s0_temp);
    mpf_mul (s0_temp, r0, r0);			// s0_temp = r0*r0
    mpf_mul (s0_temp, s0_temp, r0);		// s0_temp = r0*r0*r0
    mpf_ui_sub (s0, 1, s0_temp);			// s0 = (1 - r0*r0*r0)

    cube_root(s0);

}

/*
 * compute variable t1
 * @param t1 = 2*r0 + 1
 * @param r0 required for computation
 */
void setting_t1(mpf_t& t1, mpf_t r0)
{
    // setting tn+1

    mpf_mul_ui (t1, r0, 2);				//t1 = 2*r0
    mpf_add_ui (t1, t1, 1);				//t1 = 2*r0 + 1

}

/*
 * compute variable u1
 * @param u1 = (r0*r0 + r0 + 1)*r0*9
 * @param r0 required for computation
 */
void setting_u1(mpf_t& u1, mpf_t& r0)
{
	 // setting un+1
	mpf_mul (u1, r0, r0);				// u1 = r0*r0
	mpf_add (u1, u1, r0);				// u1 = r0*r0 + r0
	mpf_add_ui (u1, u1, 1);				// u1 = r0*r0 + r0 + 1
	mpf_mul (u1, u1, r0);				// u1 = (r0*r0 + r0 + 1)*r0
	mpf_mul_ui (u1, u1, 9);				// u1 = (r0*r0 + r0 + 1)*r0*9

	cube_root(u1);

}

/*
 * compute variable v1
 * @param v1 = t1*t1 + t1*u1 + u1*u1
 * @param t1 required for computation
 * @param u1 required for computation
 */
void setting_v1(mpf_t& v1, mpf_t& t1, mpf_t& u1)
{
    // setting vn+1

    mpf_t v1_temp; mpf_init(v1_temp);
    mpf_t v1_temp1; mpf_init(v1_temp1);

    mpf_mul (v1, t1 , t1);				// v1 = t1*t1
    mpf_mul (v1_temp, t1, u1);			// v1_temp = t1*u1
    mpf_mul (v1_temp1, u1, u1);			// v1_temp1 = u1*u1
    mpf_add (v1, v1 , v1_temp);			// v1 = t1*t1 + t1*u1
    mpf_add (v1 , v1 , v1_temp1);		// v1 = t1*t1 + t1*u1 + u1*u1

}

/*
 * compute variable w1
 * @param w1 = (s0*s0 + s0 + 1)*27/v1
 * @param s0 required for computation
 * @param v1 required for computation
 */
void setting_w1(mpf_t&w1, mpf_t& s0, mpf_t& v1)
{
    // setting wn+1

    mpf_t w1_temp; mpf_init(w1_temp);
    mpf_t w1_temp1; mpf_init(w1_temp1);
    mpf_t w1_temp2; mpf_init(w1_temp2);

    mpf_pow_ui (w1_temp, s0 , 2);			// w1_temp = s0*s0
    mpf_add (w1_temp1, w1_temp , s0);		// w1_temp1 = s0*s0 + s0
    mpf_add_ui (w1_temp2, w1_temp1 , 1);	// w1_temp2 = s0*s0 + s0 + 1
    mpf_mul_ui (w1_temp2, w1_temp2 , 27);	// w1_temp = (s0*s0 + s0 + 1)*27
    mpf_div (w1, w1_temp2, v1);			// w1 = (s0*s0 + s0 + 1)*27/v1

}

/*
 * compute variable a1
 * @param a1 = (1 - w1) * ((3^(2n)) / 3) + a0*w1
 * @param w1 required for computation
 * @param n required for computation
 * @param a0 required for computation
 */
void setting_a1(mpf_t& a1, mpf_t& w1, int n, mpf_t a0)
{
    // setting an+1

    mpf_t a1_temp; mpf_init(a1_temp);
    mpf_t a1_temp1; mpf_init(a1_temp1);
    mpf_t a1_temp2; mpf_init(a1_temp2);
    mpf_t a1_temp3; mpf_init(a1_temp3);
    mpf_t a1_temp4; mpf_init(a1_temp4);

    mpf_mul (a1_temp, a0 , w1);			// a1_temp = a0*w1
    mpf_ui_sub (a1_temp1, 1, w1);		// a1_temp1 = 1 - w1
    mpf_set_d(a1_temp3, 3.0);			//a1_temp3 = 3
    mpf_pow_ui(a1_temp4, a1_temp3,2*n);	// a1_temp4 = 3^(2n)
    mpf_div(a1_temp4, a1_temp4 , a1_temp3);	// a1_temp4 =  (3^(2n)) / 3
    mpf_mul(a1_temp1, a1_temp1, a1_temp4);	// a1_temp1 = (1 - w1) * ((3^(2n)) / 3)
    mpf_add(a1 ,a1_temp1, a1_temp);			// a1 = (1 - w1) * ((3^(2n)) / 3) + a0*w1

}

/*
 * compute variable s1
 * @param s1 = ((1 - r0)*(1 - r0)*(1 - r0)) / (2*u1 + t1)*v1
 * @param r0 required for computation
 * @param u1 required for computation
 * @param t1 required for computation
 * @param v1 required for computation
 */
void setting_s1(mpf_t& s1, mpf_t& r0, mpf_t& u1, mpf_t& t1, mpf_t& v1)
{
    // setting s1

    mpf_t s1_temp; mpf_init(s1_temp);
    mpf_t s1_temp1; mpf_init(s1_temp1);
    mpf_t s1_temp2; mpf_init(s1_temp2);
    mpf_t s1_temp3; mpf_init(s1_temp3);

    mpf_ui_sub(s1_temp, 1, r0);				// s1_temp = 1 - r0
    mpf_pow_ui (s1_temp1, s1_temp , 3);		// s1_temp1 = (1 - r0)*(1 - r0)*(1 - r0)
    mpf_mul_ui(s1_temp2, u1, 2);				// s1_temp2 = 2*u1
    mpf_add(s1_temp2, s1_temp2, t1);			// s1_temp2 = 2*u1 + t1
    mpf_mul(s1_temp3, s1_temp2, v1);			// s1_temp3 = (2*u1 + t1)*v1
    mpf_div(s1, s1_temp1, s1_temp3);			// s1 = ((1 - r0)*(1 - r0)*(1 - r0)) / (2*u1 + t1)*v1

}

/*
 * compute variable r1
 * @param r1 = = 1 - s1*s1*s1
 * @param s1 required for computation
 */
void setting_r1(mpf_t& r1, mpf_t& s1)
{
    // setting r1

    mpf_t r1_temp; mpf_init(r1_temp);

    mpf_mul(r1_temp, s1, s1);			// r1_temp = s1*s1
    mpf_mul(r1_temp, r1_temp, s1);		// r1_temp = s1*s1*s1
    mpf_ui_sub(r1, 1, r1_temp);			// r1_temp = 1 - s1*s1*s1

    cube_root(r1);

}


int main()
{
    mpf_set_default_prec(BIT_COUNT*PRECISION);  // precision in bits

    // declare and initializinf variables

    mpf_t pi; mpf_init(pi);
    mpf_t a0; mpf_init(a0);
    mpf_t r0; mpf_init(r0);
    mpf_t s0; mpf_init(s0);
    mpf_t t1; mpf_init(t1);
    mpf_t u1; mpf_init(u1);
    mpf_t v1; mpf_init(v1);
    mpf_t w1; mpf_init(w1);
    mpf_t a1; mpf_init(a1);
    mpf_t s1; mpf_init(s1);
    mpf_t r1; mpf_init(r1);

    setting_a0(a0);
    setting_r0(r0);
    setting_s0(s0, r0);

    for (int n = 0 ; n < 4; n++)			// running loop to iterate as per Nonic Convergence algorithm
    {
    		setting_t1(t1,r0);
    		setting_u1(u1,r0);
    		setting_v1(v1,t1,u1);
    		setting_w1(w1,s0,v1);
    		setting_a1(a1,w1,n,a0);
    		setting_s1(s1,r0,u1,t1,v1);
    		setting_r1(r1,s1);

        // assigning values of variables1 to variables0

        mpf_set(a0, a1);
        mpf_set(r0, r1);
        mpf_set(s0, s1);

    }

    mpf_ui_div (pi, 1, a1);
/*
    	FILE *file3 = 0;
    	mpf_out_str(file3,10,1001,final);
*/
    size_t  n_digits = PRECISION;
    char *str = (char *) malloc(n_digits*sizeof(char));
    mp_exp_t exp ;
    mpf_get_str ( str ,&exp , BASE , n_digits , pi );		// copying pi value to a pointer str of type character array

    print_BigPi(str);									// printing PI value

    return 0;
}
