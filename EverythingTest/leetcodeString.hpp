#pragma once
#include<iostream>
#include<string>
#include<algorithm>
/*
string s;
reverse(s.begin(),s.end());
s.substr(1,3) 获取从s[1]开始，长度为3的string
s.insert(2,ss)  在2号前插入ss
getline(cin, s);遇到空格情况
char *p = str.c_str();

char*转string
1 string s;
2 char *p = "hello";//直接赋值
3 s = p;
*/
using namespace std;
void myReverse(string& s)
{
	int begin = 0;
	int end = s.size() - 1;
	while (begin < end)
	{
		char temp = s[end];
		s[end] = s[begin];
		s[begin] = temp;
		begin++;
		end--;
	}
}
//把 we are student 变成 we%20are%20student
//void stringAdd20(string s)
//{
//	int count = 0;
//	for (auto e : s)
//	{
//		if (e == ' ')
//			count++;
//	}
//	string ret;
//	ret.resize(count + s.size());
//	for (int j = s.size() - 1;j>=0; j--)
//	{
//
//		ret.insert(0, cur);
//	}
//}
void teststringAdd20()
{
	string s;
	//string ss="ww";
	//s.insert(0, ss);
	getline(cin, s);
	cout << s;

}

char* myStrcoy(char* dest, const char*src)//src复制到dest
{
	if (dest == NULL || src == NULL)
	{
		return NULL;
	}
	char* destCopy = dest;//保持dest首地址，方便返回
	while (*src != '/0')
	{
		*dest = *src;
	}
	*dest = *src;//赋值'/0'
	return destCopy;
}
int mystrlen(const char*str)
{
	int count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return count;
}
void  findOnlyOne()
{
	int a = 1;
	int b = 2;
	string str;
	while (cin >> str)
	{
		unordered_map<char, int> m;
		for (auto e : str)
		{
			m[e] ++;
		}
		for (auto e : m)
		{
			if (e.second == 1)
				cout << e.first;
		}
	}
	cout << "-1";

}


int singleNumber(int* nums, int numsSize) {//找出只出现一次的数字
	int k = nums[0];
	for (int i = 1; i < numsSize; i++) {
		k = (k ^ nums[i]);
	}
	return k;
}

void testsinglenumber()
{
	int nums[] = { 5, 6, 5, 6, 8, 7, 7 };
	int number = singleNumber(nums, 7);
	printf("The single number is %d.\n", number);
}

void zuoyiVector(vector <int> & v, int k)//
{
	if (v.size() <= 1)
		return;

	k = k % v.size();
	for (int j = 0; j < k; j++)
	{
		int temp = v[0];
		for (int i = 0; i <= v.size() - 2; i++)//左移一次
		{
			v[i] = v[i + 1];
		}
		v[v.size() - 1] = temp;
	}
}
void testzuoyi()
{
	vector<int> v = { 1,2,3,4,5 };
	zuoyiVector(v, 3);
	for (auto e : v)
	{
		cout << e;
	}
}