#include<vector>
#include <iostream>
#include<algorithm>
using namespace std;
using std::max;
using std::min;
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		const int M = dungeon.size(), N = dungeon[0].size();
		vector<vector<int>> dp(M + 1, vector<int>(N + 1, INT_MAX));
		dp[M][N - 1] = dp[M - 1][N] = 1;
		for (int i = M - 1; i >= 0; i--) {
			for (int j = N - 1; j >= 0; j--) {
				dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
			}
		}
		return dp[0][0];
	}
};
//地下城游戏
//骑士救公主，骑士在左上角，公主在右下角，每个房间都会有个血量变化，如果血量<=0
//，立马死去。问骑士出发的时候带了多少血，才能成功就到公主。每个移动只能向右或者向下。