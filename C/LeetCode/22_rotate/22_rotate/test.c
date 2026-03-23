#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//暴力超时
//void rotate(int* nums, int numsSize, int k) {
//	int* ans = (int*)malloc(sizeof(int) * numsSize);
//
//	k = k % numsSize;
//	for (int i = 0; i < k; i++)
//	{
//		for (int j = 0; j < numsSize; j++)
//		{
//			if (j == 0)
//			{
//				ans[j] = nums[numsSize - 1];
//				continue;
//			}
//			ans[j] = nums[j - 1];
//		}
//		memcpy(nums, ans, numsSize * sizeof(int));
//	}
//}

//优化
void rotate(int* nums, int numsSize, int k) {
	int* ans = (int*)malloc(sizeof(int) * numsSize);

	k = k % numsSize;
	for (int i = 0; i < numsSize; i++)
	{
		ans[(i + k) % numsSize] = nums[i];
	}
	memcpy(nums, ans, sizeof(int) * numsSize);
}