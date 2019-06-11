//// excetionexcerscise.cpp : Defines the entry point for the console application.
//
///*Write a Fraction class that has a constructor that takes a numerator and a denominator.
//If the user passes in a denominator of 0, throw an exception of type std::runtime_error(included in the stdexcept header).
//In your main program, ask the user to enter two integers.If the Fraction is valid, 
//print the fraction.If the Fraction is invalid, catch a std::exception, and tell the user that they entered an invalid fraction.
//*/ 
////
//
//#include "stdafx.h"
//#include<iostream>
//
//using namespace std;
//
//class Fraction
//{
//private:
//	int m_num;
//	int m_den;
//public:
//	Fraction(int num, int den) :m_num(num), m_den(den)
//	{
//		if (den == 0)
//			{
//				throw 0;
//			}
//	}
//	Fraction():m_num(0),m_den(1){}
//	void printFraction()
//	{
//		cout << "Fraction is: "<<m_num<<"/"<<m_den << endl;
//	}
//
//};
//
////int main()
////{
////	int num, den;
////	cout << "Enter numertor and denominator" << endl;
////	cin >> num >> den;
////	try
////	{
////		Fraction f(num, den);
////		f.printFraction(); //incase of exception, normal flow will be distrub and printing of fraction will not occur
////	}
////	catch (int) //we can skip the variable decalration
////	{
////		cout << "Invalid denominator" << endl;
////	}
////	//catch (long int) //throwing a int will not catch with long int or any other variation of int. Strict type check is done for exception handling
////	//{
////	//	cout << "Invalid denominator from long" << endl;
////	//}
////
////	getchar();
////	getchar();
////    return 0;
////}
//
///*
//check the order of executions. points need to remember:
//1. if thrown an exception using throw keyword, program looks for a catck block. and if its not present where throw keyowrd is used to thrown
//the exception then stack unwind thing happens. stack unwinds and check the caller for any matching catch block
//2. In the process, till it find the matching catch block, it ignores the the statement in route.
//3. once matching catch block founds, it exceutes the catch handler and normal program execution resume.
//check the output of the above program
//
//Imp** :
//benifits from stack unwinding process is, it allows applications to handle the error as they desires, i.e. print the error on console, so send it to a file etc.
//*/
//
//void last() // called by third()
//{
//	std::cout << "Start last\n";
//	std::cout << "last throwing int exception\n";
//	throw - 1;
//	std::cout << "End last\n";
//
//}
//
//void third() // called by second()
//{
//	std::cout << "Start third\n";
//	last();
//	std::cout << "End third\n";
//}
//
//void second() // called by first()
//{
//	std::cout << "Start second\n";
//	try
//	{
//		third();
//	}
//	catch (double)
//	{
//		std::cerr << "second caught double exception\n";
//	}
//	std::cout << "End second\n";
//}
//
//void first() // called by main()
//{
//	std::cout << "Start first\n";
//	try
//	{
//		second();
//	}
//	catch (int)
//	{
//		std::cerr << "first caught int exception\n";
//	}
//	catch (double)
//	{
//		std::cerr << "first caught double exception\n";
//	}
//	std::cout << "End first\n";
//}
//
////int main()
////{
////	std::cout << "Start main\n";
////	try
////	{
////		first();
////	}
////	catch (int)
////	{
////		std::cerr << "main caught int exception\n";
////	}
////	std::cout << "End main\n";
////
////	getchar();
////
////	return 0;
////}
//
////catch all handlers: because everytime we don't know type of error trown by a method
////benifits: specially it helps to do windup fnctionalitly, suppose there a method which have thrown an error and the caller was suppose to handel the
////error. But unfortuan;ity there is no such catch block, so ultimately the stack will check the main for catch handler
//// if not found it will close the appication, but if we have catch alldefined in the main, it gives us chance to save the the program stage,
////or close the open files etc
//
////int main()
////{
////	try
////	{
////		throw - 1;
////	}
////	catch (double)
////	{ }
////	catch (...)
////	{
////		cout << "Catch all handler" << endl;
////	}
////	getchar();
////	return 0;
////}
//
///*
//Dynamic eception specifier and noexcept
//*/
//
////Dynamic eception specifier : depreciated in c++ 11, will be removed from c++17
//void randomFunction() throw(){} //will not throw any exception
//void randomFunction1() throw(int) {} //will throw int exception
//void randomFunction3() throw(...){} //may throw anything
//
////noexcept : says fuction may throw an exception
//
//void randomfunction()noexcept{}
//
////int main()
////{
////	try
////	{
////		throw - 1;
////	}
////	catch (double)
////	{
////	}
////	catch (...)
////	{
////		cout << "Catch all handler" << endl;
////	}
////	getchar();
////	return 0;
////}
//
///*
//Exception classes and inheritance
//*/
//
//// 1.exception in constructor, must clean up themselves before throwing the exception, as if constructor fails thorwing the exception, object never instanciated
//// and so you can't rely on destructor for cleaning the resouce
///*
//2. Destructor can never thorw an exception
//
//*/
//
//class Member
//{
//public:
//	Member()
//	{
//		cout << "Constructor of Member class" << endl;
//	}
//	~Member()
//	{
//		cout << "Destructor of Member class" << endl;
//	}
//};
//
//class A
//{
//	Member m;
//public:
//	A()
//	{
//		throw 1;
//	}
//	~A()
//	{
//		cout<<"Destructor of A"<<endl; //this will never called
//	}
//};
//int main()
//{
//	try
//	{
//		A a;
//	}
//	catch (int)
//	{
//		cout << "Construction of A Failed" << endl;
//	}
//	getchar();
//	return 0;
//}

