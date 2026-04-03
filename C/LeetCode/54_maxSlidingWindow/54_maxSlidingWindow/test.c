#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//暴力解法超时
//int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
//	if (numsSize == 0)
//	{
//		*returnSize = 0;
//		return NULL;
//	}
//
//	int* ans = (int*)malloc(sizeof(int) * numsSize);
//	int index = 0;
//
//	int left = 0, right = k - 1;
//	while (right < numsSize)
//	{
//		int max = nums[left];
//		for (int i = left; i <= right; i++)
//		{
//			if (nums[i] > max)
//			{
//				max = nums[i];
//			}
//		}
//		ans[index++] = max;
//		left++;
//		right++;
//	}
//
//	*returnSize = index;
//	return ans;
//}

//优化做法
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
	if (numsSize == 0)
	{
		*returnSize = 0;
		retrun NULL;
	}

	int* ans = (int*)malloc(sizeof(int) * (numsSize - k + 1));
	int q[100005];
	int head = 0, tail = 0;
	int index = 0;//写入ans的下标

	for (int i = 0; i < numsSize; i++)
	{
		// 只要队列不空，且“队尾老兵的战斗力” 小于等于 “当前新兵的战斗力”
		while (head < tail && nums[q[tail - 1]] < nums[i])
		{
			tail--;
		}

		// 新兵把自己的下标 i 登记入队尾
		q[tail++] = i;

		// 只要队列不空，且“队头老大的下标” 已经小于当前合法窗口的左边界 (i - k + 1)
		while (head < tail && q[head] < i - k + 1)
		{
			head++;
		}

		// 当 i 走到 k - 1 时，第一个完整的窗口（长度为 k）才算刚刚形成
		if (i >= k - 1)
		{
			ans[index++] = nums[q[head]];
		}
	}

	*returnSize = index;
	return ans;
}