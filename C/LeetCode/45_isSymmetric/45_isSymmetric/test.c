#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNodr* right;
};

bool checkMirror(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}

	// 如果一个变成了 NULL，另一个却还有物理节点（不为 NULL），说明结构残缺。
	if (p == NULL || q == NULL || p->val != q->val)
	{
		return false;
	}

	// 只有当“外侧对称” 和 “内侧对称”同时成立时，才返回 true。
	return checkMirror(p->left, q->right) && checkMirror(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return true;

	return checkMirror(root->left, root->right);
}