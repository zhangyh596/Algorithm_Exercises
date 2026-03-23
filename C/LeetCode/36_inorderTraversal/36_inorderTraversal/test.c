#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

void inorderHelper(struct TreeNode* root, int* ans, int* returnSize) {
	if (root == NULL)
	{
		return;
	}

	inorderHelper(root->left, ans, returnSize);

	ans[*returnSize] = root->val;
	(*returnSize)++;

	inorderHelper(root->right, ans, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int* ans = (int*)malloc(sizeof(int) * 100);
	*returnSize = 0;

	inorderHelper(root, ans, returnSize);
	return ans;
}