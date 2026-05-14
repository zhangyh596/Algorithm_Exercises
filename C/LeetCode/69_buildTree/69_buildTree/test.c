#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* buildTreeHelper(int* preorder, int pre_start, int pre_end, int* inorder, int in_start, int in_end) {
	if (pre_start > pre_end)
	{
		return NULL;
	}

	int root_val = preorder[pre_start];

	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = root_val;
	root->left = NULL;
	root->right = NULL;

	int root_index = in_start;
	while (root_index <= in_end && inorder[root_index] != root_val)
	{
		root_index++;
	}

	int left_len = root_index - in_start;

	root->left = buildTreeHelper(preorder, pre_start + 1, pre_start + left_len, inorder, in_start, root_index - 1);
	root->right = buildTreeHelper(preorder, pre_start + left_len + 1, pre_end, inorder, root_index + 1, in_end);

	return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	return buildTreeHelper(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}