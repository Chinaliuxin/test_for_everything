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