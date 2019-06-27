#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
//最长数字串
void fun_maxlennum(string str)
{
	int maxlen = 0;
	string ret;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			maxlen++;
			if (maxlen > ret.size())
			{
				ret.clear();
				ret = str.substr(i - maxlen + 1, maxlen);
			}
		}
		else
		{
			maxlen = 0;
		}

	}
	cout << ret << endl;
}
typedef int(*mypoint)(int);
static int fun1(int num)
{
	printf("打印fun\n");
	return num;
}
static int fun2(int num)
{
	printf("不打印fun\n");
	return num;
}
void test_fun(mypoint p)
{
	p(11);
}
void test(int com)
{
	//int(*pfun)(int);
	mypoint pfun;
	if (com > 1)
	{
		pfun = &fun1;
		test_fun(fun1);
	}
	else
	{
		pfun = fun2;
	}
	test_fun(pfun);
}
#include <algorithm>
#include<vector>
int main()
{
	vector<int> v = { 1,-1,0 };
	sort(v.begin(), v.end(), [](int a, int b)->bool {return a > b; });
	char a[3],b[3];
	char const* p = a;
	p = b+1;
	test(-1);
	//test_fun(fun1);
	//test_fun(fun2);
	return 0;

}