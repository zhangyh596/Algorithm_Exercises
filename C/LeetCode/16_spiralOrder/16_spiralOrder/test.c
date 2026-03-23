#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//移动方向
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
	int* ans = (int*)malloc(sizeof(int) * matrixSize * (*matrixColSize));

	int dir = 0;
	int x = 0, y = 0;
	for (int i = 0; i < matrixSize * (*matrixColSize); i++)
	{
		ans[i] = matrix[x][y];
		matrix[x][y] = 101;
		int new_x = x + dx[dir];
		int new_y = y + dy[dir];
		if (new_x < 0 || new_x >= matrixSize || new_y < 0 || new_y >= *matrixColSize || matrix[new_x][new_y] == 101)
		{
			dir = (dir + 1) % 4;
			new_x = x + dx[dir];
			new_y = y + dy[dir];
		}

		x = new_x;
		y = new_y;
	}
	*returnSize = matrixSize * (*matrixColSize);
	return ans;
}
