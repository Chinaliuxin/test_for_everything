#pragma once


// write your code here cpp
#include <iostream>
#include <string>
/*


��������ͨ����һ�����ĸ���λ�ϵ����ּ������õ�������õ�������һλ������ô�������������������������λ�����߰�������λ�����֣���ô�ٰ���Щ���ּ���������˽�����ȥ��ֱ���õ���һλ��Ϊֹ��
���磬����24 ��˵����2 ��4 �õ�6������6 ��һλ�������6 ��24 ��������
�ٱ���39����3 ��9 �������õ�12������12 ����һλ������˻��ð�1 ��2 �����������õ�3������һ��һλ�������3 ��39 ��������
���ڸ���һ�����������������������
*/
using namespace std;
int get(int num)
{
	if (num < 10)return num;
	int sum = 0;
	while (num > 0)
	{
		sum += num % 10;
		num = num / 10;

	}
	if (sum >= 10)sum = get(sum);
	return sum;
}
int testget()
{
	string num;
	while (cin>>num)
	{
		int sum = 0;
		for (string::iterator it = num.begin(); it != num.end(); it++)
		{
			sum = (*it) + sum - '0';
		}
		sum = get(sum);
		cout << sum << endl;
	}
}