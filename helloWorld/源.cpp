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

const char* myStrStr(const char * str, const char* des)
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
int flag = 0;
#define   PAIR  pair<int,int>
template<class T = PAIR>
struct fun_cmp {
	bool operator()(const T a, const T b)const
	{
		bool ret = a.first > b.first || (a.first == b.first && a.second > b.second);
		if (ret == true)
			flag++;
		return ret;
	}
};
template<class T>
struct Big {
	bool operator()(const T a, const T b)const
	{
		return a > b;
	}
};

template<class T = vector<PAIR>, class K>
void mysort(T & num, const K &cmp)
{
	int size = num.size();
	for (int i = 0; i <= size - 2; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (cmp(num[j], num[j + 1]))
				swap(num[j], num[j + 1]);
		}
	}
}
struct myvalue
{
	int a;
	int b;
	int c;
	int d;
};
void testMyvalue()
{
	class fun_value {
	public:
		bool operator()(myvalue first, myvalue second)const
		{
			bool ret = false;
			if (first.a == second.a)
			{
				if (first.b == second.b)
				{
					if (first.c == second.c)
					{
						if (first.d == second.d)
						{
							return first.d > second.d;
						}
					}
					else
					{
						return first.c > second.c;
					}
				}
				else
				{
					return first.b > second.b;
				}
			}
			else
			{
				return first.a > second.a;
			}
			return ret;
		}

	};
	//自定义排序
	vector<myvalue> test;
	myvalue val[] = { {12,344,-6,-1}, {12,344,3,4},{12,344,2,6},{-22,2,-1,4},{24,243,43,4},{34,24,4,24},{12,344,3,4} };
	for (int i = 0; i < sizeof(val) / sizeof(val[0]); i++)
	{
		test.push_back(val[i]);
	}
	//mysort/*<vector<myvalue>>*/(test, fun_value());//自动推导类型
	mysort(test, [](const myvalue first, const myvalue second)->bool
	{
		if (first.a == second.a)
		{
			if (first.b == second.b)
			{
				if (first.c == second.c)
				{
					if (first.d == second.d)
					{
						return first.d > second.d;
					}
				}
				else
				{
					return first.c > second.c;
				}
			}
			else
			{
				return first.b > second.b;
			}
		}
		else
		{
			return first.a > second.a;
		}
	}
	);
	for (auto e : test)
	{
		printf("{%d,%d,%d,%d}  ", e.a, e.b, e.c, e.d);
	}
}
//int main()
//{
//	testMyvalue();
//	vector<PAIR> v;
//	PAIR p[] = { {2,4},{1,7}, {1, 2},{1,3},{1,-4},{2,7},{2,9} };
//	for (int i = 0; i < sizeof(p) / sizeof(p[0]); i++)
//	{
//		v.push_back(p[i]);
//	}
//	p[0].first;
//	mysort(v, fun_cmp<PAIR>());
//	for (auto e : v)
//	{
//		printf("{%d,%d}  ", e.first, e.second);
//	}
//	cout << flag;
//	string str;
//}
//void FindMax()//动态规划
//{
//	int i, j;
//	//填表
//	for (i = 1; i <= number; i++)
//	{
//		for (j = 1; j <= capacity; j++)
//		{
//			if (j < w[i])//包装不进
//			{
//				V[i][j] = V[i - 1][j];
//			}
//			else//能装
//			{
//				if (V[i - 1][j] > V[i - 1][j - w[i]] + v[i])//不装价值大
//				{
//					V[i][j] = V[i - 1][j];
//				}
//				else//前i-1个物品的最优解与第i个物品的价值之和更大
//				{
//					V[i][j] = V[i - 1][j - w[i]] + v[i];
//				}
//			}
//		}
//	}
//}
#include <unordered_set>
//例如:A = "00010001", B = "??"
//字符串B可能的字符串是"00", "01", "10", "11", 只有"11"没有出现在字符串A中, 所以输出3
int ma___in()
{
	string str1, str2;//str1 长字符串
	while (cin >> str1 >> str2)
	{
		int ret = 0;
		vector<int> arr;
		for (int i = 0; i < str2.size(); i++)
		{
			if (str2[i] == '?')
				arr.push_back(i);
		}
		unordered_set<string> set;
		int len = str2.size();
		for (int i = 0; i <= str1.size() - len; i++)
		{
			set.insert(str1.substr(i, len));
		}
		for (auto it = set.begin(); it != set.end(); it++)
		{
			string temp = *it;
			for (auto e : arr)
			{
				temp[e] = '?';
			}
			if (temp == str2)
				ret++;
		}
		cout << ret << endl;
	}
	return 0;
}


void fun1()
{
	auto bianliang = 'A' + 1 + 3.3;
	cout << typeid(bianliang).name() << endl;
	auto a = 11 | 10;
	cout <<a;
	printf("%5.3s","computer");
	int num;
	while (cin >> num)
	{
		vector<int> queue;
		queue.reserve(3 * num);
		int size = 3 * num;
		while (size--)
		{
			int nu; cin >> nu;
			queue.push_back(nu);
		}
		sort(queue.begin(), queue.end());
		int ret = 0;
		for (int i = num; i < 2 * num; i++)
		{
			ret += queue[i];
		}
		cout << ret << endl;
	}
}
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include<Windows.h>
using namespace std;
int main()
{
	fun1();
	int num;
	while (cin >> num)
	{
		DWORD start_time = GetTickCount();
		int ret = 0;
		int fi = -1;
		for (int i = 1; i <= num; i++)
		{
			string temp = to_string(i);

			while ((fi = temp.find('1')) != -1)
			{
				ret++;
				temp.erase(fi, 1);
			}
		}
		cout << ret << endl;
		DWORD end_time = GetTickCount();
		cout << "The run time is:" << (end_time - start_time) << "ms!" << endl;

	}

	//ma___in();
	//set<int> se;
	//se.insert(1);
	//if (se.end() == se.find(2))cout << "no find" << endl;
	//auto it = se.begin();
	//map<int,string> sssss;
	//sssss.insert(pair<int, string>(1, "2"));
	//cout<<sssss.begin()->second;
	//string str1="122,", str2;
	//for (char  e : str1)
	//{
	//	cout << e;
	//}
	//cin >> str1 >> str2;
	//unordered_map<char, int> hash;
	//int flag = 1;
	//for (int i = 0; i < str2.size(); i++)
	//{
	//	hash[str2[i]]++;
	//}
	//for (int i = 0; i < str1.size(); i++)
	//{
	//	if (hash.count(str1[i]) != 1)
	//		flag = 0;
	//}
	//flag == 1 ? cout << "true" : cout << "false";

}
//B站实现一个HTML语法检查器

//迅雷输入一个有符号整数，输出该整数的反转值。
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	string str;
//	int num;
//	int flag = 0;
//	cin >> num;
//	if (num < 0)
//	{
//		flag = 1;
//		num = -num;
//	}
//	string temp = to_string(num);
//	reverse(temp.begin(), temp.end());
//	int ret = atoi(temp.c_str());
//	if (flag == 1)
//		ret = -ret;
//	cout << ret;
//}