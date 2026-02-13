#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void add(int sum[], int fact[])
{
	int carry = 0;
	for (int i = 0; i < 100; i++)
	{
		int total = sum[i] + fact[i] + carry;
		sum[i] = total % 10;
		carry = total / 10;
	}
}
void factorial(int n, int fact[])
{
	for (int i = 0; i < 100; i++)
	{
		fact[i] = 0;
	}
	fact[0] = 1;
	for (int i = 2; i <= n; i++)
	{
		int carry = 0;
		for (int j = 0; j < 100; j++)
		{
			int total = fact[j] * i + carry;
			fact[j] = total % 10;
			carry = total / 10;
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	
	int fact[100] = { 0 };
	int sum[100] = { 0 };

	for (int i = 1; i <= n; i++)
	{
		factorial(i, fact);
		add(sum, fact);
	}
	int high = 99;
	while (high > 0 && sum[high] == 0)
	{
		high--;
	}
	for (int i = high; i >= 0; i--)
	{
		printf("%d", sum[i]);
	}
	return 0;
}



//
//void add(int a[], int b[])
//{
//	int carry = 0;
//	for (int i = 0; i < 70; i++)
//	{
//		int sum = a[i] + b[i] + carry;
//		a[i] = sum % 10;
//		carry = sum / 10;
//
//	}
//}
//void factorial(int n, int result[])
//{
//	for (int i = 0; i < 70; i++)
//	{
//		result[i] = 0;
//	}
//	result[0] = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		int carry = 0;
//		for (int j = 0; j < 70; j++)
//		{
//			int product = result[j] * i + carry;
//			result[j] = product % 10;
//			carry = product / 10;
//		}
//	}
//}
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum[70];
//	int fact[70];
//	for (int i = 0; i < 70; i++)
//	{
//		sum[i] = 0;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j < 70; j++)
//		{
//			fact[j] = 0;
//		}
//		factorial(i, fact);
//		add(sum, fact);
//	}
//	int high = 70 - 1;
//	while (high >= 0 && sum[high] == 0)
//	{
//		high--;
//	}
//	for (int i = high; i >= 0; i--)
//	{
//		printf("%d", sum[i]);
//	}
//	printf("\n");
//	return 0;
//}