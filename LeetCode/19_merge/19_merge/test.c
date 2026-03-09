#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
	int* a = *(int**)p1;
	int* b = *(int**)p2;

	return a[0] - b[0];
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
	qsort(intervals, intervalsSize, sizeof(int*), cmp);

	//准备空间
	int** ans = (int**)malloc(sizeof(int*) * intervalsSize);
	*returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);

	int count = 0;//计算有多少个区间
	for (int i = 0; i < intervalsSize; i++)
	{
		//没有重叠
		if (count == 0 || intervals[i][0] > ans[count - 1][1])
		{
			ans[count] = (int*)malloc(sizeof(int) * 2);
			ans[count][0] = intervals[i][0];
			ans[count][1] = intervals[i][1];
			(*returnColumnSizes)[count] = 2;
			count++;
		}
		//有重叠
		else
		{
			if (intervals[i][1] > ans[count - 1][1])
			{
				ans[count - 1][1] = intervals[i][1];
			}
		}
	}

	*returnSize = count;
	return ans;
}