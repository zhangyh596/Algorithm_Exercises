#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int n, m, sx, sy;

struct Node
{
	int x, y;
};

struct Node queue[160005];

int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void bfs(int x, int y)
{
	int head = 0, tail = 0;//用head标记准备处理的点，用tail标记新位置
	queue[tail].x = sx, queue[tail].y = sy;
	tail++;
	int ans[405][405];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			ans[i][j] = -1;//初始化标记????位置都不能走到
		}
	}
	ans[x][y] = 0;//初始位置为0

	while (tail > head)
	{
		struct Node now = queue[head];
		head++;
		for (int i = 0; i < 8; i++)
		{
			int tx = now.x + dx[i];
			int ty = now.y + dy[i];
			if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && ans[tx][ty] == -1)
			{
				ans[tx][ty] = ans[now.x][now.y] + 1;
				queue[tail].x = tx;
				queue[tail].y = ty;
				tail++;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	scanf("%d %d %d %d", &n, &m, &sx, &sy);
	bfs(sx, sy);
	return 0;
}