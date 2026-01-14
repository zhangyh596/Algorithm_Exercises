#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct carpet
{
	int a, b, g, k;
};

struct carpet arr[10005];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d %d", &arr[i].a, &arr[i].b, &arr[i].g, &arr[i].k);
	}
	int x, y;
	scanf("%d %d", &x, &y);
	for (int i = n; i >= 1; i--)
	{
		if (x >= arr[i].a && x <= arr[i].a + arr[i].g && y >= arr[i].b && y <= arr[i].b + arr[i].k)
		{
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}