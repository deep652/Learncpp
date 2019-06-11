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

//int main()
//{
//	int num, den;
//	cout << "Enter numertor and denominator" << endl;
//	cin >> num >> den;
//	try
//	{
//		Fraction f(num, den);
//		f.printFraction(); //incase of exception, normal flow will be distrub and printing of fraction will not occur
//	}
//	catch (int) //we can skip the variable decalration
//	{
//		cout << "Invalid denominator" << endl;
//	}
//	//catch (long int) //throwing a int will not catch with long int or any other variation of int. Strict type check is done for exception handling
//	//{
//	//	cout << "Invalid denominator from long" << endl;
//	//}
//
//	getchar();
//	getchar();
//    return 0;
//}

/*
check the order of executions. points need to remember:
1. if thrown an exception using throw keyword, program looks for a catck block. and if its not present where throw keyowrd is used to thrown
the exception then stack unwind thing happens. stack unwinds and check the caller for any matching catch block
2. In the process, till it find the matching catch block, it ignores the the statement in route.
3. once matching catch block founds, it exceutes the catch handler and normal program execution resume.
check the output of the above program

Imp** :
benifits from stack unwinding process is, it allows applications to handle the error as they desires, i.e. print the error on console, so send it to a file etc.
*/

void last() // called by third()
{
	std::cout << "Start last\n";
	std::cout << "last throwing int exception\n";
	throw - 1;
	std::cout << "End last\n";

}

void third() // called by second()
{
	std::cout << "Start third\n";
	last();
	std::cout << "End third\n";
}

void second() // called by first()
{
	std::cout << "Start second\n";
	try
	{
		third();
	}
	catch (double)
	{
		std::cerr << "second caught double exception\n";
	}
	std::cout << "End second\n";
}

void first() // called by main()
{
	std::cout << "Start first\n";
	try
	{
		second();
	}
	catch (int)
	{
		std::cerr << "first caught int exception\n";
	}
	catch (double)
	{
		std::cerr << "first caught double exception\n";
	}
	std::cout << "End first\n";
}

int main()
{
	std::cout << "Start main\n";
	try
	{
		first();
	}
	catch (int)
	{
		std::cerr << "main caught int exception\n";
	}
	std::cout << "End main\n";

	getchar();

	return 0;
}

