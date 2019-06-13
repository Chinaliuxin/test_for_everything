
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
				}//特殊Up
				else
				{
					flag -= 1;
				}//一般up
			}
			else//D
			{
				if (flag == n)
				{
					flag = 1;
				}//特殊down
				else
				{
					flag += 1;
				}//一般down
			}
		}
		for (int i = 1; i <= n; i++)
			cout << i << " ";
		cout << "\n" << flag << endl;
	}
	if (n > 4)//begin记录屏幕最上方数字
	{
		for (int i = 0; i < operate.size(); i++)
		{
			if (operate[i] == 'U')
			{
				if (begin == flag)//特殊up
				{
					if (begin == 1)//特殊up中的从1到10，完全翻页
					{
						begin = n - 3;
						flag = n;
					}
					else//特殊up中的向上,屏幕由4567变为3456
					{
						begin--;
						flag--;
					}
				}
				else//一般up
				{
					flag--;
				}
			}

			else//operater[i]==D
			{
				if (flag == (begin + 3))//特殊down
				{
					if ((begin + 3) == n)//特殊dowm中的完全翻页
					{
						begin = 1;
						flag = 1;
					}
					else//特殊down中的4567变成5678
					{
						begin++;
						flag++;
					}
				}
				else//一般dowm
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
/*链接：https://www.nowcoder.com/questionTerminal/eaf5b886bd6645dd9cfb5406f3753e15
来源：牛客网

MP3 Player因为屏幕较小，显示歌曲列表的时候每屏只能显示几首歌曲，用户要通过上下键才能浏览所有的歌曲。为了简化处理，假设每屏只能显示4首歌曲，光标初始的位置为第1首歌。

 

现在要实现通过上下键控制光标移动来浏览歌曲列表，控制逻辑如下：

歌曲总数<=4的时候，不需要翻页，只是挪动光标位置。

光标在第一首歌曲上时，按Up键光标挪到最后一首歌曲；光标在最后一首歌曲时，按Down键光标挪到第一首歌曲。



其他情况下用户按Up键，光标挪到上一首歌曲；用户按Down键，光标挪到下一首歌曲。



  2. 歌曲总数大于4的时候（以一共有10首歌为例）：

 

特殊翻页：屏幕显示的是第一页（即显示第1 – 4首）时，光标在第一首歌曲上，用户按Up键后，
屏幕要显示最后一页（即显示第7-10首歌），同时光标放到最后一首歌上。同样的，屏幕显示最后一页时，光标在最后一首歌曲上，用户按Down键，屏幕要显示第一页，光标挪到第一首歌上。



一般翻页：屏幕显示的不是第一页时，光标在当前屏幕显示的第一首歌曲时，用户按Up键后，屏幕从当前歌曲的上一首开始显示，光标也挪到上一首歌曲。光标当前屏幕的最后一首歌时的Down键处理也类似。



其他情况，不用翻页，只是挪动光标就行。*/