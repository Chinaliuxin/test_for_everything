#include<queue>
#include<vector>
#include<iostream>
#include<list>
//priority_queue(const Compare& x = Compare(), const Container& y = Container() );
using namespace std;
namespace mydeque {
	template<class T, class Con = ::std::deque<T>>
	class Stack
	{
	public:
		Stack() {}
		void Push(const T& x) { _c.push_back(x); }
		void Pop() { _c.pop_back(); }
		T& Top() { return _c.back(); }
		const T& Top()const { return _c.back(); }
		size_t Size()const { return _c.size(); }
		bool Empty()const { return _c.empty(); }
	private:
		Con _c;
	};}
void testPriorityQueue()
{
	//���ȼ�����Ĭ���Ǵ��
	int array[] = { 1,3,54,6,57,45,345,4 };
	int size = sizeof(array) / sizeof(array[0]);
	priority_queue<int> pq;
	for (auto e : array)
	{
		pq.push(e);
	}
	for (int i=0; i < size; i++)
	{
		cout << pq.top()<<">";
		pq.pop();
	}

	// ���Ҫ����С�ѣ���������ģ���������greater�ȽϷ�ʽ
	vector<int> v = { 1,3,54,6,57,45,345,4 };
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());



}

void testMystack()
{
	::mydeque::Stack<int, list<int>> s;//ջ��������������deque��Ҳ������list��vector
	s.Push(1);
	s.Pop();
	s.Push(2);
	cout << s.Top()<<s.Empty();

}
