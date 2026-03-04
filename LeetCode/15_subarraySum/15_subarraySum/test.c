#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//暴力超时
//int subarraySum(int* nums, int numsSize, int k) {
//	int count = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		int sum = 0;
//		for (int j = i; j < numsSize; j++)
//		{
//			sum += nums[j];
//			if (sum == k)
//			{
//				count++;
//			}
//		}
//	}
//	return count;
//}

//前缀和思想+数组模拟实现哈希表

//因为数组下标不能是负数，用下标代表sum，里面的值代表出现的次数，模拟实现哈希表
#define OFFSET 20000000

int book[40000001];

int subarraySum(int* nums, int numsSize, int k) {
	int count = 0;
	int sum = 0;

	book[0 + OFFSET] = 1;//0默认出现一次

	for (int i = 0; i < numsSize; i++)
	{
		sum += nums[i];
		int target = sum - k;
		if (target + OFFSET >= 0 && target + OFFSET <= 40000000)
		{
			count += book[target + OFFSET];
		}
		book[sum + OFFSET]++;
	}

	//重新将数组置空，方便下次调用
	int tmp_sum = 0;
	for (int i = 0; i < numsSize; i++)
	{
		tmp_sum += nums[i];
		book[tmp_sum + OFFSET] = 0;
	}
	return count;
}