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
					dp[i] = dp[i - coin[j]] + 1;//a<b  b=a;
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


class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int size = A.size();
		int L = 0, R = size - 1;
		while (L < R) {
			while (L < R && A[L] % 2 == 0) {
				L++;
			}
			while (L < R && A[R] % 2 == 1) {
				R--;
			}
			swap(A[L], A[R]);
		}
		return A;
	}
};

//给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。

//你可以返回满足此条件的任何数组作为答案。