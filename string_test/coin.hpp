#pragma once

#include<iostream>
using namespace std;
class cointest {
public://��Ӳ��

	int coin[3] = { 1,3,5 };
	int dp[12];
	void dp_fun(int num)
	{
		dp[0] = 0;
		for (int i = 1; i <= num; i++)
		{
			dp[i] = 999999999;
			for (int j = 0; coin[j] <= i && j < 3; j++)
			{
				if (dp[i - coin[j]] + 1 < dp[i])
					dp[i] = dp[i - coin[j]] + 1;
			}
		}
	}
	int main()
	{
		dp_fun(11);		//��ʾҪ����11Ԫ��Ӳ��
		for (int i = 0; i < 12; i++)
		{
			cout << "����" << i << "Ԫ��������Ҫ" << dp[i] << "öӲ��" << endl;
		}
		return 0;
	}
};