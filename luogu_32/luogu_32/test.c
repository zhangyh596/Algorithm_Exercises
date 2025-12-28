#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int main()
{
	int N;
	double R;
	scanf("%d %lf", &N, &R);
	double sum = 0;
	double arr[105][2];
	for (int i = 0; i < N; i++)
	{
		scanf("%lf %lf", &arr[i][0], &arr[i][1]);
	}
	for (int i = 0; i < N - 1; i++)
	{
		double dx = arr[i][0] - arr[i + 1][0];
		double dy = arr[i][1] - arr[i + 1][1];
		sum += sqrt(dx * dx + dy * dy);
	}
	//加上第1个点和第N个点的距离
	double dx = arr[0][0] - arr[N - 1][0];
	double dy = arr[0][1] - arr[N - 1][1];
	sum += sqrt(dx * dx + dy * dy);
	//加一段弧长，可以求出是一个钉子的周长
	sum += 3.1415926535 * R * 2;
	printf("%.2f", sum);
	return 0;
}