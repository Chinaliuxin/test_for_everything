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
////		//i��i+1
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
		//i��i+1

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
//����һ����Ϊn ����Ϊm�е����񣬼��������������ж��ٸ�����
/*
���ֻ��һ�еĻ������ж��ٸ������أ�����������m��������������m-1��������m��������1����
ÿһ�о��У�1+2+3+����+m��=m * (m + 1) / 2��
���ǰ�ÿһ�г����һ�����Σ�Ҳ��ֻʣһ���ˡ�һ�еĻ�����:1+2+����+n=n * (n + 1) / 2����
�ܽ����������У���1+m��* m/2 * (1+n)*n/2��ô����ˡ�

http://www.itkeyword.com/doc/8173314389299632466
*/

int getHowMany(int n,int m)//���Ϳ�
{
	return (1 + m) * m / 2 * (1 + n)*n / 2;
}


//https://www.nowcoder.com/questionTerminal/fae8632cfc64433989720bc01e09f382?orderByHotValue=1&page=1&onlyReference=false
//Ȼ���ö��ֵ�˼·���

#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	long long sum, i, t;
	scanf("%lld", &sum);
	int w = to_string(sum).size();
	for (i = 10 * w; i < sum; i++)
	{
		long long s = 0;
		t = i;
		while (t)
		{
			s += t;
			t /= 10;
		}
		if (s == sum) { printf("%lld", i); return 0; }
	}
	printf("-1");
}

#include<stdio.h>
#include<iostream>
typedef   long long L;

using namespace std;
L   check(L num)
{
	L sum = 0;
	while (num != 0)
	{
		sum += num;
		num = num / 10;
	}
	return sum;
}

int main()
{
	L num = 137174210616796;
	auto hh = check(123456789555123);
	printf("%lld", check(123456789555123));
	L left = 0;
	L right = num + 1;
	L& key = num;
	while (left <= right)
	{
		L mid = left + ((right - left) >> 1);
		if (check(mid) == key) { cout << mid << endl; return 0; }
		if (check(mid) < key)
		{
			left = mid + 1;
		}
		if (check(mid) > key)
		{
			right = mid - 1;
		}
	}
	cout << "-1" << endl;
	return 0;
}
