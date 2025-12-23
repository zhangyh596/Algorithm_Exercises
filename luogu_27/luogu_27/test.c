#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int isprime(int n)
{
	if (n < 2)
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
	for (int i = 2; i < n; i++)
	{
		if (isprime(i) == 0)
			continue;
		for (int j = i; j < n - i; j++)
		{
			if (isprime(j) == 0)
				continue;
			int k = n - i - j;
			if (isprime(k))
			{
				printf("%d %d %d", i, j, k);
				return 0;
			}
		}
	}
	return 0;
}