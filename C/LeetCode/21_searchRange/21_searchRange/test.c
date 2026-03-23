#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int* ans = (int*)malloc(sizeof(int) * 2);

	if (numsSize == 0)
	{
		ans[0] = -1, ans[1] = -1;
		*returnSize = 2;
		return ans;
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
	ans[0] = left;

	if (nums[left] != target)
	{
		ans[0] = -1, ans[1] = -1;
		*returnSize = 2;
		return ans;
	}

	left = 0, right = numsSize - 1;
	while (left < right)
	{
		int mid = (left + right + 1) / 2;
		if (nums[mid] <= target)
		{
			left = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	ans[1] = left;

	*returnSize = 2;
	return ans;
}