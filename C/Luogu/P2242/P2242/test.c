#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int n, m;
int a[15005];
int b[15005];

int cmp(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);

		if (i > 0)
		{
			b[i] = a[i] - a[i - 1] - 1;
		}
	}

	qsort(b + 1, n - 1, sizeof(int), cmp);
	int ans = a[n - 1] - a[0] + 1;
	for (int i = 0; i < m - 1; i++)//分成m段只需要切m - 1刀
	{
		ans -= b[n - 1];
		n--;
	}
	printf("%d", ans);
	return 0;
}