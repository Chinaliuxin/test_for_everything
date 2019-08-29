#include<iostream>
#include "fun.h"
#include <vector>
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
		cout << "构造B";
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

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n == 0)
			return;
		// nums1.resize(n+m);
		int i = m - 1;
		int j = n - 1;
		int k = m + n - 1;
		while (k >= 0)
		{
			if (i >= 0 && j >= 0)
			{
				if (nums1[i] >= nums2[j])
				{
					nums1[k--] = nums1[i--];
				}
				else
				{
					nums1[k--] = nums2[j--];
				}
			}
			else {
				if (i >= 0 && j < 0)
				{
					nums1[k--] = nums1[i--];
				}
				else if (i < 0 && j >= 0)
				{
					nums1[k--] = nums2[j--];
				}
			}

		}
	}
};
void testMerge()
{
	vector<int > a = { 1,4,5,7,0,0,0,0 };
	vector<int > b = { 0,4,6,9 };
	int size_b = b.size() - 1;
	int size_a = a.size() - b.size() - 1;
	int temp = a.size() - 1;
	int & i = size_a;
	int & j = size_b;
	while (temp >= 0)
	{
		if (i >= 0 && j >= 0)
		{
			if (a[i] > a[j])
				a[temp--] = a[i--];
			else
				a[temp--] = b[j--];
		}
		else {
			if (i >= 0 && j < 0)
			{
				a[temp--] = a[i--];
			}
			else if (i < 0 && j >= 0)
			{
				a[temp--] = b[j--];
			}
		}
	}
	for (auto e : a)
	{
		cout << e << ':';
	}
	cout << '\n';
}


#include<iostream>
using namespace std;
int value[4] = { 0,1,3,5 };
int main()/*我们要对它抽象一下，
d(i) = min{ d(i - vj) + 1 }，其中i - vj >= 0，vj表示第j个硬币的面值;
有了状态和状态转移方程，这个问题基本上也就解决了*/
{
	int min[12];
	for (int i = 0; i < 12; i++)
		min[i] = 100;
	min[0] = 0;
	for (int i = 0; i < 12; i++)
		for (int j = 1; j < 4; j++)
			if (value[j] <= i && min[i - value[j]] + 1 < min[i])
				min[i] = min[i - value[j]] + 1;
	for (int i = 0; i < 12; i++)
		cout << min[i] << ' ';

	return 0;
}