#include <iostream>
#include<cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include<stack>
#include<map>
using namespace std;
int quickSortPart(int a[], int left, int right)
{
	int temp = a[right];
	while (left < right)
	{
		while (left < right&&a[left] < temp)
		{
			left++;
		}
		a[right] = a[left];
		while (left < right&&a[right] >= temp)
		{
			right--;
		}
		a[left] = a[right];
	}
	a[right] = temp;
	return right;
}
void quickSort_(int a[], int left, int right)
{
	if (left < right)
	{
		int mid = quickSortPart(a, left, right);
		quickSort_(a, left, mid - 1);
		quickSort_(a, mid + 1, right);
	}
}


#include<vector>
class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		// write code here
		vector<int> ret;
		for (int k = 0; k <= n - 1; k++)//k是size
		{
			int max1 = 0x80000000;
			int max2 = 0x80000000;
			for (int i = 0; i < k; i++)
			{
				if (A[i] > max1)
					max1 = A[i];
			}
			for (int i = k; i <= n - 1; i++)
			{
				if (A[i] > max2)
					max2 = A[i];
			}
			int r = max1 > max2 ? max1 - max2 : max2 - max1;
			ret.push_back(r);

		}
		int returnIt = ret[0];
		for (auto e : ret)
		{
			returnIt = e > returnIt ? e : returnIt;
		}
		return returnIt;
	}
	};

const char* myStrStr( const char * str,const char* des)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		int j = 0;
		int temp = i;
		if (str[i] == des[j])
		{
			while (str[i] == des[j])
			{
				i++;
				j++;
				if (des[j] == '\0')
					return &str[i - j];
			}
		}
		i = temp;
	}
	return nullptr;
}
//int main()
//{
//	MaxGap s;
//	vector<int > a = { 2,7,3,1,1 };
//	//cout<<s.findMaxGap(a, a.size());
//	int cc = INT_MIN;//0x80000000
//	char str[]="fff12312361234512345612343";
//	char des[]= "123456";
//	const char * hh = myStrStr(str, des);
//	printf("%p\n", myStrStr(str, des));
//	printf("%p\n", strstr(str, des));
//
//	printf("%s", hh);
//	printf("%s\n", strstr(str, des));
//
//	int b = 0x80000000;
//	printf("%d", b);
//
//
//	return 0;
//}
//int main()
//{
//	MaxGap s;
//	vector<int > a = { 2,7,3,1,1 };
//	//cout<<s.findMaxGap(a, a.size());
//	int cc = INT_MIN;//0x80000000
//	char str[]="fff12312361234512345612343";
//	char des[]= "123456";
//	const char * hh = myStrStr(str, des);
//	printf("%p\n", myStrStr(str, des));
//	printf("%p\n", strstr(str, des));
//
//	printf("%s", hh);
//	printf("%s\n", strstr(str, des));
//
//	int b = 0x80000000;
//	printf("%d", b);
//
//
//	return 0;
//}
#include<iostream>
#include <string>
using namespace std;
bool fun(int n)
{
	long ret = n * n;
	string str = to_string(ret);
	int i = 0;
	int j = str.size() - 1;
	for (; i < j; i++, j--)
	{
		if (str[i] != str[j])
		{
			return false;
		}
	}
	return true;
}
namespace minStack {
	class Solution {
	private:
		stack<int> s1;
		stack<int> s2;
	public:
		void push(int value) {
			s1.push(value);
			if (s2.empty() == 1 || value <= s2.top())
			{
				s2.push(value);
			}
		}
		void pop() {
			if (s1.empty() == 1)
				return;
			if (s1.top() == s2.top())
				s2.pop();
			s1.pop();
		}
		int top() {
			return s1.top();
		}
		int min() {
			return s2.top();
		}
	};
}
void adjustHeap(int a[], int i, int size)
{
	//int max;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int max = i;
	//vs 2017 会检测&&右边的，故不能将l < size&& a[l] > a[max]书写
	if (l < size) {
		if (a[l] > a[max])
			max = l;
	}
	if (r < size) {
		if (a[r] > a[max])
			max = r;
	}
	if (max != i)
	{
		::std::swap(a[i], a[max]);
		adjustHeap(a, max, size);
	}
}

void heapSort(int a[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		adjustHeap(a, i, size);
	}
	for (int i = size - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		adjustHeap(a, 0, i);
	}
}

void fun(string & str)//时钟
{
	//12:12:12
	int h = atoi(str.substr(0, 2).c_str());
	int m = atoi(str.substr(3, 2).c_str());
	int s = atoi(str.substr(6, 2).c_str());
	if (h > 23)
	{
		h = h % 10;//30-00
	}
	if (m > 59)
	{
		m = m % 10;
	}
	if (s > 59)
	{
		s = s % 10;
	}
	if (h < 10)
		cout << 0;
	cout << h << ":";
	if (m < 10)
		cout << 0;
	cout << m << ":";
	if (s < 10)
		cout << 0;
	cout << s << endl;
}
int a[0x7ffffff];


//int  main()
//{
//	static int adsfsd[100000000];
//	int num;
//	cin >> num;
//	while (num--)
//	{
//		string str;
//		cin >> str;
//		fun(str);
//	}
//
//	string ssss="12:34:56";
//	int h=atoi(ssss.substr(0, 2).c_str());
//	int m = atoi(ssss.substr(3, 2).c_str());
//	int s = atoi(ssss.substr(6, 2).c_str());
//	cout << h << m << s;
//	int a[] = { 5,11,7,2,3,17 };
//	int size = 6;
//	for (int i = size / 2 - 1; i >= 0; i--)
//	{
//		adjustHeap(a, i, size);
//	}
//	for (int  e : a)
//	{
//		cout << e;
//	}
//	map<int,int> hash;
//	map<int, int>::iterator it = hash.begin();
//	pair<int, int> d(1, 2);
//	hash.insert(d);
//	for (auto e : hash)
//	{
//		cout << e.first;
//	}
//
//}
int flag=0;
#define   PAIR  pair<int,int>
template<class T=PAIR>
struct fun_cmp {
	bool operator()(const T a, const T b)const 
	{
		bool ret = a.first > b.first || (a.first == b.first && a.second > b.second);
		if (ret == true)
			flag ++;
		return ret;
	}
};
template<class T>
struct Big {
	bool operator()(const T a, const T b)const
	{
		return a>b;
	}
};
template<class K>
void mysort(vector<PAIR> & num,const K &cmp)
{
	int size = num.size();
	for (int i = 0; i <= size-2; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (cmp(num[j],num[j+1]))
				swap(num[j], num[j + 1]);
		}
	}
}

using namespace std;
int main()
{
	vector<PAIR> v;
	PAIR p[] = { {2,4},{1,7}, {1, 2},{1,3},{1,-4},{2,7},{2,9} };
	for (int i = 0; i < sizeof(p) / sizeof(p[0]); i++)
	{
		v.push_back(p[i]);
	}
	p[0].first;
	mysort(v, fun_cmp<PAIR>());
	for (auto e : v)
	{
		printf("{%d,%d}  ", e.first, e.second);
	}
	cout << flag;

}

