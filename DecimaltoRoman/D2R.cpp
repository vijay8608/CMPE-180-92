#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	int d;
	cin >> d ;

	char temp[20];

	for (int i = 0 ; i < 40 ; i++)
	{
		if ( d >= 1000)
		{
			temp[i] = 'M';
			d = d - 1000;
			//continue;
		}
		else if ( d >= 900)
		{
			temp[i] = 'C';
			temp[i+1] = 'M';
			d = d - 900;
			i++;
			//continue;
		}
		else if ( d >= 500)
		{
			temp[i] = 'D';
			d = d - 500;
			//continue;
		}
		else if ( d >= 400)
		{
			temp[i] = 'C';
			temp[i+1] = 'D';
			d = d - 400;
			i++;
		//	continue;
		}
		else if ( d >= 100)
		{
			temp[i] = 'C';
			d = d - 100;
			//continue;
		}
		else if ( d >= 90)
		{
			temp[i] = 'X';
			temp[i+1] = 'C';
			d = d - 90;
			i++;
		//	continue;
		}
		else if ( d >= 50)
		{
			temp[i] = 'L';
			d = d - 50;
		//	continue;
		}
		else if ( d >= 40)
		{
			temp[i] = 'X';
			temp[i+1] = 'L';
			d = d - 40;
			i++;
		//	continue;
		}
		else if ( d >= 10)
		{
			temp[i] = 'X';
			d = d - 10;
		//	continue;
		}
		else if ( d >= 9)
		{
			temp[i] = 'I';
			temp[i+1] = 'X';
			d = d - 9;
			i++;
		//	continue;
		}
		else if ( d >= 5)
		{
			temp[i] = 'V';
			d = d - 5;
		//	continue;
		}
		else if ( d >= 4)
		{
			temp[i] = 'I';
			temp[i+1] = 'V';
			d = d - 4;
			i++;
	//		continue;
		}
		else if ( d >= 1)
		{
			temp[i] = 'I';
			d = d - 1;
	//		continue;
		}

		if (d == 0)
			break;
	}

	cout << temp;




}
