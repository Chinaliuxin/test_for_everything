#include<iostream>

using namespace std;
class A {
public:
	A(int set)
		:a(set) {
		cout << "A\n";
	}
	int a;
};
class  B :public A
{
public:
	B()
		:A(1)
	{
		cout << "¹¹ÔìB";
	}
	int fun()
	{
		return A::a;
	}
};
void testA()
{
	//A classA(1);
	//classA.a = 1;
	B b;
	cout << b.fun() << endl << b.a;
}
