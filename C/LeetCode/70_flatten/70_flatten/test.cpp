#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* arr[2000];

void preOrderTree(struct TreeNode* root, int* pcount)
{
	if (root == NULL)
	{
		return;
	}

	arr[*pcount] = root;
	(*pcount)++;

	preOrderTree(root->left, pcount);
	preOrderTree(root->right, pcount);
}

void flatten(struct TreeNode* root)
{
	int count = 0;
	preOrderTree(root, &count);

	for (int i = 0; i < count; i++)
	{
		arr[i]->left = NULL;

		if (i == count - 1)
		{
			arr[i]->right = NULL;
		}
		else
		{
			arr[i]->right = arr[i + 1];
		}
	}
}

int main()
{
	return 0;
}