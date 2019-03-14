#pragma once
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

namespace mysort {

	template <class T>
	struct mygreater
	{
		bool operator()(const T& a, const T& b)
		{
			return a > b;
		}
	};
	int quickSortPart(int a[],int left,int right)
	{

		int temp = a[right];
		while (left<right)
		{
			while (left<right&&a[left]<temp )
			{
				left++;
			}
			a[right] = a[left];
			while (left < right&&a[right] >=temp)
			{
				right--;
			}
			a[left] = a[right];
		}
		a[right] = temp;
		return right;
	}
	void quickSort(int a[], int left, int right)
	{
		if (left<right)
		{
			int mid = quickSortPart(a, left, right);
			quickSort(a, left, mid - 1);
			quickSort(a, mid + 1, right);
		}

	}
	void adjustHeap()
	{
		//int max;
		
	}

#if 0//∆¡±Œ
	int quick_sort_part(int *a, int first, int last)
	{
		int temp = a[last];
		while (first < last)
		{
			while (a[first] >= temp && first < last)
			{
				first++;
			}
			a[last] = a[first];
			while (a[last] <= temp && first < last)
			{
				last--;
			}
			a[first] = a[last];


		}

		a[last] = temp;
		return first;
	}
	void quick_sort(int *a, int first, int last)
	{
		if (last > first)
		{
			int mid = quick_sort_part(a, first, last);
			quick_sort(a, first, mid - 1);
			quick_sort(a, mid + 1, last);//Œ≤µ›πÈ£¨ªπ «∆’Õ®µ›πÈ
		}

	}
#endif

	void testSysSort()
	{
		vector<int> a = {1,8,2,890,102,-3,90,98 };
		std::sort(a.begin(),a.end() ,mygreater<int>());
		std::sort(a.begin(), a.end(), std::less<int>());
		for (auto e : a)
		{
			cout << e<<",";
		}
		cout<<"\n";
		int arrary[]= { 1,8,2,890,102,-3,90,98 };
		int rightIndex = sizeof(arrary) /sizeof(arrary[0]) - 1;
		quickSort(arrary, 0, rightIndex);
		for (auto e:arrary)
		{
			cout << e<<",";
		}
	}
}