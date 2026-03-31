#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//时间复杂度不符
//int cmp(const void* p1, const void* p2)
//{
//	if (*(int*)p1 > *(int*)p2)
//		return 1;
//	else if (*(int*)p1 == *(int*)p2)
//		return 0;
//	else
//		return -1;
//}
//
//int firstMissingPositive(int* nums, int numsSize) {
//	qsort(nums, numsSize, sizeof(int), cmp);
//
//	int expect = 1;
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (nums[i] <= 0)
//		{
//			continue;
//		}
//		else
//		{
//			if (nums[i] == expect)
//			{
//				expect++;
//			}
//			else if (nums[i] > expect)
//			{
//				return expect;
//			}
//		}
//	}
//	return expect;
//}


int firstMissingPositive(int* nums, int numsSize) {
	//对于负数和大于numsSize的数我们不予处理
	//将当前nums[i]放到下标为nums[i] - 1的位置
	for (int i = 0; i < numsSize; i++)
	{
		while (nums[i] > 0 && nums[i] <= numsSize && nums[i] != nums[nums[i] - 1])
		{
			int index = nums[i] - 1;
			int tmp = nums[index];
			nums[index] = nums[i];
			nums[i] = tmp;
		}
	}

	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] != i + 1)
			return i + 1;
	}
	return numsSize + 1;
}
