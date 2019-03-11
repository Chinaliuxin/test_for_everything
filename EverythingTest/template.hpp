#pragma once
#include<iostream>
using namespace std;

template<class T>
class A
{
public:
	A()
		:a(0)
	{
		cout << "初始的模板" << endl;
	}

	T a;
};

template<>
class A<int>
{
public:
	A()
		:a(0)
	{
		cout << "全特化" << endl;
	}
	int a;
};

void test_template()
{
	A<char> first;
	A<int> second;
}
