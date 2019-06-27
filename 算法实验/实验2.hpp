#pragma once

#include <iostream>
using namespace std;
namespace test2 {
	namespace 背包 {

		struct goodinfo
		{
			float p; //物品效益
			float w; //物品重量
			float X; //物品该放的数量
			int flag; //物品编号
		};//物品信息结构体
		void Insertionsort(goodinfo goods[], int n)
		{
			int j, i;
			for (j = 2; j <= n; j++)
			{
				goods[0] = goods[j];
				i = j - 1;
				while (goods[0].p > goods[i].p)
				{
					goods[i + 1] = goods[i];
					i--;
				}
				goods[i + 1] = goods[0];
			}
		}//按物品效益，重量比值做升序排列
		void bag(goodinfo goods[], float M, int n)
		{
			float cu;
			int i, j;
			for (i = 1; i <= n; i++)
				goods[i].X = 0;
			cu = M;  //背包剩余容量
			for (i = 1; i < n; i++)
			{
				if (goods[i].w > cu)//当该物品重量大与剩余容量跳出
					break;
				goods[i].X = 1;
				cu = cu - goods[i].w;//确定背包新的剩余容量
			}
			if (i <= n)
				goods[i].X = cu / goods[i].w;//该物品所要放的量
			for (j = 2; j <= n; j++)
			{
				goods[0] = goods[j];
				i = j - 1;
				while (goods[0].flag < goods[i].flag)
				{
					goods[i + 1] = goods[i];
					i--;
				}
				goods[i + 1] = goods[0];
			}
			cout << "最优解为:" << endl;
			for (i = 1; i <= n; i++)
			{
				cout << "第" << i << "件物品要放:";
				cout << goods[i].X << endl;
			}
		}
		void main_tanxin()
		{
			cout << "|--------运用贪心法解背包问题---------|" << endl;
			cout << "|-------------------------------------|" << endl;
			int j=1;
			int n;
			float M;
			goodinfo *goods;//定义一个指针
			while (j)
			{
				cout << "请输入物品的总数量：";
				cin >> n;
				goods = new struct goodinfo[n + 1];//
				cout << "请输入背包的最大容量：";
				cin >> M;
				cout << endl;
				int i;
				for (i = 1; i <= n; i++)
				{
					goods[i].flag = i;
					cout << "请输入第" << i << "件物品的重量:";
					cin >> goods[i].w;
					cout << "请输入第" << i << "件物品的效益:";
					cin >> goods[i].p;
					goods[i].p = goods[i].p / goods[i].w;//得出物品的效益，重量比
					cout << endl;
				}
				Insertionsort(goods, n);
				bag(goods, M, n);
				cout << "press <1> to run agian" << endl;
				cout << "press <0> to exit" << endl;
				cin >> j;
			}
		}
	}
	namespace prim {
#define INFINITY INT_MAX 
#define MAX_VERTEX_NUM 20 
		typedef int VRType;
		typedef int InfoType;
		typedef char VerTexType;
		typedef struct ArcCell
		{
			VRType adj;
			InfoType *info;
		}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
		typedef struct
		{
			VerTexType vexs[MAX_VERTEX_NUM];
			AdjMatrix arcs;
			int vexnum, arcnum;
		}MGraph;
		typedef struct
		{
			VerTexType adjvex;
			VRType lowcost;
		}closedge[MAX_VERTEX_NUM];

		void CreateGraph(MGraph &G);
		void MiniSpanTree_PRIM(MGraph G, VerTexType u);
		int LocateVex(MGraph G, VerTexType u);
		int minimum(closedge close);
		void main(void)
		{
			int i, j;
			MGraph G;
			CreateGraph(G);
			for (i = 0; i < G.vexnum; i++)
			{
				for (j = 0; j < G.vexnum; j++)
				{
					cout << G.arcs[i][j].adj;
					cout << " ";
				}
				cout << endl;
			}
			MiniSpanTree_PRIM(G, 'a');
		}
		void CreateGraph(MGraph &G)
		{
			int weigh;
			int i, j = 0, k = 0;
			char hand, tide;
			cout << "input the number for vexnum and arcnum:";
			cin >> G.vexnum >> G.arcnum;
			for (i = 0; i < G.vexnum; i++)
			{
				for (j = 0; j < G.vexnum; j++)
					G.arcs[i][j].adj = 88;
			}
			cout << endl;
			cout << "input" << G.vexnum << "char for vexs:";
			for (i = 0; i < G.vexnum; i++)
				cin >> G.vexs[i];
			cout << endl;
			cout << "input" << G.arcnum << "arc(char,char,weigh):" << endl;
			j = 0;
			k = 0;
			for (i = 0; i < G.arcnum; i++)
			{
				cout << i << ":";
				cin >> hand;
				cin >> tide;
				cin >> weigh;
				while (hand != G.vexs[j])
					j++;
				while (tide != G.vexs[k])
					k++;
				G.arcs[j][k].adj = weigh;
				G.arcs[k][j].adj = weigh;
				j = 0;
				k = 0;
				cout << endl;
			}
		}
		void MiniSpanTree_PRIM(MGraph G, VerTexType u)
		{
			int i, j, k = 0;
			closedge close;

			k = LocateVex(G, u);
			for (j = 0; j < G.vexnum; j++)
			{
				if (j != k)
				{
					close[j].adjvex = G.vexs[k];
					close[j].lowcost = G.arcs[k][j].adj;
				}
			}
			close[j].lowcost = 88;
			close[j].adjvex = '\0';
			close[k].lowcost = 0;
			close[k].adjvex = u;
			for (i = 1; i < G.vexnum; i++)
			{
				k = minimum(close);
				cout << close[k].adjvex;
				cout << "---->";
				cout << G.vexs[k] << " ";
				cout << close[k].lowcost << endl;
				close[k].lowcost = 0;
				for (j = 0; j < G.vexnum; j++)
				{
					if (G.arcs[k][j].adj < close[j].lowcost)
					{
						close[j].adjvex = G.vexs[k];
						close[j].lowcost = G.arcs[k][j].adj;
					}
				}
			}
		}
		int LocateVex(MGraph G, VerTexType u)
		{
			int k = 0;
			while (G.vexs[k++] == u)
				return k - 1;
			return 0;
		}
		int minimum(closedge close)
		{
			int j1 = 0, client = 88, j2;
			while (close[j1].adjvex != '\0')
			{
				if (client > close[j1].lowcost && close[j1].lowcost != 0)
				{
					client = close[j1].lowcost;
					j2 = j1;
				}
				j1++;
			}
			return j2;
		}
	}
}