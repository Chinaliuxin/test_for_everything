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

int main()

{
	D::test();

	//testVector_zero();
	//testMypoint();//函数栈帧调用结束，t1的生命周期结束，new的vector 自动释放
	//testString0318();
	//testSharePtr();
	

	//testPriorityQueue();
	//testMystack();
	//test_vector();
	//test_template();
	//mystack::test_solu_stack();
	//mysort::testSysSort();
	int a;
	int &b = a;
}
