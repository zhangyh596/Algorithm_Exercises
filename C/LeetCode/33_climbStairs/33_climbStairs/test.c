#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//递归超时
//int climbStairs(int n) {
//	if (n == 1)
//		return 1;
//	else if (n == 2)
//		return 1;
//	else
//		return climbStairs(n - 1) + climbStairs(n - 2);
//}

int climbStairs(int n) {
	int dp[50];
	dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}