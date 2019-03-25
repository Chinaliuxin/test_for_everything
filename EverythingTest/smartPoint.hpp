#pragma once
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;


namespace mypoint {
	template <class T>
	class SharedPtr
	{
	public:
		SharedPtr(T* ptr = nullptr)//����,make_shareûд����΢�鷳���������
			:_ptr(ptr)
			, _pCount(new int(1))
			, _pMutex(new mutex)
		{
			if (_ptr == nullptr)
			{
				*_pCount = 0;
			}
		}

		SharedPtr(const SharedPtr<T>& sp)//��������
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
			, _pMutex(sp._pMutex)
		{
			//�����һ����ָ��������ü����ü����������Ҫ�� pCount++
			if (_ptr)
				AddCount();
		}
		SharedPtr<T>&operator=(const SharedPtr<T>& sp)//��ֵ����
		{
			if (_ptr != sp._ptr)
			{
				Release();

				_ptr = sp._ptr;
				_pCount = sp._pCount;
				_pMutex = sp._pMutex;
				if (_ptr)
					AddCount();
			}
			return *this;
		}
		int UseCount()
		{
			return *_pCount;
		}
		int AddCount()
		{
			_pMutex->lock();
			++(*_pCount);
			_pMutex->unlock();
			return *_pCount;
		}
		int SubCount()
		{
			_pMutex->lock();
			--(*_pCount);
			_pMutex->unlock();
			return *_pCount;
		}
		void Release()
		{
			if (_ptr && 0 == SubCount())
			{
				delete _ptr;
				delete _pCount;
				delete _pMutex;
			}
		}
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
		~SharedPtr()
		{
			Release();
		}
	private:
		T* _ptr;
		int* _pCount; //���ü���
		mutex* _pMutex; //������
	};
	//struct Date
	//{
	//	int year;
	//	int month;
	//	int day;
	//};
	//int testptr()
	//{
	//	SharedPtr<int> sp1(new int(10));
	//	SharedPtr<int> sp2(sp1);
	//	*sp2 = 20;
	//	cout << sp1.UseCount() << endl;
	//	cout << sp2.UseCount() << endl;
	//	SharedPtr<int> sp3(new int(10));
	//	sp2 = sp3;
	//	cout << sp1.UseCount() << endl;
	//	cout << sp2.UseCount() << endl;
	//	cout << sp3.UseCount() << endl;
	//	sp1 = sp3;
	//	cout << sp1.UseCount() << endl;
	//	cout << sp2.UseCount() << endl;
	//	cout << sp3.UseCount() << endl;
	//	return 0;
	//}
}


void other(shared_ptr<vector<int>>& smart_p2)
{
	shared_ptr<vector<int>>smart_p4 = smart_p2;//��ֵ����
	printf("1,2,3,4��������ü�����%d\n", smart_p2.use_count());
}
void testSharePtr()
{
	shared_ptr<vector<int>> smart_p1 = make_shared<vector<int>>(10, 9);//make_shared�����õ�
	for (auto e : *smart_p1)
	{
		cout << e;
	}
	vector<int> * p2 = new vector<int>();
	*p2 = { 1,2,3,4 };
	shared_ptr<vector<int>>smart_p2(p2);//ʹ��ָ�������Դ��ָ�빹��
	shared_ptr<vector<int>>smart_p3(smart_p2);//��������
	other(smart_p2);
	smart_p2->push_back(5);
	printf("1,2,3,4��������ü�����%d\n", smart_p2.use_count());
	cout << "�������һ��Ԫ�ر�ɣ� " << *(smart_p3->end() - 1) << endl;

	//���2��shared_ptrָ��ѭ�����ã���A�����ָ��ָ��B��B�����ָ��ָ��A�����ѭ�����ã��ܺý����������һ��ָ�뻻��weak_ptr
}
//template <class T>
//class testMypointClass
//{
//public:
//	testMypointClass(T*p)
//		:smart_p1(p)
//	{
//		smart_p1->pop_back();
//		cout << (*smart_p1)[2];
//
//	}
//private:
//	::mypoint::SharedPtr<vector<int> > smart_p1;
//};
//void testMypoint()
//{
//	vector<int> * p2 = new vector<int>();
//	*p2 = { 1,2,3,4 };
//	testMypointClass<vector<int>> t1(p2);
//}