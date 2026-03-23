#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {

	if (target > nums[numsSize - 1])
	{
		return numsSize;
	}
	else if (target < nums[0])
	{
		return 0;
	}

	int left = 0, right = numsSize - 1;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] >= target)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return left;
}