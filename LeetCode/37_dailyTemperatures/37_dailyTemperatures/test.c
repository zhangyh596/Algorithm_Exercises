#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//暴力超时
//int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
//	int* ans = (int*)calloc(temperaturesSize, sizeof(int));
//	for (int i = 0; i < temperaturesSize; i++)
//	{
//		int count = 0;
//		for (int j = i + 1; j < temperaturesSize; j++)
//		{
//			count++;
//			if (temperatures[j] > temperatures[i])
//			{
//				ans[i] = count;
//				break;
//			}
//		}
//	}
//	*returnSize = temperaturesSize;
//	return ans;
//}

//单调栈
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
	int* ans = (int*)calloc(temperaturesSize, sizeof(int));

	int stack[100005];
	int top = -1;
	for (int i = 0; i < temperaturesSize; i++)
	{
		while (top > -1 && temperatures[i] > temperatures[stack[top]])
		{
			ans[stack[top]] = i - stack[top];
			top--;
		}

		top++;
		stack[top] = i;
	}

	*returnSize = temperaturesSize;
	return ans;
}