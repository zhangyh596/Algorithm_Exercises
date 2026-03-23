#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//排序做法时间复杂度为O(log n)
//int cmp(const void* p1, const void* p2)
//{
//	return *(int*)p1 - *(int*)p2;
//}
//
//int longestConsecutive(int* nums, int numsSize) {
//	if (numsSize == 0)
//		return 0;
//
//	qsort(nums, numsSize, sizeof(int), cmp);
//
//	int max_len = 1;
//	int cur_len = 1;
//	for (int i = 1; i < numsSize; i++)
//	{
//		if (nums[i] == nums[i - 1] + 1)
//		{
//			cur_len++;
//			if (cur_len > max_len)
//			{
//				max_len = cur_len;
//			}
//		}
//		else if (nums[i] == nums[i - 1])
//		{
//
//		}
//		//nums[i] - nums[i - 1] > 1
//		else
//		{
//			cur_len = 1;
//		}
//	}
//	return max_len;
//}

//优化做法
int longestConsecutive(int* nums, int numsSize) {
	if (numsSize <= 1)
		return numsSize;

	unsigned int* buff = (unsigned int*)malloc(sizeof(unsigned int) * numsSize);
	unsigned int* src = (unsigned int*)nums;
	unsigned int* dest = buff;

	//让负数排到正数前面（异或）
	for (int i = 0; i < numsSize; i++)
	{
		src[i] ^= 0x80000000;
	}

	//核心思想（基数排序）把 32 位整数切成 4 个字节，跑 4 轮 (从低位到高位)
	for (int k = 0; k < 4; k++)
	{
		int cnt[256] = { 0 };

		//第 1 步：点名记账（算频率）。只看第 k 个字节
		for (int i = 0; i < numsSize; i++)
		{
			int byte_val = (src[i] >> (k * 8)) & 0xFF;
			cnt[byte_val]++;
		}

		//第 2 步：前缀和算坐标。算出每种字节对应的“最后一个座位号”
		for (int i = 1; i < 256; i++)
		{
			cnt[i] += cnt[i - 1];
		}

		//第 3 步：对号入座（逆序遍历，保证稳定性）。数字直接飞到 dest 里
		for (int i = numsSize - 1; i >= 0; i--)
		{
			unsigned int val = src[i];
			int byte_val = (val >> (k * 8)) & 0xFF;

			//cnt-- 极其精妙：先让座位号减 1（变成 C 语言的 0-based 下标），然后入座
			cnt[byte_val]--;
			dest[cnt[byte_val]] = val;
		}

		//第 4 步：指针戏法。第 k 轮排完了，下一轮的源头变成现在的 dest，目的地变成 src
		unsigned int* tmp = src;
		src = dest;
		dest = tmp;
	}

	free(dest);

	//脱掉马甲：把符号位翻转回来，恢复原汁原味的真实数字
	for (int i = 0; i < numsSize; i++)
	{
		nums[i] ^= 0x80000000;
	}

	//和最开始的做法相同
	int max_len = 1;
	int cur_len = 1;
	for (int i = 1; i < numsSize; i++)
	{
		if (nums[i] == nums[i - 1] + 1)
		{
			cur_len++;
			if (cur_len > max_len)
			{
				max_len = cur_len;
			}
		}
		else if (nums[i] != nums[i - 1])
		{
			cur_len = 1;
		}
		else
		{

		}
	}
	return max_len;
}