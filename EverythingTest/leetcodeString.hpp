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