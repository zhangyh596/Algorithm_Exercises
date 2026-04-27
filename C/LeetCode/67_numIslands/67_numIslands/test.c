#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int start_x, int start_y, int rows, int cols, char** grid, int (*vis)[305]) {

	vis[start_x][start_y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = start_x + dx[i];
		int ny = start_y + dy[i];
		if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && vis[nx][ny] == 0 && grid[nx][ny] == '1')
		{
			dfs(nx, ny, rows, cols, grid, vis);
		}
	}

}
int numIslands(char** grid, int gridSize, int* gridColSize) {
	int vis[305][305] = { 0 };

	int count = 0;
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < *gridColSize; j++)
		{
			if (grid[i][j] == '1' && vis[i][j] == 0)
			{
				dfs(i, j, gridSize, *gridColSize, grid, vis);
				count++;
			}
		}
	}
	return count;
}