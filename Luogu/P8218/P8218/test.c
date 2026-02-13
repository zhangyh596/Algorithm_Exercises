#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int a[100005];
int s[100005];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		s[i] = s[i - 1] + a[i];
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", s[r] - s[l - 1]);
	}
	return 0;
}