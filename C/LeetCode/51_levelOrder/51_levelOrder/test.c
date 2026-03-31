#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
	if (root == NULL)
	{
		*returnSize = 0;
		return NULL;
	}

	struct TreeNode* queue[2005];
	int head = 0, tail = 0;

	int** ans = (int**)malloc(sizeof(int*) * 2000);
	*returnColumnSizes = (int*)malloc(sizeof(int) * 2000);

	//根节点入队，tail向后加1（tail指向即将放入数据的位置）
	queue[tail++] = root;
	int index = 0;//记录当前的层数

	while (head < tail)
	{
		int cur_len = tail - head;//记录 当前层的长度（有几个节点）

		ans[index] = (int*)malloc(sizeof(int) * cur_len);
		(*returnColumnSizes)[index] = cur_len;

		for (int i = 0; i < cur_len; i++)
		{
			//把当前下标为head的节点拿出来
			struct TreeNode* node = queue[head++];
			ans[index][i] = node->val;

			if (node->left)
			{
				queue[tail++] = node->left;
			}

			if (node->right)
			{
				queue[tail++] = node->right;
			}
		}
		//循环结束后head刚好又指向当前层的第一个节点，tail指向下一层的第一个节点
		index++;
	}

	*returnSize = index;
	return ans;
}