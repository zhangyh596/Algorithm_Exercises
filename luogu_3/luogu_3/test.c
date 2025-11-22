#define _CRT_SECURE_NO_WARNINGS 1
//ÖÊÊý¿Ú´üP5723
#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
		if (n == 1)
			return 0;
		if (n == 2)
			return 1;
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
				return 0;
		}
	return 1;
}
int main()
{
	int L;
	scanf("%d", &L);
	int sum = 0;
	int i = 2;
	int count = 0;
	while (1)
	{
		if (is_prime(i))
		{
			sum += i;
			if (sum > L)
				break;
			count++;
			printf("%d\n", i);
		}
		i++;
	}
	printf("%d\n", count);
	return 0;
}

//
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//
//int main()
//{
//	int i = 1;
//	int n = 0;
//	scanf("%d", &n);
//	int count = 0;
//	int sum = 0;
//	for (i = 2; i <= n; i++)
//	{
//		int j = 0;
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j == i)
//		{
//			if (sum + i <= n)
//			{
//				printf("%d\n", i);
//				sum += i;
//				count++;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}