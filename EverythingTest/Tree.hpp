#pragma once
#include<iostream>
#include<string>
#include <map>
#include<stack>
#include<vector>

using namespace std;

template <typename T>
struct BinaryTreeNode
{
	BinaryTreeNode(T data)//T data = T()
		:_left(nullptr)
		, _right(nullptr)
		, _data(data)
	{}
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
	T _data;
};


template <typename T>
class BinaryTree
{
	typedef  BinaryTreeNode<T>  Node;

public:

	BinaryTree(const T* a, size_t size, const T& invalid);//构造
	BinaryTree(const vector<T>& a, size_t size, const T& invalid);//构造

	~BinaryTree();//析构
	void PrintPre();//前序遍历_递归
	void PrintPreIteration();
	void PrintIn();//中序遍历_递归
	void PrintInIteration();
	Node* Find(T data);



private:
	Node* _MakeTree(const T* a, size_t size, int& index, const T& invalid);
	Node* _MakeTree(const vector<T>& a, size_t size, int& index, const T& invalid);
	void Destroy(Node* _root);
	void _PrintPre(Node* _root);
	void _PrintIn(Node* _root);
	Node* Find(Node* _root, T data);
private:
	Node* _root;
};




template<typename T>
inline BinaryTree<T>::BinaryTree(const T* a, size_t size, const T& invalid)
{
	int index = 0;
	_root = _MakeTree(a, size, index, invalid);
}


template<typename T>
inline BinaryTree<T>::BinaryTree(const vector<T>& a, size_t size, const T & invalid)
{
	int index = 0;

	_root = _MakeTree(a, size, index, invalid);
}

template<typename T>
inline BinaryTree<T>::~BinaryTree()
{
	Destroy(_root);
}

template<typename T>
inline void BinaryTree<T>::PrintPre()
{
	_PrintPre(_root);

}
template<typename T>
inline BinaryTreeNode<T> * BinaryTree<T>::_MakeTree(const vector<T>&a, size_t size, int & index, const T & invalid)
{
	Node *root = nullptr;
	if (index < size && a[index] != invalid)
	{
		root = new Node(invalid);
		root->_data = a[index];
		root->_left = _MakeTree(a, size, ++index, invalid);
		root->_right = _MakeTree(a, size, ++index, invalid);
	}
	return root;

}

template<typename T>
inline BinaryTreeNode<T> * BinaryTree<T>::_MakeTree(const T * a, size_t size, int & index, const T & invalid)
{
	Node *root = nullptr;
	if (index < size && a[index] != invalid)
	{
		root = new Node(invalid);
		root->_data = a[index];
		root->_left = _MakeTree(a, size, ++index, invalid);
		root->_right = _MakeTree(a, size, ++index, invalid);
	}
	return root;

}

template<typename T>
inline void BinaryTree<T>::Destroy(Node * _root)
{
	Node* tmp = _root;
	if (tmp == nullptr)
		return;
	Destroy(tmp->_left);
	Destroy(tmp->_right);
	delete tmp;
	tmp = nullptr;

}

template<typename T>
inline void BinaryTree<T>::_PrintPre(Node * _root)
{
	if (_root == nullptr)
	{
		return;
	}
	cout << _root->_data << endl;
	_PrintPre(_root->_left);
	_PrintPre(_root->_right);
}
template<typename T>
inline void BinaryTree<T>::_PrintIn(Node * _root)
{
	if (_root == nullptr)
	{
		return;
	}
	_PrintIn(_root->_left);
	cout << _root->_data << endl;
	_PrintIn(_root->_right);
}
template<typename T>
inline void BinaryTree<T>::PrintPreIteration()
{
	Node* cur = _root;//BinaryTreeNode<T>
	Node* top = nullptr;
	stack<Node*> s;
	if (cur == nullptr)
	{
		return;
	}
	while (cur || !s.empty())
	{
		while (cur)
		{
			s.push(cur);
			cout << cur->_data << endl;
			cur = cur->_left;
		}
		top = s.top();
		s.pop();
		cur = top->_right;
	}
}

template<typename T>
inline void BinaryTree<T>::PrintIn()
{
	_PrintIn(_root);
}

template<typename T>
inline void BinaryTree<T>::PrintInIteration()
{

}



class s {
public://找到前k个重复的字符串
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int> count_map;
		for (size_t i = 0; i < words.size(); ++i)
		{
			count_map[words[i]]++;
		}

		multimap<int, string, greater<int>> sort_map;
		for (const auto& e : count_map)
		{
			sort_map.insert(make_pair(e.second, e.first));
		}

		vector<string> v;
		auto it = sort_map.begin();
		while (it != sort_map.end() && k-- != 0)
		{
			v.push_back(it->second);
			++it;
		}

		return v;
	}
};
void test_tree()
{
	vector<char> v{ 'A','B','D','#','#','#','C','E','#','#' ,'F' };

	//char a[] = { 'A','B','D','#','#','#','C','E','#','#' ,'F' };

	BinaryTree<char> b(v, v.size(), '#');
	b.PrintPreIteration();
	cout << "中序";
	b.PrintInIteration();
	b.PrintIn();

}
