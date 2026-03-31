#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int vis[1005];

int main()
{
	int n;
	int arr[1005];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		
		if (i > 0)
		{
			if (abs(arr[i] - arr[i - 1]) >= 1 && abs(arr[i] - arr[i - 1]) < n)
			{
				vis[abs(arr[i] - arr[i - 1])] = 1;
			}
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (vis[i] == 0)
		{
			printf("Not jolly\n");
			return 0;
		}
	}

	printf("Jolly\n");
	return 0;
}