#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int arr[39][39] = { 0 };
	int i = 0;
	int j = N / 2;
	arr[i][j] = 1;
	for (int k = 2; k <= N * N; k++)
	{
		if (i == 0 && j != N - 1)
		{
			arr[N - 1][j + 1] = k;
			i = N - 1; 
			j = j + 1;
			continue;
		}
		else if (j == N - 1 && i != 0)
		{
			arr[i - 1][0] = k;
			i = i - 1;
			j = 0;
			continue;
		}
		else if (i == 0 && j == N - 1)
		{
			arr[i + 1][j] = k;
			i = i + 1;
			j = j;
			continue;
		}
		else
		{
			if (i != 0 && j != N - 1 && arr[i - 1][j + 1] == 0)
			{
				arr[i - 1][j + 1] = k;
				i = i - 1;
				j = j + 1;
				continue;
			}
			else if (i != 0 && j != N - 1 && arr[i - 1][j + 1] != 0)
			{
				arr[i + 1][j] = k;
				i = i + 1;
				j = j;
				continue;
			}
		}
		
	}
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			printf("%d ", arr[row][col]);
		}
		printf("\n");
	}
	return 0;
}



//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//
//int main()
//{
//	int N = 0;
//	scanf("%d", &N);
//	int arr[200][200] = { 0 };
//	int i = 0;
//	int j = N / 2;
//	arr[i][j] = 1;
//	for (int k = 2; k <= N * N; k++)
//	{
//		int new_i, new_j;
//		if (i == 0 && j != N - 1)
//		{
//			new_i = N - 1;
//			new_j = j + 1;
//		}
//		else if (i != 0 && j == N - 1)
//		{
//			new_i = i - 1;
//			new_j = 0;
//		}
//		else if (i == 0 && j == N - 1)
//		{
//			new_i = i + 1;
//			new_j = j;
//		}
//		else
//		{
//			new_i = i - 1;
//			new_j = j + 1;
//			if (arr[new_i][new_j] != 0)
//			{
//				new_i = i + 1;
//				new_j = j;
//			}
//		}
//		arr[new_i][new_j] = k;
//		i = new_i;
//		j = new_j;
//	}
//	for (int row = 0; row < N; row++)
//	{
//		for (int col = 0; col < N; col++)
//		{
//			printf("%d ", arr[row][col]);
//		}
//		printf("\n");
//	}
//	return 0;
//}