#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int trap(int* height, int heightSize) {
	int left = 0, right = heightSize - 1;
	int l_max = 0, r_max = 0;

	int ans = 0;
	while (left < right)
	{
		if (height[left] > l_max)
		{
			l_max = height[left];
		}
		
		if (height[right] > r_max)
		{
			r_max = height[right];
		}

		//利用木桶效应去算能接多少水
		if (l_max < r_max)
		{
			ans += l_max - height[left];
			left++;
		}
		else
		{
			ans += r_max - height[right];
			right--;
		}
	}
	return ans;
}