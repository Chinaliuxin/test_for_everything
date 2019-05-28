#pragma once
#include <iostream>
using namespace std;
class A
{
public:
	int val;
public:
	A()
		:val(0)
	{
		test();
	}
	virtual void func() { cout << val<<"����A" ;		printf("       %p\n", this);
	}
	void test() { func(); }
};
class B :public A {
public:
	B() { test(); }
	void func()
	{
		val++;
		cout << val << "����B";
		printf("%p\n", this);
	}
};

void testAandB()
{
	B b;
	A*p = &b;
	p->test();
}