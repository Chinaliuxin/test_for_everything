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
}	
vector<int>& vector_zero(vector <int> &v)
{
	vector<int>* b=new vector<int>();
	int count = 0;
	for (auto &e : v)
	{
		if (e == 0)
			count++;
		else
			b->push_back(e);
	}
	for (int i = 0; i < count; i++)
	{
		b->push_back(0);
	}
	return *b;
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