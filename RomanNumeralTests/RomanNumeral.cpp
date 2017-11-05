#include <iostream>
#include <string>
#include "RomanNumeral.h"
using namespace std;

/*
 * Default constructor
 */
RomanNumeral::RomanNumeral() : roman(""), decimal(0) {}

/*
 * Constructor with integer parameter
 * @param d Decimal integer number
 */
RomanNumeral::RomanNumeral(int d) : decimal(d)
{
	to_roman(d);
}

/*
 * Constructor with roman number paramter
 * @param r String roman number
 */
RomanNumeral::RomanNumeral(string r) : roman(r)
{
	to_decimal(r);
}

/*
 * Getter method to get integer equivalent of number
 */
int RomanNumeral::get_decimal() const { return decimal; }

/*
 * Getter method to get roman number
 */
string RomanNumeral::get_roman() const { return roman; }

/*
 * Setter method to set integer value of an equivalent roman number
 */
void RomanNumeral::set_decimal( int d) { decimal = d ;}

/*
 * Setter method to set string - roman number for quivalent integer number
 */
void RomanNumeral::set_roman( string r) { roman = r ;}

/*
 * Operator overloading "+"
 */
int operator +(const RomanNumeral& r1, const RomanNumeral& r2)
{
	return (r1.decimal + r2.decimal);
}

/*
 * Operator overloading "-"
 */

int operator -(const RomanNumeral& r1, const RomanNumeral& r2)
{
	return abs(r1.decimal - r2.decimal);
}


/*
 * Operator overloading "*"
 */
int operator *(const RomanNumeral& r1, const RomanNumeral& r2)
{
	return (r1.decimal * r2.decimal);
}


/*
 * Operator overloading "/"
 */
int operator /(const RomanNumeral& r1, const RomanNumeral& r2)
{
	return (r1.decimal / r2.decimal);
}

/*
 * Operator overloading "=="
 */
bool operator == (const RomanNumeral& r1, const RomanNumeral& r2)
{
	if (r1.decimal == r2.decimal)
		return true;
	else
		return false;
}

/*
 * Operator overloading "!="
 */
bool operator != (const RomanNumeral& r1, const RomanNumeral& r2)
{
	if (r1.decimal != r2.decimal)
		return true;
	else
		return false;
}

/*
 * Convert integer to equivalent roman number
 */
void RomanNumeral::to_roman( int d)
{

	char temp[50] = {0};

	for (int i = 0 ; i < 40 ; i++)
	{
		if ( d >= 1000)
		{
			temp[i] = 'M';
			d = d - 1000;

		}
		else if ( d >= 900)
		{
			temp[i] = 'C';
			temp[i+1] = 'M';
			d = d - 900;
			i++;

		}
		else if ( d >= 500)
		{
			temp[i] = 'D';
			d = d - 500;

		}
		else if ( d >= 400)
		{
			temp[i] = 'C';
			temp[i+1] = 'D';
			d = d - 400;
			i++;

		}
		else if ( d >= 100)
		{
			temp[i] = 'C';
			d = d - 100;

		}
		else if ( d >= 90)
		{
			temp[i] = 'X';
			temp[i+1] = 'C';
			d = d - 90;
			i++;

		}
		else if ( d >= 50)
		{
			temp[i] = 'L';
			d = d - 50;

		}
		else if ( d >= 40)
		{
			temp[i] = 'X';
			temp[i+1] = 'L';
			d = d - 40;
			i++;

		}
		else if ( d >= 10)
		{
			temp[i] = 'X';
			d = d - 10;

		}
		else if ( d >= 9)
		{
			temp[i] = 'I';
			temp[i+1] = 'X';
			d = d - 9;
			i++;

		}
		else if ( d >= 5)
		{
			temp[i] = 'V';
			d = d - 5;

		}
		else if ( d >= 4)
		{
			temp[i] = 'I';
			temp[i+1] = 'V';
			d = d - 4;
			i++;

		}
		else if ( d >= 1)
		{
			temp[i] = 'I';
			d = d - 1;

		}

		if (d == 0)
			break;
	}

	string p = temp;
	RomanNumeral::set_roman(p);

}

/*
 * Convert roman to quivalent decimal number
 */
void RomanNumeral::to_decimal( string r)
{
	int total = 0;

	for (int i = 0 ; i < r.length() ; i++)
	{
		if (r[i] == 'M')
		{
			total = total + 1000;
		}
		else if( r[i] == 'C')
		{
			if ( (i+1) <= r.length())
			{
				switch(r[i+1]){
				case 'D':
					total = total + 400;
					i++;
					break;
				case 'M':
					total = total + 900;
					i++;
					break;
				default:
					total = total + 100;
				}


			}
		}
		else if(r[i] == 'D') {total = total + 500;}
		else if (r[i] == 'X')
		{
			if ( (i+1) <= r.length())
			{
				switch(r[i+1]){
				case 'L':
					total = total + 40;
					i++;
					break;
				case 'C':
					total = total + 90;
					i++;
					break;
				default:
					total = total + 10;
				}

			}
		}
		else if (r[i] == 'L') {total = total + 50;}
		else if (r[i] == 'I')
		{
			if ( (i+1) <= r.length())
			{
				switch(r[i+1]){
				case 'V':
					total = total + 4;
					i++;
					break;
				case 'X':
					total = total + 9;
					i++;
					break;
				default:
					total = total + 1;
				}

			}
		}
		else if (r[i] == 'V') {total = total + 5;}
	}

	RomanNumeral::set_decimal(total);
}

/*
 * Operator overloading "<<"
 */
ostream& operator << ( ostream& outs, RomanNumeral& rom)
{
	outs << "[" << rom.decimal << ":" << rom.roman  << "]";
	return outs;
}

/*
 * Operator overloading ">>"
 */
istream& operator >> ( istream& in, RomanNumeral& rom)
{
	in >> rom.roman;
	rom.to_decimal(rom.roman);
	return in;
}




