//#include <iostream>
//#include <string>
//using namespace std;
//24进制转10进制
//int Toint(char ch)
//{
//	return ch - '0';
//}
//long long  pow(int n)
//{
//	long long ret = 1;
//	for (int i = 0; i < n; i++)
//	{
//		ret = ret * 24;
//	}
//	return ret;
//}
//void reverse(string & str)
//{
//	int begin = 0;
//	int end = str.size() - 1;
//	while (begin < end)
//	{
//		swap(str[begin++], str[end--]);
//	}
//}
//int myfun(string & str)
//{
//	string table = "0123456789abcdefghijklmn";
//	reverse(str);
//	long long ret = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		int temp = table.find(str[i]);
//		if (i == 0)
//			ret += temp;
//		else
//		ret += temp *pow(i);
//	}
//	return ret;
//	//cout << ret << endl;
//}
//int main()
//{
//
//			string str="10";
//			cout<<myfun(str);
//
//	return 0;
//}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool size(vector<int> &I, vector<int> &O)
{
	if (I.size() == O.size() && I.size() > 0)
	{
		return true;
	}
	else
		return false;
}
bool myfun(vector<int> &I, vector<int> &O, stack<int>& sta)
{
	int i = 0; int j = 0;
	for (; i < I.size(); i++)
	{
		sta.push(I[i]);
		while (sta.size() != 0 && sta.top() == O[j])
		{
			if (sta.top() == O[j]);
			{
				sta.pop();
				j++;
			}
		}
	}
	if (sta.empty() == 1 && i == j)
	{
		return true;
	}
	else
		return false;
}
#include <string>
//判断入栈出栈顺序
//int main()
//{
//	//push,pop==>1-1,2-2,
//	//1234 == 3421
//	//
//	int num = 1;
//	//cin >> num;
//	while (num--)
//	{
//		vector<int> I;
//		vector<int> O;
//		stack<int> sta;
//		int numb;
//		string str1;
//		getline(cin, str1);
//			for (int i = 0; i < str1.size(); i++)
//			{
//				numb = str1[i] - '0';
//				I.push_back(numb);
//			}
//			string str2;
//			getline(cin, str2);
//			for (int i = 0; i < str2.size(); i++)
//			{
//				numb = str2[i] - '0';
//				O.push_back(numb);
//			}
//		if (size(I, O) && myfun(I, O, sta))
//			cout << "Y" << endl;
//		else
//			cout << "N" << endl;
//	}
//	return 0;
//}

#include<iostream>
#include <string>
#include<vector>
#include <algorithm>
using namespace std;
struct len {
	bool operator()(string a, string b)
	{
		return a.size() < b.size();
	}
};
struct dic {
	bool operator()(string a, string b)
	{
		bool flag = false;
		for (int j = 0, i = 0; i < a.size() && j < b.size(); i++,j++)
		{
			if (a[i] == b[j])
				;
			else
			{
				return a[i] > b[j];
			}
		}
	}
};
bool equal(vector<string>first, vector<string> second)
{
	for (int i = 0, j = 0; i < first.size(); i++, j++)
	{
		if (first[i] == second[j])
			;
		else
			return false;
	}
	return true;
}
int main_()
{
	int num;
	cin >> num;
	vector<string> ret;
	int flag = 0;//0->none ,1 lengths,2
	while (num--)
	{


		string str;
		cin >> str;
		ret.push_back(str);
	}
		auto temp = ret;
		sort(temp.begin(), temp.end(), len());
		if (equal(temp, ret))flag = 1;
		sort(temp.begin(), temp.end());
		if (equal(temp, ret))
		{
			if (flag == 1)
				flag = 3, cout << "both" << endl;
			else
				flag = 2, cout << "lexicographocally" << endl;
		}
		if (flag == 1)
			cout << "lengths" << endl;
		if (flag == 0)
			cout << "none" << endl;
		return -1;
}
#include"father.hpp"	

int main()
{
	机器人走路();
	testAandB();

}