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



int main()

{
	testMypoint();//函数栈帧调用结束，t1的生命周期结束，new的vector 自动释放

	testSharePtr();
	

	//testPriorityQueue();
	//testMystack();
	//test_vector();
	//test_template();
	//mystack::test_solu_stack();
	//mysort::testSysSort();
	int a;
}