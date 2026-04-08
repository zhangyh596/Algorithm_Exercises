#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int singleNumber(int* nums, int numsSize) {
//	int ret = 0;
//	int count = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		int flag = 0;
//		for (int j = 0; j < numsSize; j++)
//		{
//			if(nums[j] == nums[i] && j != i)
//			{
//				flag = 1;
//				break;
//			}
//		}
//
//		if (flag == 0)
//		{
//			ret = nums[i];
//		}
//	}
//	return ret;
//}

int singleNumber(int* nums, int numsSize) {
	int ret = 0;
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];
	}
	return ret;
}