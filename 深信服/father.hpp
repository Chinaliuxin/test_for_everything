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
	virtual void func() { cout << val<<"调用A" ;		printf("       %p\n", this);
	}
	void test() { func(); }
};
class B :public A {
public:
	B() { test(); }
	void func()
	{
		val++;
		cout << val << "调用B";
		printf("%p\n", this);
	}
};

void testAandB()
{
	B b;
	A*p = &b;
	p->test();
}
#include <iostream>
#include <vector>
using namespace std;
int 机器人走路()
{
	int n=1, m=2;
	while (	cin >> n >> m)
	{
		//int **dp=new int [n+1][m+1];
		n = n + 1;
		m = m + 1;
		vector<vector<int> > dp(m , vector<int>(n , 0));
		//d[i][j]=d[i-1][j]+d[i][j-1];
		for (int i = 0; i <n; i++)//行填充,n
		{
			dp[0][i] = 1;
		}
		for (int i = 0; i < m; i++)//列填充,m
		{
			dp[i][0] = 1;
		}
		
		for (int i = 1; i <m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		cout << dp[m-1][n-1] << endl;
	}
	return 0;
}