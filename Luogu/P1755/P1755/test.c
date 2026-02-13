#define _CRT_SECURE_NO_WARNINGS 1
	
#include <stdio.h>

int t;

int fib[46];//斐波那契数列
int ans[50];//存储找到的数

int main()
{
	scanf("%d", &t);
	//斐波那契数列逻辑
	fib[1] = 1, fib[2] = 1;
	for (int i = 3; i <= 45; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	for (int i = 0; i < t; i++)
	{
		int n = 0;
		scanf("%d", &n);
		printf("%d=", n);
		int index = 0;//记录ans的下标
		//从大到小进行遍历
		for (int j = 45; j >= 1; j--)
		{
			if (n >= fib[j])
			{
				ans[index] = fib[j];
				index++;
				n -= fib[j];
			}
		}
		for (int k = index - 1; k >= 0; k--)
		{
			if (k > 0)
				printf("%d+", ans[k]);
			else
				printf("%d", ans[k]);
		}
		printf("\n");
	}
	return 0;
}