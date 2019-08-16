//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
////int abs(int a)
////{
////	if (a > 0)return a;
////	else return -a;
////}
////void fun(vector<int> &ret)
////{
////	int first;
////	int second;
////	int ans = 9999999999;
////	for (int i = 0; i < ret.size()-1; i++)
////	{
////		//i，i+1
////
////		int min = abs(ret[i] - ret[i + 1]);
////		if (min < ans)
////		{
////			first = i;
////			second = i + 1;
////			ans = min;
////		}
////	}
////	cout << ret[first] << " " << ret[second];
////}
////int main()
////{
////	vector<int> ret;
////	int time = 9;
////	ret = { 0,1,-10,10};
////	//ret = { 1,2 ,2};
////	//for (int i = 0; i < time; i++)
////	//{
////	//	int num;
////	//	cin >> num;
////	//	ret.push_back(num);
////	//}
////	fun(ret);
////
////
////
////}
/////-----------------------------------------------------------------------
//
////bool canDo(int a, int b)
////{
////	if (a == b)return true;
////	else {
////		if (a > b)
////		{
////			double ans = a * 0.9;
////			return b >= ans;
////		}
////		else {
////			double ans = b * 0.9;
////			return a >= ans;
////		}
////	}
////	return false;
////}
/////*
////  1 2 3 4 5
////1 
////2
////3
////4
////5
////*/
////int  fun(vector<int> &ret) {
////	int flag = 0;
////	for (int j = 0; j < ret.size(); j++)
////	{
////		for (int i = 0; i < ret.size(); i++)
////		{
////			if (canDo(ret[i], ret[j]))
////			{
////				flag++;
////			}
////		}
////	}
////
////	flag = (flag - ret.size()) / 2;
////	return flag;
////}
////int main()
////{
////	int num;
////	cin >> num;
////	vector<int> ret;
////	ret.reserve(num);
////
////	for (int i = 0; i < num; i++)
////	{
////		int add; cin >> add;
////		ret.push_back(add);
////	}
////	ret = { 1,2,1,2,3,3,4,5,65,6,7,7,8,8,8,8,9,9,9,90,0,0,0,0,0,8,7,7,7,77,7,7, };
////	cout << fun(ret) << endl;
////	return 0;
////
////}
//int fun(vector<int> &ret) {
//	vector<int> fo; 
//	fo.resize(ret.size());
//	int ans = -9999999;
//	for (int i =0; i < fo.size(); i++)
//	{
//		fo[i] = 1;
//	}
//	for (int i = 0; i <ret.size(); i++)
//	{
//		for (int j = 0; j <=i; j++)
//		{
//			if (ret[j] < ret[i])
//				fo[i] = max(fo[i], fo[j] + 1);
//			for (int i = 0; i < ret.size(); i++)
//			{
//				ans = max(ans, fo[i]);
//			}
//		}
//	}
//	return ans;
//}
//int main()
//{
//	//int num;
//	vector<int> ret;
//
//	//cin >> num;
//	//ret.reserve(num);
//	//for (int i = 0; i < num; i++)
//	//{
//	//	int add;
//	//	cin >> add;
//	//	ret.push_back(add);
//	//}
//	ret = { 5,1,6,8,2,4,5,10 };
//	cout << fun(ret) << endl;
//
//
//}
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
long long myabs(long long  a)
{
	if (a > 0)return a;
	else return -a;
}
void fun(vector<long long> & ret)
{
	int first = 0;
	int second = 1;
	long long ans = 10000000000000001;
	for (int i = 0; i < ret.size() - 1; i++)
	{
		//i，i+1

		long long min = myabs(ret[i] - ret[i + 1]);
		if (min < ans)
		{
			first = i;
			second = i + 1;
			ans = min;
		}
	}
	cout << ret[first] << " " << ret[second];
}
int main()
{
	long long te = 99999999999999;
	cout << te;
	vector< long long> ret;
	int time;
	cin >> time;
	ret.reserve(time);
	for (int i = 0; i < time; i++)
	{
		long long  num;
		cin >> num;
		ret.push_back(num);
	}
	fun(ret);

	return 0;
}
//给你一个高为n ，宽为m列的网格，计算出这个网格中有多少个矩形
/*
如果只看一行的话，它有多少个矩形呢？单个地数有m个，两个地数有m-1个……，m个地数有1个。
每一行就有：1+2+3+……+m个=m * (m + 1) / 2。
我们把每一行抽象成一个矩形，也就只剩一列了。一列的话，有:1+2+……+n=n * (n + 1) / 2个。
总结起来，就有：（1+m）* m/2 * (1+n)*n/2那么多个了。

http://www.itkeyword.com/doc/8173314389299632466
*/

int getHowMany(int n,int m)//长和宽
{
	return (1 + m) * m / 2 * (1 + n)*n / 2;
}