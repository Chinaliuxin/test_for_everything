
#pragma once
#include <iostream>
#include<string>
using namespace std;

void MP3(int n, string operate)
{
	int flag = 1;
	int begin = 1;//end=begin+3
	if (n <= 4)
	{
		for (int i = 0; i < operate.size(); i++)
		{
			if (operate[i] == 'U')
			{
				if (flag == 1)
				{
					flag = n;
				}//����Up
				else
				{
					flag -= 1;
				}//һ��up
			}
			else//D
			{
				if (flag == n)
				{
					flag = 1;
				}//����down
				else
				{
					flag += 1;
				}//һ��down
			}
		}
		for (int i = 1; i <= n; i++)
			cout << i << " ";
		cout << "\n" << flag << endl;
	}
	if (n > 4)//begin��¼��Ļ���Ϸ�����
	{
		for (int i = 0; i < operate.size(); i++)
		{
			if (operate[i] == 'U')
			{
				if (begin == flag)//����up
				{
					if (begin == 1)//����up�еĴ�1��10����ȫ��ҳ
					{
						begin = n - 3;
						flag = n;
					}
					else//����up�е�����,��Ļ��4567��Ϊ3456
					{
						begin--;
						flag--;
					}
				}
				else//һ��up
				{
					flag--;
				}
			}

			else//operater[i]==D
			{
				if (flag == (begin + 3))//����down
				{
					if ((begin + 3) == n)//����dowm�е���ȫ��ҳ
					{
						begin = 1;
						flag = 1;
					}
					else//����down�е�4567���5678
					{
						begin++;
						flag++;
					}
				}
				else//һ��dowm
				{
					flag++;
				}
			}
		}
		cout << begin << " " << begin + 1 << " " << begin + 2 << " " << begin + 3 << " " << endl;
		cout << flag << endl;
	}
}
int test_MP3()
{
	int n;
	string op;
	while (cin >> n >> op)
	{
		MP3(n, op);
	}
	return 0;
}
/*���ӣ�https://www.nowcoder.com/questionTerminal/eaf5b886bd6645dd9cfb5406f3753e15
��Դ��ţ����

MP3 Player��Ϊ��Ļ��С����ʾ�����б��ʱ��ÿ��ֻ����ʾ���׸������û�Ҫͨ�����¼�����������еĸ�����Ϊ�˼򻯴�������ÿ��ֻ����ʾ4�׸���������ʼ��λ��Ϊ��1�׸衣

 

����Ҫʵ��ͨ�����¼����ƹ���ƶ�����������б������߼����£�

��������<=4��ʱ�򣬲���Ҫ��ҳ��ֻ��Ų�����λ�á�

����ڵ�һ�׸�����ʱ����Up�����Ų�����һ�׸�������������һ�׸���ʱ����Down�����Ų����һ�׸�����



����������û���Up�������Ų����һ�׸������û���Down�������Ų����һ�׸�����



  2. ������������4��ʱ����һ����10�׸�Ϊ������

 

���ⷭҳ����Ļ��ʾ���ǵ�һҳ������ʾ��1 �C 4�ף�ʱ������ڵ�һ�׸����ϣ��û���Up����
��ĻҪ��ʾ���һҳ������ʾ��7-10�׸裩��ͬʱ���ŵ����һ�׸��ϡ�ͬ���ģ���Ļ��ʾ���һҳʱ����������һ�׸����ϣ��û���Down������ĻҪ��ʾ��һҳ�����Ų����һ�׸��ϡ�



һ�㷭ҳ����Ļ��ʾ�Ĳ��ǵ�һҳʱ������ڵ�ǰ��Ļ��ʾ�ĵ�һ�׸���ʱ���û���Up������Ļ�ӵ�ǰ��������һ�׿�ʼ��ʾ�����ҲŲ����һ�׸�������굱ǰ��Ļ�����һ�׸�ʱ��Down������Ҳ���ơ�



������������÷�ҳ��ֻ��Ų�������С�*/