#include "Calculator.h"

int Calculator::parenthesis_open = 0;
int Calculator::parenthesis_close = 0;


Calculator::Calculator()
{
	//outputf = 0;
	//outputt = 0;
	outpute = 0;
	inp = 0;
}

Calculator::~Calculator(){}

double Calculator::expression()
{
	outpute = term();
	//cout << outpute << endl;

	//if ( !ss.eof())
	while(!ss.eof())
	{
		char c;
		ss >> c;

		if (c == '+')
		{
			double temp;
			temp = term();
			outpute = outpute + temp;
		}
		else if (c == '-')
		{
			double temp;
			temp = term();
			outpute = outpute - temp;
		}
		else if ( c == '*')
		{
			ss.unget();
			outpute = term();
		}
		else if ( c == '/')
		{
			ss.unget();
			outpute = term();
		}
	}


	return outpute;
}


double Calculator::term()
{
	double outputt = factor();

	//if ( !ss.eof())
	while(!ss.eof())
	{
		char c;

		ss >> c;

		//cout << c << endl;

		if ( c == '*')
		{
			//ss >> c;
			double temp;
			//cout << "before "<< output << endl;
			temp = factor();
			//cout << " temp"<< temp<<endl;
			//cout << " output" << output << endl;
			outputt = outputt*temp;
			//cout << "result"<< output <<endl;

		}
		else if (c == '/')
		{
			double temp;
			temp = factor();
			if (temp != 0 )
			{
				outputt = outputt / temp;
			}
			else
			{
				throw  "***** Division by zero";
				//cout << "error - divide by zero" << endl;
			}

		}
		else if (c == '+')
		{
			ss.unget();
			//outputt = expression();
			return outputt;
		}
		else if (c == '-')
		{
			ss.unget();
			//outputt = expression();
			return outputt;
		}
		else if ( c == '%')
		{
			cout << outputt << endl;
			throw "***** Unexpected %";

		}

	}

	return outputt;

}

double Calculator::factor()
{
	char c;
	double outputf = 0;

	if (this->get_inp())
	{
		c = this->get_inp();
		this->set_inp(0);
	}
	else
	{
		ss >> c;
		//cout << c  << "this is me "<< endl;
	}

	if ( c >= '0' && c <='9')
	{
		ss.unget();
		ss >> outputf;
		//cout << "after "<< output << endl;
		return outputf;
	}
	else if ( c == '(')
	{
		//parenthesis_open++;
		outputf = expression();

	}


	return outputf;
}



