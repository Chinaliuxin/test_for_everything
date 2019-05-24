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
