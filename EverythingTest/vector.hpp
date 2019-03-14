#pragma once

#include<algorithm>

#include<vector>


void test_vector()
{

	vector <int> v{ 1,2,2,2,35,5 };
	string s1;
	s1.resize(10);
	transform(v.begin(), v.end(), s1.begin(), [](int i)->char{
		if (i % 2 == 0)i++;
		i=i%10;

		return i+'0' ; });
	int ret=atoi(s1.c_str());
	vector<int> v1;
	v1.reserve(10);
	//transform(v.begin(), v.end(), v.begin(), [](int i) -> int{
	//	if (i >2)
	//		return --i;
	//	else
	//		return i;
	//});
	for (auto e : v)
	{
		printf("%d->",e);
	}
	cout << ret;
}