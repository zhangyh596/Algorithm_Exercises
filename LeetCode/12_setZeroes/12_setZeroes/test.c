#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
	int row_record[205] = { 0 };
	int col_record[205] = { 0 };

	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < *matrixColSize; j++)
		{
			if (matrix[i][j] == 0)
			{
				row_record[i] = 1;
				col_record[j] = 1;
			}
		}
	}

	for (int i = 0; i < matrixSize; i++)
	{
		if (row_record[i] == 1)
		{
			for (int j = 0; j < *matrixColSize; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < *matrixColSize; i++)
	{
		if (col_record[i] == 1)
		{
			for (int j = 0; j < matrixSize; j++)
			{
				matrix[j][i] = 0;
			}
		}
	}
}