#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	double avg = 0;
	double max_avg = 0;
	for (int i = 0; i < n; i++)
	{
		int arr[20] = { 0 };
		int max = 0;
		int min = 10;
		int sum = 0;
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[j]);
			sum += arr[j];
			if (arr[j] > max)
				max = arr[j];
			if (arr[j] < min)
				min = arr[j];
		}
		avg = (sum - max - min) * 1.0 / (m - 2);
		if (avg > max_avg)
			max_avg = avg;
	}
	printf("%.2f", max_avg);
	return 0;
}


//#include <stdio.h>
//
//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//	double max_stu = 0.0;
//	for (int i = 0; i < n; i++)
//	{
//		int sum = 0;
//		int max = 0;
//		int min = 10;
//		for (int j = 0; j < m; j++)
//		{
//			int score;
//			scanf("%d", &score);
//			sum += score;
//			if (score > max)
//				max = score;
//			if (score < min)
//				min = score;
//		}
//		double stu_score = (sum - max - min) * 1.0 / (m - 2);
//		if (stu_score > max_stu)
//			max_stu = stu_score;
//	}
//	printf("%.2f", max_stu);
//	return 0;
//}