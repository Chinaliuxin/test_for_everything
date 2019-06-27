
#include"实验1.hpp"
#include"实验2.hpp"
#include"实验3.hpp"
#include"实验4.hpp"
void test_1()
{
	/* 实验1   包括归并，求子集，归并*/
	cout << "-----------------子集----------" << endl;
	test1::perm::main_Perm();
	cout << "-----------------快排----------" << endl;
	test1::quicksort::main_quicksort();
	cout << "-----------------归并----------" << endl;
	//test1::merge::main_merge();
}

void test_2()
{
	cout << "----------------贪心背包----------" << endl;
	test2::背包::main_tanxin();

	cout << "-----------prim-----------------" << endl;
	test2::prim::main();
}
void test_3()
{
	cout << "-----------多段图----------" << endl;

	test3::多段图::main();


}
void test_4()

{
	cout << "-----------N皇后问题----------" << endl;
	test4::Nqueens::main();


}
int main()
{

	//test_1();//实验1
	//test_2();//实验2
	//test_3();//实验3
	test_4();//实验4

	cout << "end" << endl;

}