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
//���³���Ϸ
//��ʿ�ȹ�������ʿ�����Ͻǣ����������½ǣ�ÿ�����䶼���и�Ѫ���仯�����Ѫ��<=0
//��������ȥ������ʿ������ʱ����˶���Ѫ�����ܳɹ��͵�������ÿ���ƶ�ֻ�����һ������¡