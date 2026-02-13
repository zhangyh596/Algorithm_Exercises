#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int a[200005];
int s[200005];

int main()
{
	int n;
	scanf("%d", &n);
	int max = -1e20;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (s[i - 1] > 0)
		{
			s[i] = s[i] + a[i];
		}
		else
		{
			s[i] = a[i];
		}
		if (s[i] > max)
		{
			max = s[i];
		}
	}
	printf("%d", max);
	return 0;
}