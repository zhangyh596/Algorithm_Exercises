#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int f[1005];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		f[i] = 1;
		for (int j = 1; j <= i / 2; j++)
		{
			f[i] += f[j];
		}
	}
	printf("%d", f[n]);
	return 0;
}