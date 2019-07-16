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

class Solution {//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		//vector<int> v={};
		for (int i = 0; i < nums.size(); i++) {
			m[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (m.count(target - nums[i]) && i != m[target - nums[i]])
			{
				//auto it=m.find(target-nums[i]);
				//v.push_back(i);
				//v.push_back(m[target-nums[i]]);//或者直接push m[target-nums[i]]
				return { i,m[target - nums[i]] };
			}
		}
		return {};
	}
};
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
//数组左移
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

/*
对字符串中的所有单词进行倒排。

说明：

1、每个单词是以26个大写或小写英文字母构成；

2、非构成单词的字符均视为单词间隔符；

3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；

4、每个单词最长20个字母；
*/

#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
//123   45 67  ====>vector[0]=123...
void func_dancinizhi(string& str) {
	vector<string> out;
	out.clear();
	string temp;
	for (size_t i = 0; i < str.size(); i++)
	{

		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
			temp.push_back(str[i]);
		else {
			if (temp.size() > 0)
			{
				out.push_back(temp);
				temp.clear();
			}
		}
	}
	if (temp.size() > 0)out.push_back(temp);
	reverse(out.begin(), out.end());
	for (auto e : out)
	{
		cout << e << " ";
	}
	cout << endl;
}
/*
int main()
{
	string str;
	while (getline(cin, str)) {
		func_dancinizhi(str);
	}
}
*/