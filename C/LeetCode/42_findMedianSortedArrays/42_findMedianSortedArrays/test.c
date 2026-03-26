#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//暴力解法
//double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
//	int* nums = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));
//
//	int i = 0, j = 0, k = 0;
//	while (i < nums1Size && j < nums2Size)
//	{
//		if (nums1[i] < nums2[j])
//		{
//			nums[k++] = nums1[i++];
//		}
//		else
//		{
//			nums[k++] = nums2[j++];
//		}
//	}
//	if (i < nums1Size)
//	{
//		while (i < nums1Size)
//		{
//			nums[k++] = nums1[i++];
//		}
//	}
//	else
//	{
//		while (j < nums2Size)
//		{
//			nums[k++] = nums2[j++];
//		}
//	}
//
//	int numsSize = nums1Size + nums2Size;
//	double ret = 0;
//	if (numsSize % 2 == 0)
//	{
//		ret = (nums[numsSize / 2 - 1] + nums[numsSize / 2]) / 2.0;
//	}
//	else
//	{
//		ret = nums[(numsSize + 1) / 2 - 1];
//	}
//	return ret;
//}

//在两个有序数组中找第 k 小的元素
int findK(int* nums1, int size1, int* nums2, int size2, int k)
{
	// 如果 size1 == 0，说明 nums1 全被淘汰了，直接返回 nums2 的第 k 个元素
	if (size1 == 0)
		return nums2[k - 1];
	if (size2 == 0)
		return nums1[k - 1];
	// 如果 k == 1，说明我们要找剩下的最小元素，直接比较 nums1[0] 和 nums2[0] 谁小返回谁
	if (k == 1)
		return nums1[0] < nums2[0] ? nums1[0] : nums2[0];
	
	int p1 = (k / 2 < size1) ? (k / 2) : size1;
	int p2 = (k / 2 < size2) ? (k / 2) : size2;

	if (nums1[p1 - 1] < nums2[p2 - 1])
	{
		//只能确保nums1中的0到p1-1不符，不能把nums2中的0到p2-2也给删了(p1-1)撑死排到k-1位
		//例如nums1: 1, 2, 3, 4 ;nums2: 10, 20, 30, 40
		return findK(nums1 + p1, size1 - p1, nums2, size2, k - p1);
	}
	else
	{
		return findK(nums1, size1, nums2 + p2, size2 - p2, k - p2);
	}
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int numsSize = nums1Size + nums2Size;
	double k1 = findK(nums1, nums1Size, nums2, nums2Size, (numsSize + 1) / 2);
	double k2 = findK(nums1, nums1Size, nums2, nums2Size, (numsSize + 2) / 2);

	double ret = (k1 + k2) / 2.0;
	return ret;
}