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
					dp[i] = dp[i - coin[j]] + 1;//a<b  b=a;
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

//����һ���Ǹ��������� A������һ�����飬�ڸ������У� A ������ż��Ԫ��֮�������������Ԫ�ء�

//����Է���������������κ�������Ϊ�𰸡