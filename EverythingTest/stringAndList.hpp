#pragma once
#pragma once
#include<iostream>
#include<string>
using namespace std;
class big {
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
auto big = [](int a, int b)->bool {return a > b; };
auto less = [](int a, int b)->bool {return a < b; };

//仿函数和lambda表达式

//list结点
class listNode {
public:
	listNode(int data) :data(data), next(nullptr) {}
	listNode(const listNode& l) = delete;
	listNode& operator=(const listNode& l) = delete;

	int data;
	listNode* next;
};
typedef listNode* PNode;

class mylist {
public:
	mylist() :phead(nullptr)
	{
		//cout << "开始构造" << endl;
	}
	mylist(mylist & l) = delete;
	mylist& operator = (const mylist& l) = delete;
	void push_back(int data)
	{
		listNode* newnode = new listNode(data);
		if (phead == nullptr)
		{
			phead = newnode;
			return;
		}
		PNode pcur = phead;
		while (pcur->next != nullptr)
			pcur = pcur->next;
		pcur->next = newnode;
	}
	void pop_back()
	{
		if (nullptr == phead)
			return;
		if (nullptr == phead->next)
		{
			delete(phead->next);//
			return;
		}
		auto pcur = phead;
		while (pcur->next->next != nullptr)
			pcur = pcur->next;
		delete(pcur->next);
		pcur->next = nullptr;

	}
	void push_front(int data)
	{
		PNode newnode = new listNode(data);
		if (phead == nullptr)
		{
			phead = newnode;
			return;
		}
		else
		{
			newnode->next = phead;
			phead = newnode;
		}

	}
	void pop_front()
	{
		if (phead == nullptr)
			return;
		if (phead->next == nullptr)
		{
			delete phead;
			phead = nullptr;
			return;
		}
		PNode pcur = phead->next;
		PNode pdel = phead;
		delete(pdel);
		pdel = nullptr;
		phead = pcur;

	}
	void print()
	{
		PNode pcur = phead;
		while (pcur != nullptr)
		{
			printf("%d--->", pcur->data);
			pcur = pcur->next;
		}
		cout << "nullptr";
	}

	~mylist()
	{//析构
		_destroy();
	}
	PNode getPhead()
	{
		return this->phead;
	}
	void setPhead(PNode& p)
	{
		phead = p;
	}
private:
	void _destroy()
	{
		while ((phead) != nullptr)
		{
			PNode pcur = phead;
			phead = pcur->next;
			delete(pcur);
		}
	}
private:
	PNode phead;
};

void print(PNode& phead)
{
	PNode pcur = phead;
	while (pcur != nullptr)
	{
		printf("%d--->", pcur->data);
		pcur = pcur->next;
	}
	cout << "nullptr";
}
class Solutionlist {
public:
	PNode listAdd(mylist& const list1, mylist& const list2)
	{
		PNode l1 = list1.getPhead();//是list one的缩写，不要看错
		PNode l2 = list2.getPhead();
		listNode* dummy = new listNode(-1);//利用哑结点，避免list传入空的情况
		listNode* cur = dummy;
		int carry = 0;//进位
		int sum = 0;// 对应位数
		while (l1 || l2)//l1或者l2不为空就一直循环，（不为空表示还有数字）
		{
			int data1 = (l1 ? l1->data : 0);
			int data2 = (l2 ? l2->data : 0);
			sum = data1 + data2 + carry;
			carry = sum / 10;
			cur->next = new listNode(sum % 10);//sum取值在0-18之间（0+0---9+9）
			cur = cur->next;
			if (l1 != nullptr)
			{
				l1 = l1->next;
			}
			if (l2 != nullptr)
			{
				l2 = l2->next;
			}

		}
		if (carry)
		{
			cur->next = new listNode(1);
		}
		return dummy->next;

	}
};
//进制转换
void test_zhuanhaun()
{
	int n = 16;//n是进制
	int num = 12345;
	string s, table = "0123456789ABCDEF";
	while (num != 0)
	{
		s += table.at(num%n);
		num = num / n;
	}
	reverse(s.begin(), s.end());
	cout << endl;
	cout << s;

}


void test_list1()
{
	//mylist l;
	//l.push_back(1);
	////l.push_back(2);
	//l.pop_back();
	//l.print();
	//mylist* l2=new mylist();
	//l2->push_back(222);
	//l2->push_back(43467);
	//l2->push_back(325);

	//l2->print();
	//mylist* l3 = new mylist();
	//l3->push_front(1);
	//l3->push_front(2);
	//l3->push_front(3);
	//l3->pop_front();
	//l3->pop_front();
	//l3->pop_front();
	//l3->print();
}
void testListAdd()
{
	mylist listOne, listTwo;
	listOne.push_back(1);
	listOne.push_back(2);
	listOne.push_back(2);
	listOne.push_back(3);

	listTwo.push_back(2);
	listTwo.push_back(1);
	listTwo.push_back(3);
	listTwo.push_back(8);

	Solutionlist solution;
	auto result = solution.listAdd(listOne, listTwo);
	print(result);
	//mylist printflist;
	//printflist.setPhead(result);
	//printflist.print();

}


