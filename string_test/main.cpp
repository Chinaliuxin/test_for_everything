#include <iostream>
#include"string_test.hpp"
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
		cout << "����" << endl;
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
int testADD()
{
	string num1, num2;
	while (cin >> num1 >> num2)
	{
		my_main(num1, num2);
	}
	return  0;

}
void testShunxu()
{
	int a = 1, b = 0, c = 1, d = 0;
	d =((++b&&++c)||++a) ;
	int f = 11 && 11;
	cout << "����" << d<<'f'<<f;
}
void fun_kaoyan(int &time,int n)
{
	int x = 0;
	while ((x+1)*(x+1)<n)
	{
		time++;
		x += 1;
	}
}
int main()
{
	vector<int> sss(2,10);

	int time = 0;
	fun_kaoyan(time,1000000);
	cout << time;
	testload<int>::myoverload();
	testload<int> * p;
	p->myoverload();//static���������ж����еġ�
	string s("123");
	cout << s.substr(3);
	testStringDfs();
	testShunxu();
	//string s("224543");
	//vector<int	>v;
	//for (auto e : s)
	//{
	//	v.push_back(atoi(e));
	//}
	/*for(int i=0;i<v.size();i++)
	cout << v[i];*/
	testload<int> test;
	cout<<test.myoverload(1,2,3);
	bool ch[] = { true,false };
	cout << '\n'<<ch[0];
	testADD();
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