#include <iostream>
#include<mutex>
#include"template.hpp"
#include"stringAndList.hpp"
#include"stackAndQueue.hpp"
#include"mySort.hpp"
#include"Tree.hpp"
#include"vector.hpp"
#include"priority_queue.hpp"
#include"smartPoint.hpp"
#include<deque>
#include"Derived.hpp"
#include"leetcodeString.hpp"
void main1() {
	string s1, s2;
	string out;
	cin >> s1 >> s2;
	char *ss1;
	char*ss2;
	int N = s1.size() - 1;
	int M = s2.size() - 1;//M,N指向string最后一个元素
	int carry = 0;
	int sum = 0;
	while (N >= 0 || M >= 0)
	{

		int data1 = N >= 0 ? (s1[N])-'0' : 0;
		int data2 = M >= 0 ? s2[M]-'0' : 0;
		sum = data1 + data2 + carry;
		carry = sum > 9 ? 1 : 0;
		sum = sum > 9? sum - 10: sum;
		out.push_back(sum+'0');
		M--;
		N--;
	}
	if (carry == 1)
		out.push_back('1');
	reverse(out.begin(), out.end());
	cout << out;
}
struct lll{
	int a;
	int b;
};

int main()
{
	//printf("error%s", strerror(errno));
	//void fun(int, int);
	//void (*pf) (int d,int);
	//pf = fun;
	vector<struct lll> v;
	const char* ssr = "12345";
	cout << mystrlen(ssr);
	v.resize(1);
	v[0].a = 1;
	v[0].b = 2;
	string s ="123";
	//findOnlyOne();
	teststringAdd20();
	//test_list1();
	//main1();
	//D::test();

	//testVector_zero();
	//testMypoint();//函数栈帧调用结束，t1的生命周期结束，new的vector 自动释放
	//testString0318();
	//testSharePtr();
	
//	array_point();
	//testPriorityQueue();
	//testMystack();
	//test_vector();
	//test_template();
	//mystack::test_solu_stack();
	//mysort::testSysSort();
	//struct union1  n111;
	//poly::test();
	//testreverseOddAndEven();
	int a=3;
	//if (++a = 4)
	//{
	//	cout <<sizeof(n111);
	//}
	cout << "1111111111111111111111" << "\n";
	testgetvector132();
	char st[] = "S\066\nAB";
	char d[] = { '1','2','35' };
	cout << sizeof(st) << endl<<strlen(st)<<strlen(d);
	//testSubSet();
	int &b = a;
}
