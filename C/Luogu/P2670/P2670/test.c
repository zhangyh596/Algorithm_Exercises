#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

char vis[105][105];

int main()
{
	char map[105][105];
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", map[i]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == '*')
			{
				vis[i][j] = '*';
				continue;
			}

			vis[i][j] = '0';
			for (int k = 0; k < 8; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == '*')
				{
					vis[i][j]++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%s\n", vis[i]);
	}
	return 0;
}