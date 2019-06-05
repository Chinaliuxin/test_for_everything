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
#include <Windows.h>
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
/*
链接：https://www.nowcoder.com/questionTerminal/4284c8f466814870bae7799a07d49ec8
来源：牛客网

小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，
小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。
小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达
*/
int findMost(int num)
{
	for (int i = num-1; i>=1; i--)
	{
		if (num%i == 0)
			return i;
	}
}
void jumpStone(int N, int M)
{
	int ret = 0;
	int now = N;
	while (now<=M)
	{
		now+=findMost(now);
		ret++;
	}
	cout << ret << endl;

}