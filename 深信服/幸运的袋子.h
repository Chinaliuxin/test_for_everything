#pragma once
#include "father.hpp"
#include<iostream>
#include <set>
#include<vector>
using namespace std;
bool istrue_(vector <int> &v)
{
	int add = 0;
	int mul = 1;
	for (auto e : v)
	{
		add += e;
		mul *= e;
	}
	if (add > mul)
		return true;
	else
		return false;
}
void fun_luck(vector<int>&v)
{
	int ret = 0;
	int max = 1 << v.size();
	set<vector<int>>set;
	for (int i = 1; i < max; i++)
	{
		int index = 0;
		int flag = i;
		vector<int> temp;
		while (flag > 0)
		{
			if (flag & 1)
			{
				temp.push_back(v[index]);
			}
			index++;
			flag = flag >> 1;
		}
		set.insert(temp);
	}
	for (auto e : set)
	{
		if (istrue_(e))
			ret++;
	}
	cout << ret << endl;
}
int testluck()
{
	DWORD start_time1 = GetTickCount();
	vector<int> v;
	v = { 1,2,1,2,1,1,7,43,3 };
	fun_luck(v);
	DWORD end_time1 = GetTickCount();
	cout << "The run time is:" << (end_time1 - start_time1) << "ms!" << endl;
	return 0;
}
/*
DWORD start_time1 = GetTickCount();

	DWORD end_time1 = GetTickCount();

	cout << "The run time is:" << (end_time1 - start_time1) << "ms!" << endl;
*/