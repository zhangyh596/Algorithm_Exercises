#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
	int i = 0, k = 0;
	for (int k = 0; k < numsSize; k++)
	{
		if (nums[k] == 0)
		{

		}
		else
		{
			nums[i] = nums[k];
			i++;
		}
	}
	while (i < numsSize)
	{
		nums[i] = 0;
		i++;
	}
}