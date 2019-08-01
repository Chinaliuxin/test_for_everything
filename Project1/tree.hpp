#pragma once
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 给定一个二叉树，返回它的 前序 遍历。
 https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 */
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret(0, 0);
		if (root == nullptr)return ret;
		stack<TreeNode*> s;
		s.push(root);
		TreeNode* cur = nullptr;
		while (!s.empty())
		{
			cur = s.top();
			ret.push_back(cur->val);
			s.pop();
			if (cur->right != nullptr)
				s.push(cur->right);
			if (cur->left != nullptr)
				s.push(cur->left);
		}
		return ret;
	}
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (root == nullptr)return ret;
		stack<TreeNode*> s;
		auto cur = root;
		while (cur || !s.empty())
		{
			while (cur != nullptr)
			{
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();
			s.pop();
			ret.push_back(cur->val);
			cur = cur->right;
		}
		return ret;
	}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 给定一个二叉树，返回它的 后序 遍历。
 https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
 */
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret(0, 0);
		if (root == nullptr)return ret;
		stack<TreeNode*> s;
		s.push(root);
		TreeNode* cur = nullptr;
		while (!s.empty())
		{
			cur = s.top();
			ret.push_back(cur->val);
			s.pop();
			if (cur->left != nullptr)
				s.push(cur->left);
			if (cur->right != nullptr)
				s.push(cur->right);
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}

};