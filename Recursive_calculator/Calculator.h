#include <iostream>
#include <string>
#include <sstream>
#ifndef CALCULATOR_H_
#define CALCULATOR_H_


using namespace std;



class Calculator {
public:
	/*
	 * constructor of calculator class
	 */
	Calculator();

	/*
	 * destructor of calculator class
	 */
	virtual ~Calculator();

	/*
	 *expression function which calls factor function and does '+' and '-' operations
	 */
	double expression();

	/*
	 * factor function which calls term function and does '*' and '/' operations
	 */
	double factor();

	/*
	 * term function does most of the part of checking each character and doing the neccesary operations and calling expression function of seeing parenthesis
	 */
	double term();

	//double get_output(){return output;}
	void set_inp(char temp){inp = temp;}
	char get_inp(){return inp;}

	/*
	 * stringstream has the user entered expresion and gives it to char c as per need.
	 */
	stringstream ss;

	static int parenthesis_open;
	static int parenthesis_close;

private:
	//double outputf;
	//double outputt;
	double outpute;
	char inp;

};

#endif
