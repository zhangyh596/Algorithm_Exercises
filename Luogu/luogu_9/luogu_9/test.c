#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int map[101][101] = { 0 };
	int torch[5][5] = {
		{0,0,1,0,0},
		{0,1,1,1,0},
		{1,1,1,1,1},
		{0,1,1,1,0},
		{0,0,1,0,0}
	};
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		for (int dx = -2; dx <= 2; dx++)
		{
			for (int dy = -2; dy <= 2; dy++)
			{
				int nx = x + dx;
				int ny = y + dy;
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && torch[dx + 2][dy + 2] == 1)
				{
					map[nx][ny] = 1;
				}
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		for (int dx = -2; dx <= 2; dx++)
		{
			for (int dy = -2; dy <= 2; dy++)
			{
				int nx = x + dx;
				int ny = y + dy;
				if (nx >= 0 && nx < n && ny >= 0 && ny < n)
				{
					map[nx][ny] = 1;
				}
			}
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 0)
			{
				count++;
			}
		}
	}
	printf("%d", count);
	return 0;
}


//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//
//int main()
//{
//	int n, m, k;
//	scanf("%d %d %d", &n, &m, &k);
//	int map[100][100] = { 0 };
//	int torch[5][5] = {
//		{0,0,1,0,0},
//		{0,1,1,1,0},
//		{1,1,1,1,1},
//		{0,1,1,1,0},
//		{0,0,1,0,0}
//	};
//	for (int i = 0; i < m; i++)
//	{
//		int x, y;
//		scanf("%d %d", &x, &y);
//		x--;
//		y--;
//		for (int dx = -2; dx <= 2; dx++)
//		{
//			for (int dy = -2; dy <= 2; dy++)
//			{
//				int nx = x + dx;
//				int ny = y + dy;
//				if (nx >= 0 && nx < n && ny >= 0 && ny < n && torch[dx + 2][dy + 2] == 1)
//				{
//					map[nx][ny] = 1;
//				}
//			}
//		}
//	}
//	for (int i = 0; i < k; i++)
//	{
//		int x, y;
//		scanf("%d %d", &x, &y);
//		x--;
//		y--;
//		for (int dx = -2; dx <= 2; dx++)
//		{
//			for (int dy = -2; dy <= 2; dy++)
//			{
//				int nx = x + dx;
//				int ny = y + dy;
//				if (nx >= 0 && nx < n && ny >= 0 && ny < n)
//				{
//					map[nx][ny] = 1;
//				}
//			}
//		}
//	}
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (map[i][j] == 0)
//			{
//				count++;
//			}
//		}
//	}
//	printf("%d", count);
//	return 0;
//}