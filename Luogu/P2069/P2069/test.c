#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int arr[205];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}
	int j = 1, pos = 1;
	int ans = 0;
	while (j <= m)
	{
		pos = pos + j * j * j % 5 + 1;
		if (pos > n)
		{
			pos = 1;
			continue;
		}
		else
		{
			ans = arr[pos];
			for (int i = pos; i <= n - 1; i++)
			{
				arr[i] = arr[i + 1];
			}
			n--;
		}
		j++;
	}
	printf("%d", ans);
	return 0;
}