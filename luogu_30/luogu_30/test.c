#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

char arr[1005][105][15];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%s", arr[i][j]);
		}
	}
	//比对是否每个决策因素相同
	for (int j = 0; j < N; j++)
	{
		int flag = 1;//每一行相同flag为1
		char* base = arr[0][j];
		for (int i = 0; i < M; i++)
		{
			if (strcmp(base, arr[i][j]))
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			printf("%s", base);
		}
		else
		{
			printf("*");
		}
		if (j < N - 1)
		{
			printf(" ");
		}
	}
	return 0;
}