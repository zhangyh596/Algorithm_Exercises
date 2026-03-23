#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int n;

int main()
{
	scanf("%d", &n);
	if (n < 9)
	{
		printf("0\n");
	}
	else if (n == 9)
	{
		printf("8\n");
	}
	else
	{
		printf("72");
		for (int i = 0; i < n - 10; i++)
		{
			printf("0");
		}
		printf("\n");
	}
	return 0;
}