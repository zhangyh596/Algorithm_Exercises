#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int row[5001];
int col[5001];

int main()
{
	int N, M, B, G;
	scanf("%d %d %d %d", &N, &M, &B, &G);
	int x, y;
	//男生扫的
	for (int i = 0; i < B; i++)
	{
		scanf("%d %d", &x, &y);
		for (int j = x; j <= y; j++)
		{
			row[j] = 1;
		}
	}
	//女生扫的
	for (int i = 0; i < G; i++)
	{
		scanf("%d %d", &x, &y);
		for (int j = x; j <= y; j++)
		{
			col[j] = 1;
		}
	}
	int row_count = 0;
	int col_count = 0;
	for (int i = 1; i <= N; i++)
	{
		if (row[i] == 1)
			row_count++;
	}
	for (int i = 1; i <= M; i++)
	{
		if (col[i] == 1)
			col_count++;
	}
	int count = row_count * M + col_count * N - row_count * col_count;
	printf("%d", count);
	return 0;
}