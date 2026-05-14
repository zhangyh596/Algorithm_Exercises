#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

int* rightSideView(struct TreeNode* root, int* returnSize) {
	if (root == NULL)
	{
		*returnSize = 0;
		return NULL;
	}

	struct TreeNode* queue[200];
	int head = 0, tail = 0;

	int* ans = (int*)malloc(sizeof(int) * 200);
	*returnSize = 0;

	queue[tail++] = root;

	while (head < tail)
	{
		ans[*returnSize] = queue[tail - 1]->val;
		(*returnSize)++;

		int cur_len = tail - head;
		for (int i = 0; i < cur_len; i++)
		{
			struct TreeNode* node = queue[head++];

			if (node->left != NULL)
			{
				queue[tail++] = node->left;
			}
			if (node->right != NULL)
			{
				queue[tail++] = node->right;
			}
		}
	}
	return ans;
}