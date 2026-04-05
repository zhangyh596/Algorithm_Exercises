#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

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
	int* ans = (int*)malloc(sizeof(int) * 10005);
	*returnSize = 0;

	inorderHelper(root, ans, returnSize);
	return ans;
}

bool isValidBST(struct TreeNode* root) {
	int size = 0;
	int* p = inorderTraversal(root, &size);
	for (int i = 1; i < size; i++)
	{
		if (p[i] <= p[i - 1])
		{
			return false;
		}
	}
	return true;
}