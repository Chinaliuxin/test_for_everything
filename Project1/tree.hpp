#pragma once
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