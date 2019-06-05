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
#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;
int ��������·()
{
	int n=1, m=2;
	while (	cin >> n >> m)
	{
		//int **dp=new int [n+1][m+1];
		n = n + 1;
		m = m + 1;
		vector<vector<int> > dp(m , vector<int>(n , 0));
		//d[i][j]=d[i-1][j]+d[i][j-1];
		for (int i = 0; i <n; i++)//�����,n
		{
			dp[0][i] = 1;
		}
		for (int i = 0; i < m; i++)//�����,m
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
���ӣ�https://www.nowcoder.com/questionTerminal/4284c8f466814870bae7799a07d49ec8
��Դ��ţ����

С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬
С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����������K+X(XΪK��һ����1�ͱ����Լ��)��λ�á�
С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե���
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