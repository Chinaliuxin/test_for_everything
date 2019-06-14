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
小东所在公司要发年终奖，而小东恰好获得了最高福利，他要在公司年会上参与一个抽奖游戏，游戏在一
个66的棋盘上进行，上面放着36个价值不等的礼物，每个小的棋盘上面放置着一个礼物，他需要从左上 角开
始游戏，每次只能向下或者向右移动一步，到达右下角停止，一路上的格子里的礼物小东都能拿到，请设计一个算法
使小东拿到价值最高的礼物。
给定一个66的矩阵board，其中每个元素为对应格子的礼物价值,左上角为[0,0],请返回能获得的最大价值，
保证每个礼物价值大于100小于1000。
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