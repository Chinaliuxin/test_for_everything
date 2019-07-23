#pragma once
#include<iostream>
#include<mutex>
using namespace std;
template <class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)//构造,make_share没写，稍微麻烦，不过差不多
		:_ptr(ptr)
		, _pCount(new int(1))
		, _pMutex(new mutex)
	{
		if (_ptr == nullptr)
		{
			*_pCount = 0;
		}
	}

	SharedPtr(const SharedPtr<T>& sp)//拷贝构造
		:_ptr(sp._ptr)
		, _pCount(sp._pCount)
		, _pMutex(sp._pMutex)
	{
		//如果是一个空指针对象，则不用加引用计数，否则就要将 pCount++
		if (_ptr)
			AddCount();
	}
	SharedPtr<T>&operator=(const SharedPtr<T>& sp)//赋值重载
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
	int* _pCount; //引用计数
	mutex* _pMutex; //互斥锁
};
struct Date
{
	int year;
	int month;
	int day;
};
int testptr()
{
	SharedPtr<int> sp1(new int(10));
	SharedPtr<int> sp2(sp1);
	*sp2 = 20;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	SharedPtr<int> sp3(new int(10));
	sp2 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;
	sp1 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;
	return 0;
}


template<class T>
class UniquePtr
{
public:
	UniquePtr(T * ptr = nullptr)
		: _ptr(ptr)
	{}
	~UniquePtr()
	{
		if (_ptr)
			delete _ptr;
	}
	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }
private:
	// C++98防拷贝的方式：只声明不实现+声明成私有
	UniquePtr(UniquePtr<T> const &);
	UniquePtr & operator=(UniquePtr<T> const &);
	// C++11防拷贝的方式：delete
	UniquePtr(UniquePtr<T> const &) = delete;
	UniquePtr & operator=(UniquePtr<T> const &) = delete;
private: T * _ptr;
};
