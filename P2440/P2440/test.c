#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int n, k;
int arr[100005];

int check(int x)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i] / x;
	}
	if (sum >= k)
		return 1;
	else
		return 0;
}
int main()
{
	scanf("%d %d", &n, &k);
	int max_arr = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > max_arr)
			max_arr = arr[i];
	}
	int l = 1, r = max_arr;
	while (l < r)
	{
		int mid = (l + r + 1) / 2;
		if (check(mid))
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	printf("%d", l);
	return 0;
}