#pragma once

#pragma once
#include<stack>
#include<string>
using namespace std;
namespace mystack {
	//用于测试和栈有关的数据的命名空间

	class Parenthesis {
	public:
		bool chkParenthesis(string A, int n) {
			// write code here
			stack<char> s;
			for (int i = 0; i < n; i++) {
				if (A[i] == '(')
					s.push(A[i]);
				else if (A[i] == ')')
				{
					if (true == s.empty() || s.top() != '(')
						return false;
					s.pop();
				}

			}
			if (s.empty())
				return true;
			return false;
		}
	};

	void test_solu_stack()//判断括号问题
	{
		Parenthesis p;

		string A = "()()()()()((())";
		string ret = p.chkParenthesis(A, A.size()) == 1 ? "所有括号匹配" : "括号不匹配";
		cout << ret;
		string A2 = "()(((()))(sfdf)()()sfsf(f)()((())";
		ret = p.chkParenthesis(A2, A2.size()) == 1 ? "所有括号匹配" : "括号不匹配";

		cout << ret;
	}
}