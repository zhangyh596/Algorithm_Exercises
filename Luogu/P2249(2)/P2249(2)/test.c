#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int arr[1000005];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < m; i++)
	{
		int q;
		scanf("%d", &q);
		int l = 1, r = n;
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (arr[mid] >= q)
				r = mid;
			else
				l = mid + 1;
		}
		if (arr[l] == q)
		{
			printf("%d ", l);
		}
		else
		{
			printf("-1 ");
		}
	}
	return 0;
}