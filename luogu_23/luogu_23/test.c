#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

int n;
char origin[15][15];
char target[15][15];
char buffer1[15][15];
char buffer2[15][15];

void rotate(char src[15][15], char dest[15][15])//旋转90度 
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dest[j][n - i + 1] = src[i][j];
		}
	}
}
void reflect(char src[15][15], char dest[15][15])//水平反射
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dest[i][n - j + 1] = src[i][j];
		}
	}
}
bool isequal(char src[15][15], char dest[15][15])//判断两个矩阵是否相同 
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (src[i][j] != dest[i][j])
				return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", origin[i] + 1);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", target[i] + 1);
	}
	rotate(origin, buffer1);
	if (isequal(buffer1, target))
	{
		printf("1");
		return 0;
	}
	rotate(buffer1, buffer2);
	if (isequal(buffer2, target))
	{
		printf("2");
		return 0;
	}
	rotate(buffer2, buffer1);
	if (isequal(buffer1, target))
	{
		printf("3");
		return 0;
	}
	reflect(origin, buffer1);
	if (isequal(buffer1, target))
	{
		printf("4");
		return 0;
	}
	rotate(buffer1, buffer2);
	if (isequal(buffer2, target))
	{
		printf("5");
		return 0;
	}
	rotate(buffer2, buffer1);
	if (isequal(buffer1, target))
	{
		printf("5");
		return 0;
	}
	rotate(buffer1, buffer2);
	if (isequal(buffer2, target))
	{
		printf("5");
		return 0;
	}
	if (isequal(origin, target))
	{
		printf("6");
		return 0;
	}
	printf("7");
	return 0;
}