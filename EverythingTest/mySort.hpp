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
	void adjustHeap(int a[], int i, int size)
	{
		//int max;
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int max = i;
		//vs 2017 会检测&&右边的，故不能将l < size&& a[l] > a[max]书写
		if (l < size) {
			if ( a[l] > a[max])
				max = l;
		}
		if (r < size) {
			if ( a[r] > a[max])
				max = r;
		}
		if (max != i)
		{
			swap(a[i], a[max]);
			adjustHeap(a, max, size);
		}
	}
	void heapSort(int a[],int size)
	{
		for (int i = size / 2 - 1; i >=0; i--)
		{
			adjustHeap(a, i, size);
		}
		for (int i = size-1;i >= 0; i--)
		{
			swap(a[0], a[i]);
			adjustHeap(a, 0, i);
		}
	}


#if 0//屏蔽
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
			quick_sort(a, mid + 1, last);//尾递归，还是普通递归
		}

	}
#endif

	int BinFind(int a[], int size,int key)//升序2分查找
	{
		int left = 0;
		int right =size - 1;

		while (left <= right)
		{
			int mid = (left + right) >> 1;
			if (a[mid] < key)
				left = mid + 1;
			if (a[mid] > key)
				right = mid - 1;
			if (a[mid] == key)
				return mid;
		}
		return -1;
	}
	void testSysSort()
	{
		//vector<int> a = {1,8,2,890,102,-3,90,98 };
		//std::sort(a.begin(),a.end() ,mygreater<int>());
		//std::sort(a.begin(), a.end(), std::less<int>());
		//for (auto e : a)
		//{
		//	cout << e<<",";
		//}
		//cout<<"\n";
		//int arrary[]= { 1,8,2,890,102,-3,90,98 };
		//int rightIndex = sizeof(arrary) /sizeof(arrary[0]) - 1;
		//quickSort(arrary, 0, rightIndex);
		//for (auto e:arrary)
		//{
		//	cout << e<<",";
		//}
		int a[] = { 1,2,3,4,5,6,7,7,8,8,9,9,9 };
		cout << BinFind(a, sizeof(a) / sizeof(a[0]), 7) << endl;

		int a3[8] = { 1,8,2,890,102,-3,90,98 };
		heapSort(a3, 8);
		for (auto e:a3)
		{
			cout << e<<",";
		}
	}

}