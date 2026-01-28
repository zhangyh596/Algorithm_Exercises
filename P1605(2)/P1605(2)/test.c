#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int n, m, t;

int map[10][10] = { 0 };
int vis[10][10] = { 0 };//标记走过的路

int sx, sy, fx, fy;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int total;//记录路径数
void dfs(int x, int y)
{
	if (x == fx && y == fy)
	{
		total++;
		return;
	}
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && vis[tx][ty] == 0 && map[tx][ty] == 0)
		{
			dfs(tx, ty);
		}
	}
	vis[x][y] = 0;
}

int main()
{
	scanf("%d %d %d", &n, &m, &t);
	scanf("%d %d %d %d", &sx, &sy, &fx, &fy);
	for (int i = 0; i < t; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		map[x][y] = 1;//标记障碍物
	}
	dfs(sx, sy);
	printf("%d", total);
	return 0;
}