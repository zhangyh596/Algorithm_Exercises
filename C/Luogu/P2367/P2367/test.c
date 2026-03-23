#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int n, p;
int a[5000005];
int b[5000005];

int main()
{
	scanf("%d %d", &n, &p);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	//处理b数组
	for (int i = 1; i <= n; i++)
	{
		b[i] = a[i] - a[i - 1];
	}
	//增加分数
	for (int i = 0; i < p; i++)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		b[x] += z;
		b[y + 1] -= z;
	}
	int min = 0x7fffffff;
	for (int i = 1; i <= n; i++)
	{
		b[i] = b[i] + b[i - 1];
		if (b[i] < min)
		{
			min = b[i];
		}
	}
	printf("%d", min);
	return 0;
}