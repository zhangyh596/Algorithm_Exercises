#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int cmp(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	qsort(nums, numsSize, sizeof(int), cmp);
	int** ans = (int**)malloc(sizeof(int*) * 20000);
	*returnColumnSizes = (int*)malloc(sizeof(int) * 20000);
	int index = 0;

	for (int i = 0; i < numsSize; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		int left = i + 1, right = numsSize - 1;
		while (left < right)
		{
			if (nums[i] + nums[left] + nums[right] > 0)
			{
				right--;
			}
			else if (nums[i] + nums[left] + nums[right] < 0)
			{
				left++;
			}
			else
			{
				ans[index] = (int*)malloc(sizeof(int) * 3);
				ans[index][0] = nums[i], ans[index][1] = nums[left], ans[index][2] = nums[right];
				(*returnColumnSizes)[index] = 3;
				index++;
				while (left < right && nums[left] == nums[left + 1])
				{
					left++;
				}
				while (left < right && nums[right] == nums[right - 1])
				{
					right--;
				}
				left++;
				right--;
			}
		}
	}
	*returnSize = index;
	return ans;
}