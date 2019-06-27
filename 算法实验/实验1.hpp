#pragma once


#include <iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;
namespace test1 {
	namespace perm {
		void Perm(int list[], int k, int m)
		{
			if (k == m)
			{
				for (int i = 0; i <= m; i++)
					cout << list[i] << " ";
				cout << endl;
			}
			else
				for (int j = k; j <= m; j++)
				{
					swap(list[k], list[j]);   ///自行编写
					Perm(list, k + 1, m);
					swap(list[k], list[j]);
				}
		}

		int main_Perm()
		{
			int list[] = { 1,2,3,4,5,6 };
			Perm(list, 0, 3);
			return 0;
		}
	}

	namespace merge {
		int const M = 11;
		typedef int KeyType;
		typedef int ElemType;
		struct rec {
			KeyType key;
			ElemType data;
		};
		typedef rec sqlist[M];
		class guibing {
		public:
			guibing(sqlist b)
			{
				for (int i = 0; i < M; i++)
					r[i] = b[i];
			}
			void output(sqlist r, int n)
			{
				for (int i = 0; i < n; i++)
					cout << setw(4) << r[i].key;
				cout << endl;
			}
			void xuanze(sqlist b, int m, int n)
			{
				int i, j, k;
				for (i = m; i < n - 1; i++)
				{
					k = i;
					for (j = i; j < n; j++)
						if (b[k].key > b[j].key) k = j;
					if (k != i)
					{
						rec temp = b[k];
						b[k] = b[i];
						b[i] = temp;
					}
				}
			}
			void merge(int l, int m, int h, sqlist r2)
			{
				xuanze(r, l, m);
				xuanze(r, m, h);
				output(r, M);
				int i, j, k;
				k = i = l;
				for (j = m; i < m&&j < h; k++)
				{
					if (r[i].key <= r[j].key)
					{
						r2[k] = r[i];
						i++;
					}
					else
					{
						r2[k] = r[j];
						j++;
					}
					output(r2, M);
				}
				while (j < h)
				{
					r2[k] = r[j];
					j++;
					k++;
				}
				while (i <= m)
				{
					r2[k] = r[i];
					i++;
					k++;
				}
				output(r2, M);
			}
		private:
			sqlist r;
		};
		int  main_merge()
		{
			cout << "guibingfa1运行结果:\n";
			sqlist a, b;
			int i, j = 0, k = M / 2, n = M;
			srand(time(0));
			for (i = 0; i < M; i++)
			{
				a[i].key = rand() % 80; b[i].key = 0;
			}
			guibing gx(a);
			cout << "排序前数组:\n";
			gx.output(a, M);
			cout << "数组排序过程演示:\n";
			gx.merge(j, k, n, b);
			cout << "排序后数组:\n";
			gx.output(b, M);
			return 0;
		}


	}
	namespace quicksort {

#define MAXI 10
		typedef int KeyType;
		typedef int ElemType;
		struct rec {
			KeyType key;
			ElemType data;
		};
		typedef rec sqlist[MAXI];
		class kuaisu
		{
		public:
			kuaisu(sqlist a, int m) :n(m)
			{
				for (int i = 0; i < n; i++) b[i] = a[i];
			}
			void quicksort(int s, int t)
			{
				int i;
				if (s < t) {
					i = part(s, t);
					quicksort(s, i - 1);
					quicksort(i + 1, t);
				}
				else return;
			}
			int part(int s, int t)
			{
				int i, j;
				rec p;
				i = s; j = t; p = b[s];
				while (i < j)
				{
					while (i < j&&b[j].key >= p.key)j--;
					b[i] = b[j];
					while (i < j&&b[i].key <= p.key)i++;
					b[j] = b[i];
				}
				b[i] = p;
				output();
				return i;
			}
			void output()
			{
				for (int i = 0; i < n; i++)
					cout << setw(4) << b[i].key;
				cout << endl;
			}
		private:
			sqlist b;
			int n;
		};

		void main_quicksort()
		{
			cout << "kuaisu1.cpp运行结果:\n";
			sqlist a1;
			int i, n = MAXI, low = 0, high = 9;
			srand(time(0));
			for (i = 0; i < n; i++)
				a1[i].key = rand() % 80;
			kuaisu px(a1, n);
			cout << "数组排序过程演示:\n";
			px.quicksort(low, high);
			cout << "排序后数组:\n";
			px.output();
			cin.get();
		}
	}
}