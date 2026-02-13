#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arr[100005];
int score[100005];

int cmp(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	int sum = 0;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &arr[i]);
	}
	//对arr进行排序
	qsort(&arr[1], m, sizeof(int), cmp);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &score[i]);
		//二分查找模板
		int l = 1, r = m;
		while (l < r)
		{
			int mid = (l + r) / 2;//向下取整
			if (arr[mid] >= score[i])
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		//如果l是1，那么分差最小的只能是arr[l]
		if (l == 1)
		{
			sum += abs(arr[l] - score[i]);
		}
		//由于l的值不会超过m
		else 
		{
			int d1 = abs(arr[l] - score[i]);
			int d2 = abs(arr[l - 1] - score[i]);
			if (d1 <= d2)
			{
				sum += d1;
			}
			else
			{
				sum += d2;
			}
		}
	}
	printf("%d", sum);
	return 0;
}