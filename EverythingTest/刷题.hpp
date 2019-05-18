#include <iostream>
#include <stdio.h>
#include <string.h>
#include<array>
#include<vector>
#define  CRT_SECURE_NO_WARNINGS 1
using namespace std;

bool isnum(int num)//看是不是素数
{
	for (int i = 2; i < num; i++)
	{
		if (num%i == 0)
			return true;
	}
	return false;
}
void fun(int num)
{
	int temp = (num / 2) + 1;//

	while (temp < num)
	{
		int temp2 = num - temp;
		if (isnum(temp) && isnum(temp2))
		{
			cout << temp2 << endl << temp << endl;
			return;
		}
		temp++;
	}
}

//int ma()
//{
//	FILE *fp = fopen("myfile", "w");
//	if (!fp) {
//		printf("fopen error!\n");
//	}
//	const char *msg = "hello bit!\n";
//	int count = 5;
//	while (count--) {
//		fwrite(msg, strlen(msg), 1, fp);
//	}
//	fclose(fp);
//	return 0;
//}
//打印三角形
void printSanjiao(int n)//n是行数。1,3,5,7
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i-1; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < 2 * i + 1; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void vectorfor(vector<int> &v1, vector<int> & v2)
{
	for (int i = 0; i < v1.size(); i++)
	{

	}
}
void testvectorfor()
{
	vector<int> v1 = { 1,3,5,7 };
	vector<int> v2 = { 1,4,6,8 };
	vectorfor(v1, v2);

}
//1,1,2,3,5
int fibonacci(int n)
{
	if (n == 1 || n == 2)
		return 1;
	int first = 1;
	int second = 1;
	int temp = 0;
	for (int i = 2; i < n; i++)
	{
		temp = second;//1 1 2 3 5
		second = first + second;
		first = temp;

	}
	return second;
}
int fir(int first, int second, int num)
{
	if (num == 1)
		return first;
	return fir(second, first + second, --num);
}
#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
int mafin()
{
	int a = 1;
	++a += a++;
	//a++ += a++;
	string s = "0123456789";
	string s2 = "sdf";
	s2 += s;
	cout << s2 << "\n";
	cout << s.erase(3, 1);
	cout << s[3];
	cout << s[8];
	system("pause");
	return 0;
}
//int main() {
//	string str,str2;
//	while (getline(cin,str2)&& getline(cin, str))
//	{
//		string::iterator it = str.begin();
//		reverse(str.begin(), str.end());
//		int flag = 0;
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (str[i] == ' ')
//			{
//				reverse(it + flag, it + i);
//				flag = i + 1;
//			}
//		}
//		cout << str << endl;
//	}
//
//}
//#include<iostream>
//using namespace std;
//void swap(int &a, int &b)
//{
//	a = a + b;
//	b = a - b;
//	a = a - b;
//}
//int main()
//{
//	long a, b, c;
//	while (cin >> a >> b >> c)
//		//保证a>=b>=c
//	{
//		if (a <= b)
//			swap(a, b);
//		if (a <= c)
//			swap(a, c);
//		if (c <= b)
//			swap(b, c);
//		if (a < 0 || b < 0 || c < 0 || b + c <= a)
//			cout << "No" << endl;
//		else
//			cout << "Yes" << endl;
//	}
//	return 0;
//}
////#include<iostream>
//#include <algorithm>
//#include<string>
//using namespace std;
//int main()
//{
//	string str = "123 456 78";
//	int a=111;
//	cout<<to_string(a);
//	cout << str.find("123 4");
//	if (-1 != str.find("123"))cout << "dsf";
//	//while (getline(cin, str)) 
//	{
//		reverse(str.begin(), str.end());
//		int flag = 0;
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (str[i] == ' ')
//			{
//				reverse(str.begin() + flag, str.begin() + i);
//				flag = i + 1;
//			}
//
//		}
//		cout << str;
//	}
//}
//int main()
//{
//	cout << fibonacci(5);
//	cout << fir(1, 1, 5);
//	//testvectorfor();
//	char x[] = "abc";
//	char xx[] = { 1,2 };
//	char Y[3] = { 'a','b','c' };
//	cout << strlen(x) << strlen(Y) << endl;
//	cout << sizeof(x) << sizeof(Y)<<endl;
//	cout << strlen(xx);
//	
//}
/*
// Sample code to perform I/O:

#include <iostream>

using na

space std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <iostream>
#include <unordered_map>
#include <vector>
void 数之和最多次数()
{
	int num;//数字个数
	int n;
	vector<int> v1;//存输入数
	while (cin >> n)
	{

		v1.push_back(n);
	}
	vector<int> v2;//存放相加数
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = i + 1; j < v1.size(); j++)
		{
			v2.push_back(v1[i] + v1[j]);
		}
	}
	unordered_map<int, int> map;
	for (int i = 0; i < v2.size(); i++)
	{
		map[v2[i]]++;
	}
	auto it = map.begin();
	int max = 0;
	for (; it != map.end(); it++)
	{
		if (it->second > max)
		{
			max = it->second;//找到出现最多的次数
		}
	}
	for (it = map.begin(); it != map.end(); it++)
	{
		if (it->second == max)
			cout << it->first << endl;
	}
}

//合并2个有序数组
class Solutio {
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
int countBitDiff(int m, int n) {
	int count = 0;
	int i = 32;
	while (i != 0)
	{


		if ((m & 1) != (n & 1))
		{
			count++;
		}
		i--;
		m=m>>1;
		n=n>>1;
	}
	return count;
}