//what is Exception class
#include "stdafx.h"
#include<iostream>

using namespace std;

//class ArrayOutOfBound
//{
//
//};
//
//class A
//{
//private:
//	int m[10];
//public:
//	void get(int index)
//	{
//		if (index < 0 || index >= 10)
//		{
//			throw ArrayOutOfBound();
//		}
//	}
//	void put(int index)
//	{
//		if (index < 0 || index >= 10)
//		{
//			throw ArrayOutOfBound();
//		}
//	}
//	int& operator [](int index)
//	{
//		if (index < 0 || index >= 10)
//		{
//			throw ArrayOutOfBound();
//		}
//		return m[index];
//	}
//};
//
//int main()
//{
//	try
//	{
//		A a;
//		a[1] = 1;
//		cout << a[1]<<endl;
//		a[-1] = 3;
//		cout << a[-1];
//	}
//	catch (ArrayOutOfBound &e)
//	{
//		cout << "Invalid Index" << endl;
//	}
//	getchar();
//	return 0;
//}

//Exception class and inheritance: one rule to rmember: always catch dervied object first as Dervied is Base and if
//the Base catch is before the Dervied then Dervied catch may never execute

//throwing Exception class directly

//int main()
//{
//	try
//	{
//		throw std::runtime_error("Bad things happened"); 
//	}
//	// This handler will catch std::exception and all the derived exceptions too
//	catch (std::exception &exception)
//	{
//		std::cerr << "Standard exception: " << exception.what() << '\n';
//	}
//
//	return 0;
//}

//**list down all std runtime exception with cpp

//Derving from Exception class

/*
Need few things to do:
1. check your requirement
2. check how to override what method
3. check how to use what method
*/

/*
Answers:
1. your class will dervied the Exception class
2. For example take ArrayOutOfBound Exception. you will have to check and give Array index out of bound if true
3. the what method signature is 	const char* what() const { return m_error.c_str(); } // pre-C++11 version
	const char* what() const noexcept { return m_error.c_str(); } // C++11 version
4. ofcourse the rreturn part need to be handled and you should return member m_error of you ArrayOutOfIndex class
*/
#include<string>

class ArrayOutOfBound :public std::exception
{
private:
	string m_error;
public:
	const char* what() const noexcept 
	{
		return m_error.c_str();
	}
	ArrayOutOfBound(string error) :m_error(error){}
	ArrayOutOfBound(){}
};

class A
{
	int m[10];
public:
	int& operator[](int index)
	{
		if (index < 0 || index >= 10)
			throw ArrayOutOfBound("Invalid Index");
		return m[index];
	}
};

int main()
{
	A a;
	try {
		a[-1] = 15;
	}
	catch (ArrayOutOfBound &e)
	{
		cout << e.what() << endl;
	}
	catch (exception &e) // if filps the order of catch then always first will exception catch will get caught
	{
		cout << "Some other error occured.."<<endl;
	}
	
	getchar();
	return 0;
}

//Last thing which is remaining is : how to rethrow the exception and that too in right way:
//write the code for it

