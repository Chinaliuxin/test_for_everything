
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include <unordered_set>
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

//�º�����lambda���ʽ

//list���
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
		//cout << "��ʼ����" << endl;
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
	int listSize()
	{
		int count = 0;
		PNode cur = phead;
		while (cur != nullptr)
		{
			count++;
			cur = cur->next;
		}
		return count;
	}
	void listSort()//�Խ�����ð������
	{
		if (phead->next == nullptr || phead == nullptr)//��֤�����������ڵ���2
			return;
		int size = listSize();
		PNode pre, cur, next;
		pre = new listNode(-1);
		pre->next = phead;
		cur = pre->next;
		next = cur->next;
		/*for(int i=0;i<size-1;i++)
		{*/
	/*		for (int j=0;j<size-1;j++ )
			{
				
				if (cur->data > next->data)
				{*/
					cur = next->next;
					pre->next = next;
					next->next = cur;
					
					PNode temp = next;
					next = cur;
					cur = temp;
				//}
				//pre = pre->next; cur = cur->next;
				//if (next!=nullptr)
				//	next = next->next;
			/*}*/
		
	}
	~mylist()
	{//����
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
//�������
class Solutionlist {
public:
	PNode listAdd(mylist& const list1, mylist& const list2)
	{
		PNode l1 = list1.getPhead();//��list one����д����Ҫ����
		PNode l2 = list2.getPhead();
		listNode* dummy = new listNode(-1);//�����ƽ�㣬����list����յ����
		listNode* cur = dummy;
		int carry = 0;//��λ
		int sum = 0;// ��Ӧλ��
		while (l1 || l2)//l1����l2��Ϊ�վ�һֱѭ��������Ϊ�ձ�ʾ�������֣�
		{
			int data1 = (l1 ? l1->data : 0);
			int data2 = (l2 ? l2->data : 0);
			sum = data1 + data2 + carry;
			carry = sum / 10;
			cur->next = new listNode(sum % 10);//sumȡֵ��0-18֮�䣨0+0---9+9��
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
//����ת��
void test_zhuanhaun()
{
	int n = 16;//n�ǽ���
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
	mylist l;
	l.push_back(4);
	l.push_back(3);
	l.push_back(2);
	l.push_back(1);
	l.print();
	cout << l.listSize()<<endl;
	l.listSort();
	l.print();
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
	listOne.push_back(4);
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
//�����������룬���дһ��������������ʵ�ֽ������и�����������������

void testString0318()
{
	string input1="xcopy /s c:\\ d:\\";
	//cin >> input1;
	string k = " ";
	 string input = k + input1;
	string::iterator it = input.begin();
	int count = 0;
	int len = 0;
	list<string> l;
	while (it != input.end())
	{
		//if (it != input.end()&&*it=='\"')
		//{
		//	it++;
		//	len++;
		//	while (it != input.end()&&*it != '\"')
		//	{
		//		it++;
		//		len++;
		//	}
		//	string str = input.substr(distance(input.begin(),it)-len+2,len-2);
		//	len = 0;
		//	l.push_back(str);
		//	count++;
		//}
		if (it != input.end()&&*it == ' ')
		{
			it++;
			len++;
			while (it != input.end()&&*it != ' ')
			{
				it++;
				len++;
			}
			string str = input.substr(distance(input.begin(), it) - len+1, len);
			if (*(str.begin()) == '\"')
			{
				str.erase(str.end() - 1);
				str.erase(str.begin());
			}
			len = 0;
			l.push_back(str);
			count++;
		}
	}
	cout << count << endl;
	cout << input;
	for (auto e : l)
	{
		cout << e<<endl;
	}
}

