#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

void inorderHelper(struct TreeNode* root, int* ans, int* returnSize)
{
	if (root == NULL)
	{
		return;
	}

	inorderHelper(root->left, ans, returnSize);

	ans[*returnSize] = root->val;
	(*returnSize)++;

	inorderHelper(root->right, ans, returnSize);
}

int kthSmallest(struct TreeNode* root, int k) {
	int* ans = (int*)malloc(sizeof(int) * 10000);
	int size = 0;

	inorderHelper(root, ans, &size);

	return ans[k - 1];
}