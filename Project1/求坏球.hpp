#pragma once

void badball(int a[])
{
	;
}


/*
���ӣ�https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163
��Դ��ţ����
O(n)
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
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