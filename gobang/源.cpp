#include<iostream>
#include<memory>
using namespace std;


class gobang {


public:
	static char data[12][12];
	static bool istaked[12][12];
	void initthearray()
	{
		memset(data, ' ', sizeof(data));
		memset(istaked, false, sizeof(istaked));
	}

	void output()
	{
		int row, column, count1;

		cout << "    1   2   3   4    5    6   7   8   9  10" << endl;
		for (row = 0; row < 21; row++)
		{
			if (row % 2 == 0)
			{
				cout << "    ";
				for (count1 = 0; count1 < 10; count1++)
					cout << "--- ";
				cout << endl;
			}
			else {
				if (row == 19)
					cout << "10 |";
				else
					cout << (row + 1) / 2 << "  " << "|";
				for (column = 1; column < 11; column++)
					cout << " " << data[(row + 1) / 2][column] << " |";
				cout << endl;

			}
		}
	}

	int isover()
	{
		// to find if it's over for the game
		int row, column, key, flag = 0;
		char station;

		//to decide if it's a tie
		for (row = 1; row < 11; row++)
		{
			for (column = 1; column < 11; column++)
			{
				if (istaked[row][column] == false)
					flag = 1;
			}
		}
		if (flag == 0)
		{
			return(-1);
		}
		for (row = 1; row < 11; row++)
		{
			for (column = 1; column < 11; column++)
			{
				station = data[row][column];
				if (station == ' ')
					continue;
				if (station == '*')
					key = 1;
				if (station == 'o')
					key = 2;
				if (data[row][column + 1] == station && data[row][column + 2] == station && data[row][column + 3] == station && data[row][column + 4] == station)
					return(key);
				if (data[row + 1][column] == station && data[row + 2][column] == station && data[row + 3][column] == station && data[row + 4][column] == station)
					return(key);
				if (data[row + 1][column + 1] == station && data[row + 2][column + 2] == station && data[row + 3][column + 3] == station && data[row + 4][column + 4] == station)
					return(key);
				if (data[row + 1][column - 1] == station && data[row + 2][column - 2] == station && data[row + 3][column - 3] == station && data[row + 4][column - 4] == station)
					return(key);
			}
		}

		return(0);
	}
	void getposition()
	{
		int row, column;
		cin >> row >> column;

		while (istaked[row][column] == true)
		{
			cout << "这个位置已经放置了棋子，请重新放置！";
			cin >> row >> column;
		}
		while (row < 1 || row>10 || column < 1 || column>10)
		{
			cout << "对不起！不能在棋盘外放置棋子！";
			cin >> row >> column;
		}
		data[row][column] = '*';
		istaked[row][column] = true;
	}

