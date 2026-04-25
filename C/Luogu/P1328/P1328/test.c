#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int N, NA, NB;
	scanf("%d %d %d", &N, &NA, &NB);

	int a[205], b[205];
	for (int i = 0; i < NA; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < NB; i++)
	{
		scanf("%d", &b[i]);
	}

	int win[5][5] =
	{
		{0, -1, 1, 1, -1},
		{1, 0, -1, 1, -1},
		{-1, 1, 0, -1, 1},
		{-1, -1, 1, 0, 1},
		{1, 1, -1, -1, 0}
	};

	int score_a = 0, score_b = 0;
	for (int i = 0; i < N; i++)
	{
		int a1 = a[i % NA];
		int b1 = b[i % NB];

		if (win[a1][b1] == 1)
		{
			score_a++;
		}
		else if(win[a1][b1] == -1)
		{
			score_b++;
		}
	}

	printf("%d %d", score_a, score_b);
	return 0;
}