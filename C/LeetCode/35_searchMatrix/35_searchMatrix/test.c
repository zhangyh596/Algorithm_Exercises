#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

//二分查找做法
//bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
//	int left1 = 0, right1 = matrixSize - 1;
//	while (left1 < right1)
//	{
//		int mid = (left1 + right1) / 2;
//		if (matrix[mid][0] >= target)
//		{
//			right1 = mid;
//		}
//		else
//		{
//			left1 = mid + 1;
//		}
//	}
//
//	for (int i = 0; i <= left1; i++)
//	{
//		int left2 = 0, right2 = *matrixColSize - 1;
//		while (left2 < right2)
//		{
//			int mid = (left2 + right2) / 2;
//			if (matrix[i][mid] >= target)
//			{
//				right2 = mid;
//			}
//			else
//			{
//				left2 = mid + 1;
//			}
//		}
//
//		if (matrix[i][left2] == target)
//		{
//			return true;
//		}
//	}
//
//	return false;
//}

//方案优化（在矩阵走迷宫）
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
	int x = *matrixColSize - 1, y = 0;
	while (x >= 0 && y < matrixSize)
	{
		if (matrix[y][x] == target)
		{
			return true;
		}
		else if (matrix[y][x] > target)
		{
			x--;
		}
		else
		{
			y++;
		}
	}
	return false;
}