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
		cout << "��ʼ��ģ��" << endl;
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
		cout << "ȫ�ػ�" << endl;
	}
	int a;
};

void test_template()
{
	A<char> first;
	A<int> second;
}

struct union1
{

	union 
	{
		int a;
		union
		{
			int b;
			int c;
		};
	};
	int aaa;
	//char aa;
};
struct union2
{
	int a1;
	int b2;
};