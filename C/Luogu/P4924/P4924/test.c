#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[505][505];
int tmp[505][505];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = (i - 1) * n + j;
		}
	}

	for (int step = 0; step < m; step++)
	{
		int x, y, r, z;
		scanf("%d %d %d %d", &x, &y, &r, &z);

		if (z == 0)
		{
			for (int i = x - r; i <= x + r; i++)
			{
				for (int j = y - r; j <= y + r; j++)
				{
					tmp[x + j - y][y - i + x] = arr[i][j];
				}
			}
		}
		else if (z == 1)
		{
			for (int i = x - r; i <= x + r; i++)
			{
				for (int j = y - r; j <= y + r; j++)
				{
					tmp[x + y - j][y + i - x] = arr[i][j];
				}
			}
		}

		for (int i = x - r; i <= x + r; i++)
		{
			for (int j = y - r; j <= y + r; j++)
			{
				arr[i][j] = tmp[i][j];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}