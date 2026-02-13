#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int N, M, T;

int map[6][6];//地图
int vis[6][6];//标记该点是否来过
int sx, sy;
int fx, fy;
//移动方向
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int total;//记录方案总数

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
		if (tx >= 1 && tx <= N && ty >= 1 && ty <= M && map[tx][ty] == 0 && vis[tx][ty] == 0)
		{
			dfs(tx, ty);
		}
	}
	vis[x][y] = 0;
}

int main()
{
	scanf("%d %d %d", &N, &M, &T);
	scanf("%d %d %d %d", &sx, &sy, &fx, &fy);
	for (int i = 0; i < T; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
	}
	dfs(sx, sy);
	printf("%d", total);
	return 0;
}