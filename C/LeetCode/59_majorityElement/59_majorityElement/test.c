#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//暴力枚举
//int majorityElement(int* nums, int numsSize) {
//	int ret = 0;
//
//	int i = 0;
//	while (i < numsSize)
//	{
//		int count = 0;
//		for (int j = 0; j < numsSize; j++)
//		{
//			if (nums[j] == nums[i])
//			{
//				count++;
//			}
//
//			if (count > numsSize / 2)
//			{
//				ret = nums[i];
//			}
//		}
//		i++;
//	}
//	return ret;
//}

int majorityElement(int* nums, int numsSize) {
	int ret = 0;
	int count = 0;

	//实行一换一找出众数，最终剩下的一定会是众数
	for (int i = 0; i < numsSize; i++)
	{
		if (count == 0)
		{
			ret = nums[i];
		}

		if (nums[i] == ret)
		{
			count++;
		}
		else
		{
			count--;
		}
	}

	return ret;
}