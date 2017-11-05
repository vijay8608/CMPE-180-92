#include<iostream>
#include<sstream>
#include<string>

/*
 * Including calculator class which does the operations using member functions like expression, term and factor
 */
#include "Calculator.h"

using namespace std;

int main()
{
	Calculator cal;	// object of calculator class

	char c;
	string str;

	cout << "Expression?";

	//cin >> c;

	getline(cin,str);	// reading enterred expression in a string
	cal.ss << str;		// reading string to stringstream for operations
	cal.ss >> c;

	cal.set_inp(c);

	//cout << cal.get_inp();

	while ( c != '.')		// reading user input expressions untill '.' is entered
	{
		try								// checking for error
		{
			cout << cal.expression() <<endl;
		}
		catch(const char* s)				// catching error
		{
			cout << s << endl;
		}


		cout << "Expression?";

		//cin >> c;

		getline(cin,str);
		cal.ss.str("");
		cal.ss.clear();
		cal.ss << str;
		cal.ss >> c;

		cal.set_inp(c);

	}

	cout << "Done!"<<endl;


}
