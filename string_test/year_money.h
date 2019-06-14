#pragma once
#include <iostream>
#include<cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include<stack>
#include<map>
#include<vector>
/*
С�����ڹ�˾Ҫ�����ս�����С��ǡ�û������߸�������Ҫ�ڹ�˾����ϲ���һ���齱��Ϸ����Ϸ��һ
��66�������Ͻ��У��������36����ֵ���ȵ����ÿ��С���������������һ���������Ҫ������ �ǿ�
ʼ��Ϸ��ÿ��ֻ�����»��������ƶ�һ�����������½�ֹͣ��һ·�ϵĸ����������С�������õ��������һ���㷨
ʹС���õ���ֵ��ߵ����
����һ��66�ľ���board������ÿ��Ԫ��Ϊ��Ӧ���ӵ������ֵ,���Ͻ�Ϊ[0,0],�뷵���ܻ�õ�����ֵ��
��֤ÿ�������ֵ����100С��1000��
*/
using namespace std;
class Bonus {
public:

	int getMost(vector<vector<int> > board) {
		// write code here
		vector< vector<int> > dp(board.size() + 1, vector<int>(board[0].size() + 1, 0));

		for (int i = 1; i < dp.size(); i++) {
			for (int j = 1; j < dp[0].size(); j++)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + board[i - 1][j - 1];
			}
		}
		return dp[dp.size() - 1][dp[0].size() - 1];
	}
};