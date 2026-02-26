#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
	int left1 = 0, right1 = matrixSize - 1;
	int mid1 = 0, mid2 = 0;
	while (left1 < right1)
	{
		mid1 = (left1 + right1) / 2;
		if (matrix[mid1][0] >= target)
		{
			right1 = mid1;
		}
		else
		{
			left1 = mid1 + 1;
		}
	}

	int left2 = 0, right2 = *matrixColSize - 1;
	while (left2 < right2)
	{
		mid2 = (left2 + right2) / 2;
		if (matrix[mid1][mid2] >= target)
		{
			right2 = mid2;
		}
		else
		{
			left2 = mid2 + 1;
		}
	}

	if (matrix[left1][left2] != target)
	{
		return false;
	}
	else
	{
		return true;
	}
}