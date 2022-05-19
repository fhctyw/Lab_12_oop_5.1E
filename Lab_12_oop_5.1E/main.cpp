#include <iostream>
#include "Rational.h"
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	try {

		Rational r(3, 0);
	}
	catch (MyException* e)
	{
		cout << "MyException* " << e->What() << endl;
	}
	
	try
	{
		Rational r(4, 4);
		r.setB(0);
	}
	catch (RationalException e)
	{
		cout << "RationalException " << e.what() << endl;
	}

	try
	{
		Rational r;
		cin >> r;
	}
	catch (exception& e)
	{
		cout << "exception& " << e.what() << endl;
	}

	return 0;
}