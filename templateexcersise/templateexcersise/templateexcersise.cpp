// templateexcersise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

template<class T1>
class Pair1
{
private:
	T1 m_d1;
	T1 m_d2;
public:
	Pair1(T1 t1, T1 t2):m_d1(t1),m_d2(t2){}
	 T1 first() const
	{
		return m_d1;
	}
	 T1 second() const
	{
		return m_d2;
	}

};

template<class T1,class T2>
class Pair
{
private:
	T1 m_d1;
	T2 m_d2;
public:
	Pair(T1 t1, T2 t2) :m_d1(t1), m_d2(t2) {}
	T1 first() const
	{
		return m_d1;
	}
	T2 second() const
	{
		return m_d2;
	}

};

template <class T>
class StringValuePair:public Pair<std::string,T>
{
private:
	//std::string m_str;
public:
	StringValuePair(std::string str,T t):Pair<string,T>(str,t){}
	/*char * first() const
	{	 
		 return m_d1.c_str();
	}*/
};
int main()
{
	/*Pair1<int> p1(5, 8);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(2.3, 4.5);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';*/

	Pair<int, double> p1(5, 6.7);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2(2.3, 4);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	StringValuePair<int> svp("Hello", 5);
	std::cout << "Pair: " << svp.first().c_str() << ' ' << svp.second() << '\n';


	getchar();
    return 0;
}

