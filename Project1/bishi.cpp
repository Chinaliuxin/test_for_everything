////#include<iostream>
////using namespace std;
////int main()
////{
////	//������ϣ�1������λ��=>  (n-1)������*n  A(n-2)(n-2)
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
	//01������time==��V    �������ڼ�ֵ��ʱ��������
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
//����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�

//�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ
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
			int res = digits[i] - '2';//��ǰ������Ӧ���ַ�������
			int len = c.size();     //ǰһ�δ���õ��ַ�����
			for (int i = 0; i < len; i++)//����ǰһ�δ���õ��ַ���
			{
				for (auto m : a[res])//����������Ӧ�ַ�
				{
					c.push_back(c[i] + m);//��ÿһ����Ϸŵ�ĩ��
				}
			}
			c.erase(c.begin(), c.begin() + len);//���ǰһ�ε����
		}
		return c;
	}
};


