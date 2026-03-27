#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

int maxDepth(struct TreeNode* root) {
	if (root == NULL)
	{
		return 0;
	}

	int left_depth = maxDepth(root->left) + 1;
	int right_depth = maxDepth(root->right) + 1;

	if (left_depth > right_depth)
	{
		return left_depth;
	}
	else
	{
		return right_depth;
	}
}