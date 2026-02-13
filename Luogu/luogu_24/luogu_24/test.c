#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int arr[1030][1030];

void solve(int x, int y, int len)
{
	if (len == 1)
		return;
	int half = len / 2;
	for (int i = x; i < x+half; i++)
	{
		for (int j = y; j < y+half; j++)
		{
			arr[i][j] = 0;
		}
	}
	solve(x + half, y, half);
	solve(x, y + half, half);
	solve(x + half, y + half, half);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int size = 1 << n;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = 1;
		}
	}
	solve(0, 0, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}