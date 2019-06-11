// excetionexcerscise.cpp : Defines the entry point for the console application.

/*Write a Fraction class that has a constructor that takes a numerator and a denominator.
If the user passes in a denominator of 0, throw an exception of type std::runtime_error(included in the stdexcept header).
In your main program, ask the user to enter two integers.If the Fraction is valid, 
print the fraction.If the Fraction is invalid, catch a std::exception, and tell the user that they entered an invalid fraction.
*/ 
//

#include "stdafx.h"
#include<iostream>

using namespace std;

class Fraction
{
private:
	int m_num;
	int m_den;
public:
	Fraction(int num, int den) :m_num(num), m_den(den)
	{
		if (den == 0)
			{
				throw 0;
			}
	}
	Fraction():m_num(0),m_den(1){}
	void printFraction()
	{
		cout << "Fraction is: "<<m_num<<"/"<<m_den << endl;
	}

};

int main()
{
	int num, den;
	cout << "Enter numertor and denominator" << endl;
	cin >> num >> den;
	try
	{
		Fraction f(num, den);
		f.printFraction(); //incase of exception, normal flow will be distrub and printing of fraction will not occur
	}
	catch (int) //we can skip the variable decalration
	{
		cout << "Invalid denominator" << endl;
	}
	//catch (long int) //throwing a int will not catch with long int or any other variation of int. Strict type check is done for exception handling
	//{
	//	cout << "Invalid denominator from long" << endl;
	//}

	getchar();
	getchar();
    return 0;
}

