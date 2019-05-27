#include<string >
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
//template<class T>
//class myvector:public vector<T> {
//
////	myvector()
//		:
//	void fun()
//	{
//
//	}
//public:
//	auto v;
//};
template <class T = string>
void reverse(T & s)
{
	int begin = 0;
	int end = s.size() - 1;
		while (begin < end)
		{
			swap(s[begin++], s[end--]);
		}
}
int  atoi(char ch)
{
	return ch - '0';
}
void  my_main(string &num1, string &num2)
{
	vector<int> ret;
	if (num1.size() == 0 || num1[0] == '0')
	{
		for (auto e : num2)
		{
			cout << e;

		}
		return;
	}
	if (num2.size() == 0 || num2[0] == '0')
	{
		for (auto e : num1)
		{
			cout << e;
		}
		return;
	}
	reverse(num1), reverse(num2);
	int i = 0, j = 0, temp = 0;
	int len1 = num1.size();
	int len2 = num2.size();
	ret.reserve(std::max(len1, len2) + 1);
	int carry = 0;
	for (; i < len1 || j < len2; i++, j++)
	{
		int first = i < len1 ? atoi(num1[i]) : 0;
		int second = j < len2 ? atoi(num2[j]) : 0;
		ret.push_back(   (first+second + carry) % 10);
		if ((first+second+carry) >= 10)
			carry = 1;
		else
			carry = 0;
	}
	if (carry == 1)ret.push_back(1);
	reverse(ret);
	for (auto e : ret)
	{
		cout << e;
	}
	cout << '\n';
}
template<class T>
class testload {
	int ret;
public:
	static int myoverload();
	T fun();
	static int myoverload(int a, int b, int c=10)
	{
		cout << "��һ������";
		return a + b + c;
	}
	char myoverload(int a, int b)const
	{
		cerr << "�ڶ���";
		return a + b;
	}
	/*
	const ���ǶԺ�����һ���޶���ʹ���޷��޸����ڵ����ݳ�Ա��const���߱��������������
	�ı�����״̬��
	����һ�������� const �ؼ�����˵�����������һ��ֻ��������read only method����
	�������޸��κε����ݳ�ԱҲ���ǲ���ı�ö����״̬�����ຯ���������Ͷ���ʱ��Ҫ����
	const �ؼ��֡�
	*/
	int  myoverload(int a , int b = 1)
	{
		cerr << "������";
		this->ret = a;
		return a + b;
	}
	void  myoverload(size_t a, size_t b)
	{
		cout << "���ĸ�����";
	}
	void myoverload(char * s)
	{
		cout << "�ַ�������";
	}
	void myoverload(const char* s)
	{
		cout << "�ַ�������2";

	}
};
template <class T>
int testload<T>::myoverload()
{
	cout << "�ڶ������÷���";
	return 0;
}

template<class T>
inline T testload<T>::fun()
{
	T a = a + a;
	return T();
}

void dfs(string sofar, string rest, vector<string> &ret)
{
	if (rest.size() == 0)
	{
		ret.push_back(sofar);
	}
	else {
		for (int i = 0; i < rest.size(); i++)
		{
			string next = sofar + rest[i];
			string remianing = rest.substr(0, i) + rest.substr(i + 1);
			dfs(next, remianing, ret);
		}
	}
}
#include<set>
//ȫ���У����ַ������������
int testStringDfs()
{
	vector<string> ret;
	string str("1234");
	//cin >> str;
	dfs("", str, ret);
	sort(ret.begin(), ret.end());

	set<string> set(ret.begin(), ret.end());
	cout << "ԭ��С��"<<ret.size()<<"->"<<set.size();
	for (auto e : set)
	{
		cout << e << endl;
	}
	return 0;
}