#pragma once

#include<iostream>
using namespace std;
class cointest {
public://凑硬币

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
		dp_fun(11);		//表示要凑齐11元的硬币
		for (int i = 0; i < 12; i++)
		{
			cout << "凑齐" << i << "元，至少须要" << dp[i] << "枚硬币" << endl;
		}
		return 0;
	}
};