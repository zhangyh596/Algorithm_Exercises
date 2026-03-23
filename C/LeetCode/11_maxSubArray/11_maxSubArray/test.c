#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
	int max = nums[0];
	int s[100005];
	s[0] = nums[0];
	for (int i = 1; i < numsSize; i++)
	{
		if (s[i - 1] > 0)
		{
			s[i] = s[i - 1] + nums[i];
		}
		else
		{
			s[i] = nums[i];
		}

		if (s[i] > max)
		{
			max = s[i];
		}
	}
	return max;
}