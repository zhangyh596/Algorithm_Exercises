#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int arr[1000005];
int obj[100005];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &obj[i]);
		int l = 1, r = n;
		while (l < r)
		{
			int mid = (r + l) / 2;
			if (arr[mid] >= obj[i])
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		if (arr[l] == obj[i])
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