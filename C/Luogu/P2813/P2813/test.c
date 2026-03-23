#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int M, N;
int arr1[100005];
int arr2[100005];

int cmp(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}

int main()
{
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= M; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr2[i]);
	}

	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	qsort(&arr1[1], M, sizeof(arr1[0]), cmp);
	qsort(&arr2[1], N, sizeof(arr2[0]), cmp);

	long long ans = 0;
	int i = 1, j = 1;
	while (i <= N && j <= M)
	{
		if (arr2[i] > arr1[j])
		{
			i++;
			j++;
		}
		else
		{
			ans += arr2[i];
			i++;
		}
	}
	if (j <= M)
	{
		printf("0");
	}
	else
	{
		while (i <= N)
		{
			ans += arr2[i];
			i++;
		}
		printf("%lld", ans);
	}
	return 0;
}