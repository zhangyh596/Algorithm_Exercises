#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int dp[105][105];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = (dp[i - 1][j] % 100 + dp[i][j - 1] % 100) % 100;
		}
	}

	printf("%d\n", dp[n][n]);
	return 0;
}