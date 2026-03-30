#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

//递归做法，时间复杂度过大
//int maxDepth(struct TreeNode* root) {
//	if (root == NULL)
//	{
//		return 0;
//	}
//
//	int left_depth = maxDepth(root->left) + 1;
//	int right_depth = maxDepth(root->right) + 1;
//
//	if (left_depth > right_depth)
//	{
//		return left_depth;
//	}
//	else
//	{
//		return right_depth;
//	}
//}
//
//int diameterOfBinaryTree(struct TreeNode* root) {
//	if (root == NULL)
//	{
//		return 0;
//	}
//
//	int d1 = diameterOfBinaryTree(root->left);
//	int d2 = diameterOfBinaryTree(root->right);
//
//	int max = d1 > d2 ? d1 : d2;
//
//	int cur = maxDepth(root->left) + maxDepth(root->right);
//	if (cur > max)
//	{
//		max = cur;
//	}
//	return max;
//}

//优化做法

//通过指针改变max的值（无需多次遍历同一个节点）
//返回值是最大深度，同时可以得到最大深度

//通过返回值来求最大深度，利用指针改变最大直径
int getDepthAndUpdate(struct TreeNode* root, int* p_max)//核心函数
{
	if (root == NULL)
	{
		return 0;
	}

	int L = getDepthAndUpdate(root->left, p_max);
	int R = getDepthAndUpdate(root->right, p_max);

	int cur = L + R;
	if (L + R > *p_max)
	{
		*p_max = cur;
	}

	//当前深度 = 左右子树中较深的那一个 + 1（节点本身这一层）
	if (L > R)
	{
		return L + 1;
	}
	else
	{
		return R + 1;
	}
}

int diameterOfBinaryTree(struct TreeNode* root) {
	int max = 0;

	getDepthAndUpdate(root, &max);

	return max;
}