#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isfun(string s)
{
	int begin = 0;
	int end = s.size() - 1;
	while (begin < end)
	{
		if (s[begin++] == s[end--])
			;
		else
			return false;
	}
	return true;
}
void testmax()
{
	int a = 1;
	int b = 2;
	cout << max(a, b);
}
class A {
public:
	virtual void fun()
	{
		cout << "1" << endl;
	}
};
class B:public A {
public:
	virtual void fun()
	{
		cout << "×ÓÀà" << endl;
	}
};
static void  change(A a)
{
	a.fun();
}
void testduotai()
{
	//A *a=new A;
//B *b=new B;
	A a;
	B b;
	change(a);
	change(b);
	A* ptr = nullptr;
	ptr = &b;
	ptr->fun();
	cout << "eeeeeeeeeeeeeee" << endl;
	B* pB = &b;
	pB->fun();
}
int main()
{
	testduotai();
	string str1, str2;

	while (cin >> str1 >> str2)
	{
		int ret = 0;
		for (int i = 0; i <= str1.size(); i++)
		{
			string temp(str1);
			if (isfun(temp.insert(i, str2)))
				ret++;
		}
		cout << ret << endl;
	}
	return 0;
}