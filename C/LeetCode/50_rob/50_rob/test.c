#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int rob(int* nums, int numsSize) {
	if (numsSize == 1)
		return nums[0];
	else if(numsSize == 2)
		return nums[0] > nums[1] ? nums[0] : nums[1];

	int dp[105];
	dp[0] = nums[0];
	dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];

	for (int i = 2; i < numsSize; i++)
	{
		dp[i] = dp[i - 1] > (dp[i - 2] + nums[i]) ? dp[i - 1] : (dp[i - 2] + nums[i]);
	}

	int max = dp[0];
	for (int i = 1; i < numsSize; i++)
	{
		if (dp[i] > max)
		{
			max = dp[i];
		}
	}
	return max;
}