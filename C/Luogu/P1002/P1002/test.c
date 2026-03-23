#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

long long dp[25][25];
int block[25][25];

int main()
{
	int n, m, horse_x, horse_y;
	scanf("%d %d %d %d", &n, &m, &horse_x, &horse_y);

	//将左平移2，y轴向上平移2，初始点变成（2，2）
	//防止马在（0,1）会跳到负数上
	dp[2][2] = 1;
	horse_x += 2;
	horse_y += 2;

	//马能走到的点
	block[horse_x][horse_y] = 1;
	int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	for (int i = 0; i < 8; i++)
	{
		block[horse_x + dx[i]][horse_y + dy[i]] = 1;
	}

	if (block[2][2] == 1)
	{
		dp[2][2] = 0;
	}

	//核心：dp方程
	for (int i = 2; i <= n + 2; i++)
	{
		for (int j = 2; j <= m + 2; j++)
		{
			if ((i == 2 && j == 2) || block[i][j] == 1)
			{
				continue;
			}
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}

	printf("%lld", dp[n + 2][m + 2]);
	return 0;
}