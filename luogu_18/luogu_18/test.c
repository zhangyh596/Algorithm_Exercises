#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int isprime(int n)
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
	int n = 0;
	scanf("%d", &n);
	int arr[101] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (isprime(arr[i]))
		{
			printf("%d ", arr[i]);
		}
	}
	return 0;
}