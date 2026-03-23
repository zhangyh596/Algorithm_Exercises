#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int arr[1001] = { 0 };
	int n;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	int min = 10;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	double avg = (sum - min - max) * 1.0 / (n - 2);
	printf("%.2f", avg);
	return 0;
}




//
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int score[1000] = { 0 };
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &score[i]);
//	}
//	int max = score[0];
//	int min = score[0];
//	float total = 0;
//	for (i = 0; i < n; i++)
//	{
//		total += score[i];
//		if (score[i] > max)
//		{
//			max = score[i];
//		}
//		if (score[i] < min)
//		{
//			min = score[i];
//		}
//	}
//	total = total - max - min;
//	float r = total / (n - 2);
//	printf("%.2f", r);
//	return 0;
//}