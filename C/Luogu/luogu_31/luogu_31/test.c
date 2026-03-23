#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

#define PI 3.1415926535

int main()
{
	int N;
	scanf("%d", &N);
	int arr[1001][2];
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	double min_area = 1e18;
	for (int i = 0; i < N; i++)
	{
		double max_s2 = 0;
		for (int j = 0; j < N; j++)
		{
			if (j == i)
				continue;
			double dx = arr[i][0] - arr[j][0];
			double dy = arr[i][1] - arr[j][1];
			double s2 = dx * dx + dy * dy;
			if (s2 > max_s2)
			{
				max_s2 = s2;
			}
		}
		double area = PI * max_s2;
		if (area < min_area)
		{
			min_area = area;
		}
	}
	printf("%.4f", min_area);
	return 0;
}