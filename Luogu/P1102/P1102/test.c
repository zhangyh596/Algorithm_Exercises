#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int arr[200010];

int cmp(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}

int main()
{
	int N, C;
	scanf("%d %d", &N, &C);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}
	//对数组从小到大排序
	qsort(arr + 1, N, sizeof(int), cmp);
	//双指针启动
	int R1 = 1, R2 = 1;
	long long ans = 0;
	for (int i = 1; i <= N; i++)
	{
		long long target = (long long)arr[i] + (long long)C;
		//找到第一个等于target的数
		while (R1 <= N && arr[R1] < target)
		{
			R1++;
		}
		//找到第一个大于target的数
		while (R2 <= N && arr[R2] <= target)
		{
			R2++;
		}
		ans += R2 - R1;
	}
	printf("%lld", ans);
	return 0;
}