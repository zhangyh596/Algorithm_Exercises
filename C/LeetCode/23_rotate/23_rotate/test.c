#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
	int** ans = (int**)malloc(matrixSize * sizeof(int*));
	for (int i = 0; i < matrixSize; i++)
	{
		ans[i] = (int*)malloc(sizeof(int) * (*matrixColSize));
	}

	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < *matrixColSize; j++)
		{
			ans[j][matrixSize - i - 1] = matrix[i][j];
		}
	}
	
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < *matrixColSize; j++)
		{
			matrix[i][j] = ans[i][j];
		}
	}
}