#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int max(int n, int m)
{
	return (n > m) ? n : m;
}
int min(int n, int m)
{
	return (n < m) ? n : m;
}
int main()
{
	int n, m, k, t;
	scanf("%d %d %d %d", &n, &m, &k, &t);
	int ret = 0;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		int count = 0;
		for (int row = max(1, x - t); row <= min(n, x + t); row++)
		{
			for (int col = max(1, y - t); col <= min(m, y + t); col++)
			{
				int s = (row - x) * (row - x) + (col - y) * (col - y);
				if (s <= (t * t))
				{
					count++;
				}
			}
		}
		if (count > ret)
		{
			ret = count;
		}
	}
	printf("%d", ret);
	return 0;
}