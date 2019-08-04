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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 中序遍历
 * };
 */
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;

		queue<TreeNode*> queue;
		queue.push(root);

		vector<int> level_res;
		int curNums = 1, nextNums = 0;

		TreeNode* node;

		while (!queue.empty())
		{
			node = queue.front();

			level_res.push_back(node->val);
			queue.pop();
			curNums--;

			if (node->left)
			{
				queue.push(node->left);
				nextNums++;
			}

			if (node->right)
			{
				queue.push(node->right);
				nextNums++;
			}


			if (curNums == 0)
			{
				res.push_back(level_res);

				level_res.clear();

				curNums = nextNums;
				nextNums = 0;
			}

		}

		return res;

	}
};

