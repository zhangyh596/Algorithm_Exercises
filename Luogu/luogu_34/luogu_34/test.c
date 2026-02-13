#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int arr[10005];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		int l = i;
		int r = i;
		while (l > 0 && arr[l - 1] <= arr[l])
		{
			l--;
		}
		while (r < N - 1 && arr[r + 1] <= arr[r])
		{
			r++;
		}
		int current = r - l + 1;
		if (current > max)
		{
			max = current;
		}
	}
	printf("%d", max);
	return 0;
}