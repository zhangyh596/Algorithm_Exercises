#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* createNode(int value)
{
	struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	newNode->val = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int value)
{
	if (root == NULL)
	{
		return createNode(value);
	}

	if (value < root->val)
	{
		root->left = insertNode(root->left, value);
	}
	else if (value > root->val)
	{
		root->right = insertNode(root->right, value);
	}

	return root;
}

struct TreeNode* buildTree(int* nums, int left, int right)
{
	if (left > right)
	{
		return NULL;
	}

	int mid = left + (right - left) / 2;

	struct TreeNode* root = createNode(nums[mid]);

	root->left = buildTree(nums, left, mid - 1);
	root->right = buildTree(nums, mid + 1, right);

	return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	return buildTree(nums, 0, numsSize - 1);
}