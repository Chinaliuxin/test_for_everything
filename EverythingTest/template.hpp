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
