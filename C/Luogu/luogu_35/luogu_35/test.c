#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int arr[100001];

int cmp(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}
int main()
{
	int n, dist;
	scanf("%d %d", &n, &dist);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), cmp);
	int count = 0;
	for (int i = 0; i + 2 < n; i++)
	{
		if (arr[i + 2] - arr[i] <= dist)
		{
			arr[i + 1] = arr[i];
			count++;
		}
	}
	printf("%d", count);
	return 0;
}