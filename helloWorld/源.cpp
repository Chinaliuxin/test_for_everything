#include <iostream>
#include<cstdio>
using namespace std;
int quickSortPart(int a[], int left, int right)
{
	int temp = a[right];
	while (left < right)
	{
		while (left < right&&a[left] < temp)
		{
			left++;
		}
		a[right] = a[left];
		while (left < right&&a[right] >= temp)
		{
			right--;
		}
		a[left] = a[right];
	}
	a[right] = temp;
	return right;
}
void quickSort_(int a[], int left, int right)
{
	if (left < right)
	{
		int mid = quickSortPart(a, left, right);
		quickSort_(a, left, mid - 1);
		quickSort_(a, mid + 1, right);
	}
}


#include<vector>
class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		// write code here
		vector<int> ret;
		for (int k = 0; k <= n - 1; k++)//kÊÇsize
		{
			int max1 = 0x80000000;
			int max2 = 0x80000000;
			for (int i = 0; i < k; i++)
			{
				if (A[i] > max1)
					max1 = A[i];
			}
			for (int i = k; i <= n - 1; i++)
			{
				if (A[i] > max2)
					max2 = A[i];
			}
			int r = max1 > max2 ? max1 - max2 : max2 - max1;
			ret.push_back(r);

		}
		int returnIt = ret[0];
		for (auto e : ret)
		{
			returnIt = e > returnIt ? e : returnIt;
		}
		return returnIt;
	}
	};

const char* myStrStr( const char * str,const char* des)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		int j = 0;
		int temp = i;
		if (str[i] == des[j])
		{
			while (str[i] == des[j])
			{
				i++;
				j++;
				if (des[j] == '\0')
					return &str[i - j];
			}
		}
		i = temp;
	}
	return nullptr;
}
int main()
{
	MaxGap s;
	vector<int > a = { 2,7,3,1,1 };
	//cout<<s.findMaxGap(a, a.size());
	int cc = INT_MIN;
	char str[]="fff12312361234512345612343";
	char des[]= "123456";
	const char * hh = myStrStr(str, des);
	printf("%p\n", myStrStr(str, des));
	printf("%p\n", strstr(str, des));

	printf("%s", hh);
	printf("%s\n", strstr(str, des));

	int b = 0x80000000;
	printf("%d", b);


	return 0;
}
