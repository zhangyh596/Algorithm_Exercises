#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
	int** ans = (int**)malloc(sizeof(int*) * numRows);
	*returnColumnSizes = (int*)malloc(sizeof(int) * numRows);
	for (int i = 0; i < numRows; i++)
	{
		(*returnColumnSizes)[i] = i + 1;
		ans[i] = (int*)malloc(sizeof(int) * (i + 1));
		ans[i][0] = 1, ans[i][i] = 1;
	}

	for (int i = 0; i < numRows; i++)
	{
		for (int j = 1; j <= i - 1; j++)
		{
			ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
		}
	}

	*returnSize = numRows;
	return ans;
}