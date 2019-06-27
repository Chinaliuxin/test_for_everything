
#pragma once
namespace test3 {
	namespace 多段图 {
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#define MAX_VERTEX_NUM 50
		typedef struct ArcNode
		{
			int adjvex; //该弧所指向的顶点的位置
			int value;  //该结点与邻接结点间的代价
			struct ArcNode *nextarc; //指向下一条弧的指针
		}ArcNode, *node;

		typedef struct VNode
		{
			int data; //顶点信息
			ArcNode *firstArc; //指向第一条依附该顶点的弧的指针
		}VNode, AdjList[MAX_VERTEX_NUM];

		typedef struct Graph
		{
			AdjList vertices;
			int vexnum, arcnum; //图的当前顶点数和弧数
		}*ALGraph;
		int build_adList(ALGraph G, int n, int a)
		{ //建立邻接表
			int v, m, i, t, h;
			node p, q;
			if (n < 0) return printf("ERROR");
			G->vexnum = n; //图的顶点数
			if (a < 0) return printf("ERROR");
			G->arcnum = a; //图的弧数
			for (m = 0; m < n; m++)
			{
				G->vertices[m].data = m;
				G->vertices[m].firstArc = NULL;
			}
			for (m = 1; m <= a; m++)
			{
				i = 1;
				printf("输入第%d条弧:", m);
				cin >> t >> h >> v;
				//scanf("%d,%d,%d", &t, &h, &v);
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = h;
				p->value = v;
				p->nextarc = NULL;
				while (G->vertices[i].data != t) i++; //转到下一个结点
				if (!G->vertices[i].firstArc) //终点
					G->vertices[i].firstArc = p;
				else
				{ //若当前结点有后继节点则后移
					for (q = G->vertices[i].firstArc; q->nextarc; q = q->nextarc);
					q->nextarc = p; //新开辟结点
				}
			}
			return v;
		}
		void print_Graph(ALGraph G)
		{ //打印邻接表
			ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
			int i;
			for (i = 1; i < G->vexnum; i++)
			{
				p = G->vertices[i].firstArc;
				printf("[%d]", i);
				while (p)
				{
					printf("->%d,%d", p->adjvex, p->value);//第i个结点的邻接结点信息
					p = p->nextarc;
				}
				printf("\n");
			}
		}

		void fgraph(ALGraph G, int k, int n)
		{ //多段图ALGraph G，n为结点数，k为图的段数
		  //输入是按段的顺序给结点编号
			int cost[100];
			int d[100];
			int path[100];
			int j, r, i, min, w, value;
			node p;
			cost[n] = 0;
			for (j = n - 1; j >= 1; j--) //向前处理结点
			{
				p = G->vertices[j].firstArc;
				min = p->value + cost[p->adjvex]; //初始化路径最小代价
				r = p->adjvex;
				value = p->value;
				while (p != NULL)
				{ //r是一个的这样的结点，权值c(j,r)+cost[r]取最小值
					if ((p->value + cost[p->adjvex]) < min)
					{
						min = p->value + cost[p->adjvex]; //p->value=c(j,r)
						r = p->adjvex;
						value = p->value;
					}
					p = p->nextarc;
				}
				cost[j] = value + cost[r]; //当前节点的代价值
				d[j] = r; //决策阶段，各结点到终点最小代价路径上前方顶点的编号
			}
			path[1] = 1; path[k] = n;
			for (i = 2; i <= k - 1; i++) //找出最小代价路径上的结点
				path[i] = d[path[i - 1]];
			printf("最小成本为:%d\n", cost[1]);
			printf("最小成本路径为: ");
			for (w = 1; w <= k; w++)
				printf("%d->", path[w]);
		}
		void main()
		{
			ALGraph g;
			int n, a, k;
			g = (ALGraph)malloc(sizeof(ALGraph));
			printf("请输入多段图节点数目:");
			cin >> n;
			//scanf("%d", &n);
			printf("请输入多段图边的数目:");
			cin >> a;
			//scanf("%d", &a);
			printf("请输入多段图的段数:");
			cin >> k;
			//scanf("%d", &k);
			printf("输入多段图的弧的信息（弧头，弧尾，权值）\n");
			build_adList(g, n, a);
			printf("多段图的邻接表为:\n");
			print_Graph(g);
			fgraph(g, k, n);
		
		}
	}
}
