
#include"ʵ��1.hpp"
#include"ʵ��2.hpp"
#include"ʵ��3.hpp"
#include"ʵ��4.hpp"
void test_1()
{
	/* ʵ��1   �����鲢�����Ӽ����鲢*/
	cout << "-----------------�Ӽ�----------" << endl;
	test1::perm::main_Perm();
	cout << "-----------------����----------" << endl;
	test1::quicksort::main_quicksort();
	cout << "-----------------�鲢----------" << endl;
	//test1::merge::main_merge();
}

void test_2()
{
	cout << "----------------̰�ı���----------" << endl;
	test2::����::main_tanxin();

	cout << "-----------prim-----------------" << endl;
	test2::prim::main();
}
void test_3()
{
	cout << "-----------���ͼ----------" << endl;

	test3::���ͼ::main();


}
void test_4()

{
	cout << "-----------N�ʺ�����----------" << endl;
	test4::Nqueens::main();


}
int main()
{

	//test_1();//ʵ��1
	//test_2();//ʵ��2
	//test_3();//ʵ��3
	test_4();//ʵ��4

	cout << "end" << endl;

}