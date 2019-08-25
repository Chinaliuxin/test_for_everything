////#include<iostream>
////using namespace std;
////int main()
////{
////	//排列组合，1个人座位对=>  (n-1)的排列*n  A(n-2)(n-2)
////
////}
//#include <iostream>
//using namespace std;
//int f(int n)
//{
//	//  d1=0,d2=1 
//	//   d3= 2*1=2
//	//d4= 3*(2+1)=6
//	if (n <= 2)return 0;
//	int ret = n;
//	n = n - 1;
//	int first = 0;//1
//	int second = 1;//2
//	for (size_t i = 3; i <= n; i++)
//	{
//		int temp = first;
//		first = second;
//		second = (i-1)*(temp + first);
//	}
//	return ret * second;
//}
//int main()
//{
//	int n=4;
//	cin >> n;
//	cout << f(n) << endl;
//
//}
#include<iostream>
#include<vector>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	//01背包，time==》V    分数等于价值，时间等于体积
	int size; cin >> size;
	vector<int>  w; w.resize(size + 1, 0);
	vector<int>  v; v.resize(size + 1, 0);
	vector<int> dp;

	for (int i = 1; i <= size; i++)
	{
		int temp; cin >> temp;
		v[i] = temp;
	}
	for (int i = 1; i <= size; i++)
	{
		int temp; cin >> temp;
		w[i] = temp;
	}
	int weight = 10; //cin >> weight;
	dp.resize(weight + 1, 0);
	for (int i = 1; i <= size; i++)
	{
		for (int j = weight; j >= w[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

		}
	}
	cout << dp[weight];

}
//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> a={ "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		vector<string> c;
		if (digits.empty())
			return c;
		c.push_back("");
		for (int i = 0; i < digits.size(); i++)
		{
			int res = digits[i] - '2';//当前按键对应的字符串索引
			int len = c.size();     //前一次处理好的字符串数
			for (int i = 0; i < len; i++)//遍历前一次处理好的字符串
			{
				for (auto m : a[res])//遍历按键对应字符
				{
					c.push_back(c[i] + m);//将每一种组合放到末端
				}
			}
			c.erase(c.begin(), c.begin() + len);//清除前一次的组合
		}
		return c;
	}
};


