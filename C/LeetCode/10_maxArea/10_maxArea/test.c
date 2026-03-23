#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int maxArea(int* height, int heightSize) {
//	int max_area = 0;
//	for (int i = 0; i < heightSize; i++)
//	{
//		int cur_area = 0;
//		for (int j = i + 1; j < heightSize; j++)
//		{
//			if (height[j] < height[i])
//			{
//				cur_area = height[j] * (j - i);
//			}
//			else
//			{
//				cur_area = height[i] * (j - i);
//			}
//
//			if (cur_area > max_area)
//			{
//				max_area = cur_area;
//			}
//		}
//	}
//	return max_area;
//}

//优化算法
int maxArea(int* height, int heightSize) {
	int left = 0, right = heightSize - 1;
	int max_area = 0;
	while (left < right)
	{
		int cur_area = 0;
		if (height[left] > height[right])
		{
			cur_area = height[right] * (right - left);
			right--;
		}
		else
		{
			cur_area = height[left] * (right - left);
			left++;
		}

		if (cur_area > max_area)
		{
			max_area = cur_area;
		}
	}
	return max_area;
}