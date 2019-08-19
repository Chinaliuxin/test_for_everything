#pragma once

#include<algorithm>

#include<vector>


void test_vector()
{

	vector <int> v{ 1,2,3,4,5,6,7 };

	//cout << *(v.rbegin()++);
	printf("%d", sizeof(v));


	printf("\n-------------------------\n");
	string s1;
	s1.resize(10);
	transform(v.begin(), v.end(), s1.begin(), [](int i)->char{
		if (i % 2 == 0)i++;
		i=i%10;

		return i+'0' ; });
	int ret=atoi(s1.c_str());
	vector<int> v1;
	v1.reserve(10);
	transform(v.begin(), v.end(), v.begin(), [](int i) -> int{
		if (i >2)
			return --i;
		else
			return i;
	});
	for (auto e : v)
	{
		printf("%d->",e);
	}
	cout << ret;
	v1.reserve(20);
	v1.resize(18);
	cout << "v1的容量" << v1.capacity() << "\n";
	cout << "v1的size" << v1.size();

}	
vector<int> vector_zero(vector <int> &v)//把数组中的0后移
{
	vector<int>b;
	int count = 0;
	for (auto &e : v)
	{
		if (e == 0)
			count++;
		else
			b.push_back(e);
	}
	for (int i = 0; i < count; i++)
	{
		b.push_back(0);
	}
	return b;
}
void testVector_zero()
{
	vector<int> v = { 0,1,24,5,0,34,0,45,0,3 };
	v=vector_zero(v);
	for (auto e : v)
	{
		cout << e;
	}
	v.clear();
	vector<int>().swap(v);
	//v.shrink_to_fit();

}
void  array_point()
{
	int a[] = { 1,2,3,4,5 };
	int* p[] = { a,a + 1,a + 2,a + 2 };
	int **q = p;
	cout << *(p[0] + 1) << endl;
	cout << **(q + 2);
	long long a1 = 3;
	printf("%d", a1);

}

vector<vector<int> > subsets(vector<int>& v)//求数组的子集,全排列
{
	int max =1<< v.size();//比如3个数字的数组  max变为8，
	vector< vector<int> > ret;

	for (int i = 0; i < max; i++)
	{
		vector<int>temp;
		int index = 0;
		int flag = i;//flag负责遍历数组，从000，001,010，到111
		while (flag > 0)
		{
			if (flag & 1)//和00000--01与取得最低位
			{
				temp.push_back(v[index]);
			}
			index++;
			flag = flag >> 1;
		}
		ret.push_back(temp);
	}
	return ret;

}
void testSubSet()//求一个数组的子集
{
	vector<int > v = { 1,2,3,4,5};
	vector<vector<int> > ret=subsets(v);
	for (auto &e : ret)
	{
		cout << "{";
		for (auto &ee : e)
		{
			if (ee != *(e.end()-1))
				cout << ee << ",";
			else
				cout << ee;
		}
		cout << "}"<<endl;
	}
	int k = 0;
	for (auto e : ret)
	{
		int temp = 1;
		for (auto ee : e)
		{
			temp = temp * ee;
			
		}
		if (temp < 50)
			k++;
	}
	cout << "----------------------\n "<< k-1;
}

void reverseOddAndEven(vector<int> & v)//把奇数放数组前面，偶数放后面

{
	int left = 0;
	int right = v.size() - 1;
	while (left < right)
	{
		while ((v[left] & 1 )== 1)//奇数最低位为1
			left++;
		while ((v[right] & 1) == 0)
			right--;
		int temp = v[left];
		v[left] = v[right];
		v[right] = temp;
	}
}
void testreverseOddAndEven()
{
	vector<int> v = { 1,2,3,4 };

	reverseOddAndEven(v);
	for (auto e : v)
	{
		cout << e;
	}

}
void getvector132(vector<int>& v)
{
	int size = v.size();
	for (int i = 0; i < size - 2; i++)
	{
		for (int j = i + 1; j < size - 1; j++)
		{
			for (int k = j + 1; k < size; k++)
				cout << "{" << v[i] << "," << v[j] << "," << v[k] << "}" << endl;
		}
	}
}


int binFind(vector<int> a, int key)
{
	int left = 0;
	int right = a.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (left <= right && key > a[mid])
		{
			left= mid+1;
		}
		if (left <= right && key < a[mid])
		{
			right=mid-1;
		}
		else
			return mid;
	}
	return -1;

}
void testgetvector132()
{
	int a[] = { 1,2,4,34,4 };
	sort(a, a+4);
	vector<int> v = { 1,2,3,4,4,6};
	getvector132(v);
}