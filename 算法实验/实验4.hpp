#pragma once
namespace test4 {
	namespace Nqueens {
#include <stdio.h>
#include <math.h>
		/*检查可不可以放置一个新的皇后*/
		bool place(int k, int *X)
		{
			int i;
			i = 1;
			while (i < k)
			{
				if ((X[i] == X[k]) || (abs(X[i] - X[k]) == abs(i - k))) //两个皇后不在同行/列/对角线
					return false;
				i++;
			}
			return true;
		}
		void Nqueens(int n, int *X)
		{//k表示所处理的是第k行的皇后，X[k]表示第k行皇后的列位置
			int k;
			X[1] = 0;
			k = 1;
			while (k > 0)
			{
				X[k] = X[k] + 1; //从当前列加1的位置开始搜索
				while ((X[k] <= n) && (!place(k, X))) //当前列位置是否满足条件
					X[k] = X[k] + 1; //不满足条件,继续搜索下一列位置
				if (X[k] <= n) //存在满足条件的列
				{
					if (k == n) //是最后一个皇后,完成搜索
					{
						for (int i = 1; i <= n; i++) //输出各行皇后的列位置
							printf("%d ", X[i]);
						printf("\n");
					}
					else
					{
						k = k + 1; //不是最后一个,则处理下一个皇后
						X[k] = 0; //下一列的皇后所在列位置置0
					}
				}
				else
				{//已判断完n列，均未能满足条件
					X[k] = 0; //当前行复位为0
					k = k - 1; //回溯到前一列
				}
			}
		}
		void main()
		{
			int n, i=1;
			int *X;
			printf("|--------------THE N QUEENS PROBLEM--------------|\n");
			printf("|------         edited by Jill Chih        ------|\n");
			printf("|------------------------------------------------|\n\n");
			while (i)
			{
				printf("Please input the sum of Queens:\n");
				cin >> n;//scanf("%d", &n);
				X = new int[n];
				printf("The solutions are:\n");
				Nqueens(n, X);
				printf("Press <1> to run again\n");
				printf("Press <0> to exit\n");
				cin >> i;
				//				scanf("%d", &i);
			}
		}
	}
}