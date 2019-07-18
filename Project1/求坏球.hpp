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