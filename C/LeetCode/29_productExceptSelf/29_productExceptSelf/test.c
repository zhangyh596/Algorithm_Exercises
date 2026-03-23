#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int l[100005];
//int r[100005];
//
//int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
//	l[0] = 1;
//	for (int i = 1; i < numsSize; i++)
//	{
//		l[i] = l[i - 1] * nums[i - 1];
//	}
//	r[numsSize - 1] = 1;
//	for (int i = numsSize - 2; i >= 0; i--)
//	{
//		r[i] = r[i + 1] * nums[i + 1];
//	}
//
//	int* ans = (int*)malloc(sizeof(int) * numsSize);
//	for (int i = 0; i < numsSize; i++)
//	{
//		ans[i] = l[i] * r[i];
//	}
//	*returnSize = numsSize;
//	return ans;
//}


//空间复杂度降低
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
	//直接把数组左边元素的乘积存入ans里面
	int* ans = (int*)malloc(sizeof(int) * numsSize);
	ans[0] = 1;
	for (int i = 1; i < numsSize; i++)
	{
		ans[i] = ans[i - 1] * nums[i - 1];
	}

	//利用right变量
	int right = 1;
	for (int i = numsSize - 1; i >= 0; i--)
	{
		ans[i] *= right;
		right *= nums[i];
	}
	*returnSize = numsSize;
	return ans;
}