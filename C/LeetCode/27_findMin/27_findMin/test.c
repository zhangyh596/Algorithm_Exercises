#define _CRT_SECURE_NO_WARNINGS 1.

#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    int min = nums[0];
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] >= nums[left])
        {
            //可能已经恢复原样故需要检查一下nums[left]
            if (nums[left] < min)
            {
                min = nums[left];
            }
            left = mid + 1;
        }
        //右半部分是有序的，最小值在left和mid之间
        else
        {
            right = mid;
        }
    }
    //需要再次检查nums[left]是否小于min
    if (nums[left] < min)
    {
        min = nums[left];
    }
    return min;
}