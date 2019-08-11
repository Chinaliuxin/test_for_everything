#pragma once

void badball(int a[])
{
	;
}


/*
链接：https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163
来源：牛客网
O(n)
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/
#include<vector>
using namespace std;
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		vector<int> & a = numbers;
		int temp = numbers[0];
		int time = 1;
		for (int i = 1; i < a.size(); i++)
		{
			if (a[i] != temp)
			{
				if (time <= 0)
				{
					temp = a[i];
					time = 1;
				}
				else
				{
					time--;

				}
			}
			else {

				time++;
			}
		}
		time = 0;
		for (auto e : a)
		{
			if (e == temp)
				time++;
		}
		if (time > (a.size() / 2))
			return temp;
		else
			return 0;
	}
};

//NowCoder最喜欢游乐场的迷宫游戏，他和小伙伴们比赛谁先走出迷宫。
//现在把迷宫的地图给你，你能帮他算出最快走出迷宫需要多少步吗？

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <exception>
#include <iomanip>
#include <memory>
#include <sstream>

using namespace std;

bool check(int x, int y, int m, int n, vector<vector<char>>& room)
{
	return x >= 0 && x < m && y >= 0 && y < n && room[x][y] == '.';
}

int main_zoumigong(int argc, char** argv)
{
	//freopen("in.txt", "r", stdin);
	int m = 10, n = 10;
	string row;
	while (cin >> row)
	{
		vector<vector<char>> room(m, vector<char>(n));
		for (int i = 0; i < m; ++i)
		{
			if (i > 0) cin >> row;
			for (int j = 0; j < n; ++j)
			{
				room[i][j] = row[j];
			}
		}

		int sx = 0, sy = 1;
		int ex = 9, ey = 8;
		vector<pair<int, int>> cur;
		cur.emplace_back(sx, sy);
		room[sx][sy] = ' ';
		int step = 0;
		bool reach = false;
		while (!cur.empty())
		{
			vector<pair<int, int>> next;
			for (auto& pr : cur)
			{
				if (pr.first == ex && pr.second == ey)
				{
					reach = true;
					break;
				}
				int x = pr.first, y = pr.second;
				if (check(x - 1, y, m, n, room))
				{
					room[x - 1][y] = ' ';
					next.emplace_back(x - 1, y);
				}
				if (check(x + 1, y, m, n, room))
				{
					room[x + 1][y] = ' ';
					next.emplace_back(x + 1, y);
				}
				if (check(x, y - 1, m, n, room))
				{
					room[x][y - 1] = ' ';
					next.emplace_back(x, y - 1);
				}
				if (check(x, y + 1, m, n, room))
				{
					room[x][y + 1] = ' ';
					next.emplace_back(x, y + 1);
				}
			}
			if (reach) break;
			++step;
			cur = next;
		}

		cout << step << endl;
	}

	return 0;
}


class Solution {
public:
	double myPow(double x, long long n) {
		if (n == 0)
			return 1;
		if (n < 0)
			return 1 / myPow(x, -n);
		double mid = myPow(x, n / 2);
		if (n & 1)
			return mid * mid * x;
		return mid * mid;
	}
};


