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
/*
https://leetcode-cn.com/problems/unique-paths/
leetcode 64 不同路径
*/
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int> > map(m, vector<int>(n, 0));
		for (int i = 0; i < map.size(); i++)
		{
			map[i][0] = 1;
		}
		for (int i = 0; i < map[0].size(); i++)
		{
			map[0][i] = 1;
		}
		for (int i = 1; i < map.size(); i++)
		{
			for (int j = 1; j < map[0].size(); j++)
			{
				map[i][j] = map[i - 1][j] + map[i][j - 1];
			}
		}
		return map[m - 1][n - 1];
	}
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };前序和中序获得二叉树


 https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/comments/
 */
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		// preorder: [root, [left], [right]]
		// inorder:  [[left], root, [right]]
		return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
	TreeNode* buildTree(vector<int>& preorder, int lo1, int hi1, vector<int>& inorder, int lo2, int hi2) {
		if (lo1 > hi1 || lo2 > hi2) return nullptr;
		int root = preorder[lo1];
		int mid = lo2;
		// 在 inorder 中查找 root 位置
		for (int i = lo2; i <= hi2; ++i) {
			if (inorder[i] == root) {
				mid = i;
				break;
			}
		}

		auto s = new TreeNode(root);
		// 下面的数组表示分割长度
		// inorder: [mid-lo2, mid, hi2-mid]
		// preorder:[root, mid-lo2, hi2-mid]
		s->left = buildTree(preorder, lo1 + 1, lo1 + mid - lo2, inorder, lo2, mid - 1);
		s->right = buildTree(preorder, lo1 + mid - lo2 + 1, hi1, inorder, mid + 1, hi2);
		return s;
	}
};