	void AIsolve()
	{
		//this part is the most difficult part of the game, I just write a simple AI
		//first step is to detect if there is any chance to win, then if there is any danger to save
		int row, column;
		char pict;

		//to find if there is any chance to win
		for (row = 1; row < 11; row++)
		{
			for (column = 1; column < 11; column++)
			{
				pict = data[row][column];
				if (pict == ' ' || pict == '*')
					continue;                           //decide if the place is took by the AI

				//to detect if there is any four in a row continuous
				if (data[row][column + 1] == pict && data[row][column + 2] == pict && data[row][column + 3] == pict)
				{
					if (istaked[row][column - 1] == false && column > 1)
					{
						data[row][column - 1] = 'o';
						istaked[row][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row][column + 4] == false && column < 7)
					{
						data[row][column + 4] = 'o';
						istaked[row][column + 4] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column + 4 << endl;
						return;
					}
				}

				//to detect if there is any four in a column continuous
				if (data[row + 1][column] == pict && data[row + 2][column] == pict && data[row + 3][column] == pict)
				{
					if (istaked[row - 1][column] == false && row > 1)
					{
						data[row - 1][column] = 'o';
						istaked[row - 1][column] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column << endl;
						return;
					}
					if (istaked[row + 4][column] == false && row < 7)
					{
						data[row + 4][column] = 'o';
						istaked[row + 4][column] = true;
						cout << "电脑放置棋子的位置是:" << row + 4 << ' ' << column << endl;
						return;
					}
				}

				//to detect the other two cases
				if (data[row + 1][column + 1] == pict && data[row + 2][column + 2] == pict && data[row + 3][column + 3] == pict)
				{
					if (istaked[row - 1][column - 1] == false && column > 1 && row > 1)
					{
						data[row - 1][column - 1] = 'o';
						istaked[row - 1][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row + 4][column + 4] == false && column < 7 && row < 7)
					{
						data[row + 4][column + 4] = 'o';
						istaked[row + 4][column + 4] = true;
						cout << "电脑放置棋子的位置是:" << row + 4 << ' ' << column + 4 << endl;
						return;
					}
				}

				//another case
				if (data[row + 1][column - 1] == pict && data[row + 2][column - 2] == pict && data[row + 3][column - 3] == pict)
				{
					if (istaked[row - 1][column + 1] == false && column < 10 && row>1)
					{
						data[row - 1][column + 1] = 'o';
						istaked[row - 1][column + 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column + 1 << endl;
						return;
					}
					if (istaked[row + 4][column - 4] == false && column > 4 && row < 7)
					{
						data[row + 4][column - 4] = 'o';
						istaked[row + 4][column - 4] = true;
						cout << "电脑放置棋子的位置是:" << row + 4 << ' ' << column - 4 << endl;
						return;
					}
				}
			}
		}

		//to find if there is any danger need to save	
		for (row = 1; row < 11; row++)
		{
			for (column = 1; column < 11; column++)
			{
				pict = data[row][column];
				if (pict == ' ' || pict == 'o')
					continue;                           //decide if the place is took by the AI

				//to detect if there is any four in a row continuous
				if (data[row][column + 1] == pict && data[row][column + 2] == pict && data[row][column + 3] == pict)
				{
					if (istaked[row][column - 1] == false && column > 1)
					{
						data[row][column - 1] = 'o';
						istaked[row][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row][column + 4] == false && column < 7)
					{
						data[row][column + 4] = 'o';
						istaked[row][column + 4] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column + 4 << endl;
						return;
					}
				}

				//to detect if there is any four in a column continuous
				if (data[row + 1][column] == pict && data[row + 2][column] == pict && data[row + 3][column] == pict)
				{
					if (istaked[row - 1][column] == false && row > 1)
					{
						data[row - 1][column] = 'o';
						istaked[row - 1][column] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column << endl;
						return;
					}
					if (istaked[row + 4][column] == false && row < 7)
					{
						data[row + 4][column] = 'o';
						istaked[row + 4][column] = true;
						cout << "电脑放置棋子的位置是:" << row + 4 << ' ' << column << endl;
						return;
					}
				}

				//to detect the other two cases
				if (data[row + 1][column + 1] == pict && data[row + 2][column + 2] == pict && data[row + 3][column + 3] == pict)
				{
					if (istaked[row - 1][column - 1] == false && column > 1 && row > 1)
					{
						data[row - 1][column - 1] = 'o';
						istaked[row - 1][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row + 4][column + 4] == false && column < 7 && row < 7)
					{
						data[row + 4][column + 4] = 'o';
						istaked[row + 4][column + 4] = true;
						cout << "电脑放置棋子的位置是:" << row + 4 << ' ' << column + 4 << endl;
						return;
					}
				}

				//another case
				if (data[row + 1][column - 1] == pict && data[row + 2][column - 2] == pict && data[row + 3][column - 3] == pict)
				{
					if (istaked[row - 1][column + 1] == false && column < 10 && row>1)
					{
						data[row - 1][column + 1] = 'o';
						istaked[row - 1][column + 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column + 1 << endl;
						return;
					}
					if (istaked[row + 4][column - 4] == false && column > 4 && row < 7)
					{
						data[row + 4][column - 4] = 'o';
						istaked[row + 4][column - 4] = true;
						cout << "电脑放置棋子的位置是:" << row + 4 << ' ' << column - 4 << endl;
						return;
					}
				}
			}
		}

		//The second step to find if there is any continuous three 
			//first for the computer itself
		for (row = 1; row < 11; row++)
		{
			for (column = 1; column < 11; column++)
			{
				pict = data[row][column];
				if (pict == ' ' || pict == '*')
					continue;                           //decide if the place is took by the AI

				//to detect if there is any three in a row continuous and another is ready to win
				if (data[row][column + 1] == pict && data[row][column + 2] == pict)
				{
					if (istaked[row][column - 1] == false && column > 2 && data[row][column - 2] == pict)
					{
						data[row][column - 1] = 'o';
						istaked[row][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row][column + 3] == false && column < 7 && data[row][column + 4] == pict)
					{
						data[row][column + 3] = 'o';
						istaked[row][column + 3] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column + 3 << endl;
						return;
					}
				}

				//to detect if there is any three in a column continuous and another is ready to win
				if (data[row + 1][column] == pict && data[row + 2][column] == pict)
				{
					if (istaked[row - 1][column] == false && row > 2 && data[row - 2][column] == pict)
					{
						data[row - 1][column] = 'o';
						istaked[row - 1][column] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column << endl;
						return;
					}
					if (istaked[row + 3][column] == false && row < 7 && data[row + 4][column] == pict)
					{
						data[row + 3][column] = 'o';
						istaked[row + 3][column] = true;
						cout << "电脑放置棋子的位置是:" << row + 3 << ' ' << column << endl;
						return;
					}
				}

				//to detect the other two cases
				if (data[row + 1][column + 1] == pict && data[row + 2][column + 2] == pict)
				{
					if (istaked[row - 1][column - 1] == false && column > 2 && row > 2 && data[row - 2][column - 2] == pict)
					{
						data[row - 1][column - 1] = 'o';
						istaked[row - 1][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row + 3][column + 3] == false && column < 7 && row < 7 && data[row + 4][column + 4] == pict)
					{
						data[row + 3][column + 3] = 'o';
						istaked[row + 3][column + 3] = true;
						cout << "电脑放置棋子的位置是:" << row + 3 << ' ' << column + 3 << endl;
						return;
					}
				}

				//another case
				if (data[row + 1][column - 1] == pict && data[row + 2][column - 2] == pict)
				{
					if (istaked[row - 1][column + 1] == false && column < 9 && row>2 && data[row - 2][column + 2] == pict)
					{
						data[row - 1][column + 1] = 'o';
						istaked[row - 1][column + 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column + 1 << endl;
						return;
					}
					if (istaked[row + 3][column - 3] == false && column > 4 && row < 7 && data[row + 4][column - 4] == pict)
					{
						data[row + 3][column - 3] = 'o';
						istaked[row + 3][column - 3] = true;
						cout << "电脑放置棋子的位置是:" << row + 3 << ' ' << column - 3 << endl;
						return;
					}
				}
				//now only three continuous
				if (data[row][column + 1] == pict && data[row][column + 2] == pict)
				{
					if (istaked[row][column - 1] == false && column > 1)
					{
						data[row][column - 1] = 'o';
						istaked[row][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row][column + 3] == false && column < 8)
					{
						data[row][column + 3] = 'o';
						istaked[row][column + 3] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column + 3 << endl;
						return;
					}
				}

				//to detect if there is only three in a column continuous
				if (data[row + 1][column] == pict && data[row + 2][column] == pict)
				{
					if (istaked[row - 1][column] == false && row > 1)
					{
						data[row - 1][column] = 'o';
						istaked[row - 1][column] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column << endl;
						return;
					}
					if (istaked[row + 3][column] == false && row < 8)
					{
						data[row + 3][column] = 'o';
						istaked[row + 3][column] = true;
						cout << "电脑放置棋子的位置是:" << row + 3 << ' ' << column << endl;
						return;
					}
				}

				//to detect the other two cases
				if (data[row + 1][column + 1] == pict && data[row + 2][column + 2] == pict)
				{
					if (istaked[row - 1][column - 1] == false && column > 1 && row > 1)
					{
						data[row - 1][column - 1] = 'o';
						istaked[row - 1][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row + 3][column + 3] == false && column < 8 && row < 8)
					{
						data[row + 3][column + 3] = 'o';
						istaked[row + 3][column + 3] = true;
						cout << "电脑放置棋子的位置是:" << row + 3 << ' ' << column + 3 << endl;
						return;
					}
				}

				//another case
				if (data[row + 1][column - 1] == pict && data[row + 2][column - 2] == pict)
				{
					if (istaked[row - 1][column + 1] == false && column < 10 && row>1)
					{
						data[row - 1][column + 1] = 'o';
						istaked[row - 1][column + 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column + 1 << endl;
						return;
					}
					if (istaked[row + 3][column - 3] == false && column > 3 && row < 8)
					{
						data[row + 3][column - 3] = 'o';
						istaked[row + 3][column - 3] = true;
						cout << "电脑放置棋子的位置是:" << row + 3 << ' ' << column - 3 << endl;
						return;
					}
				}
			}
		}

		//to detect if there is any danger of three continuous
		for (row = 1; row < 11; row++)
		{
			for (column = 1; column < 11; column++)
			{
				pict = data[row][column];
				if (pict == ' ' || pict == 'o')
					continue;                           //decide if the place is took by the AI

				//to detect if there is any three in a row continuous and another is ready to win
				if (data[row][column + 1] == pict && data[row][column + 2] == pict)
				{
					if (istaked[row][column - 1] == false && column > 2 && data[row][column - 2] == pict)
					{
						data[row][column - 1] = 'o';
						istaked[row][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row][column + 3] == false && column < 7 && data[row][column + 4] == pict)
					{
						data[row][column + 3] = 'o';
						istaked[row][column + 3] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column + 3 << endl;
						return;
					}
				}

				//to detect if there is any three in a column continuous and another is ready to win
				if (data[row + 1][column] == pict && data[row + 2][column] == pict)
				{
					if (istaked[row - 1][column] == false && row > 2 && data[row - 2][column] == pict)
					{
						data[row - 1][column] = 'o';
						istaked[row - 1][column] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column << endl;
						return;
					}
					if (istaked[row + 3][column] == false && row < 7 && data[row + 4][column] == pict)
					{
						data[row + 3][column] = 'o';
						istaked[row + 3][column] = true;
						cout << "电脑放置棋子的位置是:" << row + 3 << ' ' << column << endl;
						return;
					}
				}

				//to detect the other two cases
				if (data[row + 1][column + 1] == pict && data[row + 2][column + 2] == pict)
				{
					if (istaked[row - 1][column - 1] == false && column > 2 && row > 2 && data[row - 2][column - 2] == pict)
					{
						data[row - 1][column - 1] = 'o';
						istaked[row - 1][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row + 3][column + 3] == false && column < 7 && row < 7 && data[row + 4][column + 4] == pict)
					{
						data[row + 3][column + 3] = 'o';
						istaked[row + 3][column + 3] = true;
						cout << "电脑放置棋子的位置是:" << row + 3 << ' ' << column + 3 << endl;
						return;
					}
				}

				//another case
				if (data[row + 1][column - 1] == pict && data[row + 2][column - 2] == pict)
				{
					if (istaked[row - 1][column + 1] == false && column < 9 && row>2 && data[row - 2][column + 2] == pict)
					{
						data[row - 1][column + 1] = 'o';
						istaked[row - 1][column + 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column + 1 << endl;
						return;
					}
					if (istaked[row + 3][column - 3] == false && column > 4 && row < 7 && data[row + 4][column - 4] == pict)
					{
						data[row + 3][column - 3] = 'o';
						istaked[row + 3][column - 3] = true;
						cout << "电脑放置棋子的位置是:" << row + 3 << ' ' << column - 3 << endl;
						return;
					}
				}
				//now only three continuous
				if (data[row][column + 1] == pict && data[row][column + 2] == pict)
				{
					if (istaked[row][column - 1] == false && column > 1)
					{
						data[row][column - 1] = 'o';
						istaked[row][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row][column + 3] == false && column < 8)
					{
						data[row][column + 3] = 'o';
						istaked[row][column + 3] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column + 3 << endl;
						return;
					}
				}

				//to detect if there is only three in a column continuous
				if (data[row + 1][column] == pict && data[row + 2][column] == pict)
				{
					if (istaked[row - 1][column] == false && row > 1)
					{
						data[row - 1][column] = 'o';
						istaked[row - 1][column] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column << endl;
						return;
					}
					if (istaked[row + 3][column] == false && row < 8)
					{
						data[row + 3][column] = 'o';
						istaked[row + 3][column] = true;
						cout << "电脑放置棋子的位置是:" << row + 3 << ' ' << column << endl;
						return;
					}
				}

				//to detect the other two cases
				if (data[row + 1][column + 1] == pict && data[row + 2][column + 2] == pict)
				{
					if (istaked[row - 1][column - 1] == false && column > 1 && row > 1)
					{
						data[row - 1][column - 1] = 'o';
						istaked[row - 1][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row + 3][column + 3] == false && column < 8 && row < 8)
					{
						data[row + 3][column + 3] = 'o';
						istaked[row + 3][column + 3] = true;
						cout << "电脑放置棋子的位置是:" << row + 3 << ' ' << column + 3 << endl;
						return;
					}
				}

				//another case
				if (data[row + 1][column - 1] == pict && data[row + 2][column - 2] == pict)
				{
					if (istaked[row - 1][column + 1] == false && column < 10 && row>1)
					{
						data[row - 1][column + 1] = 'o';
						istaked[row - 1][column + 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column + 1 << endl;
						return;
					}
					if (istaked[row + 3][column - 3] == false && column > 3 && row < 8)
					{
						data[row + 3][column - 3] = 'o';
						istaked[row + 3][column - 3] = true;
						cout << "电脑放置棋子的位置是:" << row + 3 << ' ' << column - 3 << endl;
						return;
					}
				}
			}
		}

		//The third stage is to detect if there is any two continuous
			//the first is for the computer
		for (row = 1; row < 11; row++)
		{
			for (column = 1; column < 11; column++)
			{
				pict = data[row][column];
				if (pict == ' ' || pict == '*')
					continue;                           //decide if the place is took by the AI

				//to detect if there is any two in a row continuous
				if (data[row][column + 1] == pict)
				{
					if (istaked[row][column - 1] == false && column > 2 && data[row][column - 2] == pict)
					{
						data[row][column - 1] = 'o';
						istaked[row][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row][column + 2] == false && column < 8 && data[row][column + 3] == pict)
					{
						data[row][column + 2] = 'o';
						istaked[row][column + 2] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column + 2 << endl;
						return;
					}
				}

				//to detect if there is any two in a column continuous
				if (data[row + 1][column] == pict)
				{
					if (istaked[row - 1][column] == false && row > 2 && data[row - 2][column] == pict)
					{
						data[row - 1][column] = 'o';
						istaked[row - 1][column] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column << endl;
						return;
					}
					if (istaked[row + 2][column] == false && row < 8 && data[row + 3][column] == pict)
					{
						data[row + 2][column] = 'o';
						istaked[row + 2][column] = true;
						cout << "电脑放置棋子的位置是:" << row + 2 << ' ' << column << endl;
						return;
					}
				}

				//to detect the other two cases
				if (data[row + 1][column + 1] == pict)
				{
					if (istaked[row - 1][column - 1] == false && column > 2 && row > 2 && data[row - 2][column - 2] == pict)
					{
						data[row - 1][column - 1] = 'o';
						istaked[row - 1][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row + 2][column + 2] == false && column < 8 && row < 8 && data[row + 3][column + 3] == pict)
					{
						data[row + 2][column + 2] = 'o';
						istaked[row + 2][column + 2] = true;
						cout << "电脑放置棋子的位置是:" << row + 2 << ' ' << column + 2 << endl;
						return;
					}
				}

				//another case
				if (data[row + 1][column - 1] == pict)
				{
					if (istaked[row - 1][column + 1] == false && column < 9 && row>2 && data[row - 2][column + 2] == pict)
					{
						data[row - 1][column + 1] = 'o';
						istaked[row - 1][column + 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column + 1 << endl;
						return;
					}
					if (istaked[row + 2][column - 2] == false && column > 3 && row < 8 && data[row + 3][column - 3] == pict)
					{
						data[row + 2][column - 2] = 'o';
						istaked[row + 2][column - 2] = true;
						cout << "电脑放置棋子的位置是:" << row + 2 << ' ' << column - 2 << endl;
						return;
					}
				}

				//only two continuous
				if (data[row][column + 1] == pict)
				{
					if (istaked[row][column - 1] == false && column > 1)
					{
						data[row][column - 1] = 'o';
						istaked[row][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row][column + 2] == false && column < 9)
					{
						data[row][column + 2] = 'o';
						istaked[row][column + 2] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column + 2 << endl;
						return;
					}
				}

				//to detect if there is any two in a column continuous
				if (data[row + 1][column] == pict)
				{
					if (istaked[row - 1][column] == false && row > 1)
					{
						data[row - 1][column] = 'o';
						istaked[row - 1][column] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column << endl;
						return;
					}
					if (istaked[row + 2][column] == false && row < 9)
					{
						data[row + 2][column] = 'o';
						istaked[row + 2][column] = true;
						cout << "电脑放置棋子的位置是:" << row + 2 << ' ' << column << endl;
						return;
					}
				}

				//to detect the other two cases
				if (data[row + 1][column + 1] == pict)
				{
					if (istaked[row - 1][column - 1] == false && column > 1 && row > 1)
					{
						data[row - 1][column - 1] = 'o';
						istaked[row - 1][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row + 2][column + 2] == false && column < 9 && row < 9)
					{
						data[row + 2][column + 2] = 'o';
						istaked[row + 2][column + 2] = true;
						cout << "电脑放置棋子的位置是:" << row + 2 << ' ' << column + 2 << endl;
						return;
					}
				}

				//another case
				if (data[row + 1][column - 1] == pict)
				{
					if (istaked[row - 1][column + 1] == false && column < 10 && row>1)
					{
						data[row - 1][column + 1] = 'o';
						istaked[row - 1][column + 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column + 1 << endl;
						return;
					}
					if (istaked[row + 2][column - 2] == false && column > 2 && row < 9)
					{
						data[row + 2][column - 2] = 'o';
						istaked[row + 2][column - 2] = true;
						cout << "电脑放置棋子的位置是:" << row + 2 << ' ' << column - 2 << endl;
						return;
					}
				}
			}
		}

		//now detect if there is any danger of two continuous
		for (row = 1; row < 11; row++)
		{
			for (column = 1; column < 11; column++)
			{
				pict = data[row][column];
				if (pict == ' ' || pict == 'o')
					continue;                           //decide if the place is took by the AI

				//to detect if there is any two in a row continuous
				if (data[row][column + 1] == pict)
				{
					if (istaked[row][column - 1] == false && column > 2 && data[row][column - 2] == pict)
					{
						data[row][column - 1] = 'o';
						istaked[row][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row][column + 2] == false && column < 8 && data[row][column + 3] == pict)
					{
						data[row][column + 2] = 'o';
						istaked[row][column + 2] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column + 2 << endl;
						return;
					}
				}

				//to detect if there is any two in a column continuous
				if (data[row + 1][column] == pict)
				{
					if (istaked[row - 1][column] == false && row > 2 && data[row - 2][column] == pict)
					{
						data[row - 1][column] = 'o';
						istaked[row - 1][column] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column << endl;
						return;
					}
					if (istaked[row + 2][column] == false && row < 8 && data[row + 3][column] == pict)
					{
						data[row + 2][column] = 'o';
						istaked[row + 2][column] = true;
						cout << "电脑放置棋子的位置是:" << row + 2 << ' ' << column << endl;
						return;
					}
				}

				//to detect the other two cases
				if (data[row + 1][column + 1] == pict)
				{
					if (istaked[row - 1][column - 1] == false && column > 2 && row > 2 && data[row - 2][column - 2] == pict)
					{
						data[row - 1][column - 1] = 'o';
						istaked[row - 1][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row + 2][column + 2] == false && column < 8 && row < 8 && data[row + 3][column + 3] == pict)
					{
						data[row + 2][column + 2] = 'o';
						istaked[row + 2][column + 2] = true;
						cout << "电脑放置棋子的位置是:" << row + 2 << ' ' << column + 2 << endl;
						return;
					}
				}

				//another case
				if (data[row + 1][column - 1] == pict)
				{
					if (istaked[row - 1][column + 1] == false && column < 9 && row>2 && data[row - 2][column + 2] == pict)
					{
						data[row - 1][column + 1] = 'o';
						istaked[row - 1][column + 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column + 1 << endl;
						return;
					}
					if (istaked[row + 2][column - 2] == false && column > 3 && row < 8 && data[row + 3][column - 3] == pict)
					{
						data[row + 2][column - 2] = 'o';
						istaked[row + 2][column - 2] = true;
						cout << "电脑放置棋子的位置是:" << row + 2 << ' ' << column - 2 << endl;
						return;
					}
				}

				//only two continuous
				if (data[row][column + 1] == pict)
				{
					if (istaked[row][column - 1] == false && column > 1)
					{
						data[row][column - 1] = 'o';
						istaked[row][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row][column + 2] == false && column < 9)
					{
						data[row][column + 2] = 'o';
						istaked[row][column + 2] = true;
						cout << "电脑放置棋子的位置是:" << row << ' ' << column + 2 << endl;
						return;
					}
				}

				//to detect if there is any two in a column continuous
				if (data[row + 1][column] == pict)
				{
					if (istaked[row - 1][column] == false && row > 1)
					{
						data[row - 1][column] = 'o';
						istaked[row - 1][column] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column << endl;
						return;
					}
					if (istaked[row + 2][column] == false && row < 9)
					{
						data[row + 2][column] = 'o';
						istaked[row + 2][column] = true;
						cout << "电脑放置棋子的位置是:" << row + 2 << ' ' << column << endl;
						return;
					}
				}

				//to detect the other two cases
				if (data[row + 1][column + 1] == pict)
				{
					if (istaked[row - 1][column - 1] == false && column > 1 && row > 1)
					{
						data[row - 1][column - 1] = 'o';
						istaked[row - 1][column - 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column - 1 << endl;
						return;
					}
					if (istaked[row + 2][column + 2] == false && column < 9 && row < 9)
					{
						data[row + 2][column + 2] = 'o';
						istaked[row + 2][column + 2] = true;
						cout << "电脑放置棋子的位置是:" << row + 2 << ' ' << column + 2 << endl;
						return;
					}
				}

				//another case
				if (data[row + 1][column - 1] == pict)
				{
					if (istaked[row - 1][column + 1] == false && column < 10 && row>1)
					{
						data[row - 1][column + 1] = 'o';
						istaked[row - 1][column + 1] = true;
						cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column + 1 << endl;
						return;
					}
					if (istaked[row + 2][column - 2] == false && column > 2 && row < 9)
					{
						data[row + 2][column - 2] = 'o';
						istaked[row + 2][column - 2] = true;
						cout << "电脑放置棋子的位置是:" << row + 2 << ' ' << column - 2 << endl;
						return;
					}
				}
			}
		}

		//now it's for just one isolated

		for (row = 1; row < 11; row++)
		{
			for (column = 1; column < 11; column++)
			{
				pict = data[row][column];
				if (pict == ' ' || pict == 'o')
					continue;

				if (data[row][column - 2] == pict && column > 2 && istaked[row][column - 1] == false)
				{
					data[row][column - 1] = 'o';
					istaked[row][column - 1] = true;
					cout << "电脑放置棋子的位置是:" << row << ' ' << column - 1 << endl;
					return;
				}
				if (data[row][column + 2] == pict && column < 9 && istaked[row][column + 1] == false)
				{
					data[row][column + 1] = 'o';
					istaked[row][column + 1] = true;
					cout << "电脑放置棋子的位置是:" << row << ' ' << column + 1 << endl;
					return;
				}
				if (data[row - 2][column] == pict && row > 2 && istaked[row - 1][column] == false)
				{
					data[row - 1][column] = 'o';
					istaked[row - 1][column] = true;
					cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column << endl;
					return;
				}
				if (data[row + 2][column] == pict && row < 9 && istaked[row + 1][column] == false)
				{
					data[row + 1][column] = 'o';
					istaked[row + 1][column] = true;
					cout << "电脑放置棋子的位置是:" << row + 1 << ' ' << column << endl;
					return;
				}
				if (data[row - 2][column - 2] == pict && row > 2 && column > 2 && istaked[row - 1][column - 1] == false)
				{
					data[row - 1][column - 1] = 'o';
					istaked[row - 1][column - 1] = true;
					cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column - 1 << endl;
					return;
				}
				if (data[row + 2][column + 2] == pict && row < 9 && column < 9 && istaked[row + 1][column + 1] == false)
				{
					data[row + 1][column + 1] = 'o';
					istaked[row + 1][column + 1] = true;
					cout << "电脑放置棋子的位置是:" << row + 1 << ' ' << column + 1 << endl;
					return;
				}

				if (column > 1 && istaked[row][column - 1] == false)
				{
					data[row][column - 1] = 'o';
					istaked[row][column - 1] = true;
					cout << "电脑放置棋子的位置是:" << row << ' ' << column - 1 << endl;
					return;
				}
				if (column < 10 && istaked[row][column + 1] == false)
				{
					data[row][column + 1] = 'o';
					istaked[row][column + 1] = true;
					cout << "电脑放置棋子的位置是:" << row << ' ' << column + 1 << endl;
					return;
				}
				if (row > 1 && istaked[row - 1][column] == false)
				{
					data[row - 1][column] = 'o';
					istaked[row - 1][column] = true;
					cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column << endl;
					return;
				}
				if (row < 10 && istaked[row + 1][column] == false)
				{
					data[row + 1][column] = 'o';
					istaked[row + 1][column] = true;
					cout << "电脑放置棋子的位置是:" << row + 1 << ' ' << column << endl;
					return;
				}
				if (row > 1 && column > 1 && istaked[row - 1][column - 1] == false)
				{
					data[row - 1][column - 1] = 'o';
					istaked[row - 1][column - 1] = true;
					cout << "电脑放置棋子的位置是:" << row - 1 << ' ' << column - 1 << endl;
					return;
				}
				if (row < 10 && column < 10 && istaked[row + 1][column + 1] == false)
				{
					data[row + 1][column + 1] = 'o';
					istaked[row + 1][column + 1] = true;
					cout << "电脑放置棋子的位置是:" << row + 1 << ' ' << column + 1 << endl;
					return;
				}
			}
		}

		//The last one is that there is no other cases

		for (row = 1; row < 11; row++)
		{
			for (column = 1; column < 11; column++)
			{
				if (istaked[row][column] == false)
				{
					data[row][column] = 'o';
					istaked[row][column] = true;
					cout << "电脑放置棋子的位置是:" << row << ' ' << column << endl;
					return;
				}
			}
		}

	}
};
int main()
{
	int decide;
	gobang test;
	test.initthearray();
	test.output();

	while (1)
	{
		cout << "请按（横 竖）坐标放置棋子:";
		test.getposition();

		decide = test.isover();
		switch (decide)
		{
		case -1:
			test.output();
			cout << "游戏结束 平局." << endl;
			return 0;
		case 0:
			break;
		case 1:
			test.output();
			cout << "恭喜你!你赢了!" << endl;
			return 0;
		case 2:
			test.output();
			cout << "笨蛋!你输了!." << endl;
			return 0;

		default:break;
		}

		test.AIsolve();

		decide = test.isover();
		switch (decide)
		{
		case -1:
			test.output();
			cout << "游戏结束 平局." << endl;
			return 0;
		case 0:
			break;
		case 1:
			test.output();
			cout << "恭喜你!你赢了!" << endl;
			return 0;
		case 2:
			test.output();
			cout << "笨蛋!你输了!" << endl;
			return 0;

		default:break;
		}


		test.output();
	}



	return 0;
}
