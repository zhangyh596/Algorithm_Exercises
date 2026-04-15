#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void add(int a[], int sum[])
{
	int carry = 0;// 进位
	for (int i = 0; i < 505; i++)
	{
		int total = a[i] + sum[i] + carry;
		sum[i] = total % 10;
		carry = total / 10;
	}
}

void mul(int n, int arr[])
{
	int carry = 0;
	for (int j = 0; j < 505; j++)
	{
		int total = arr[j] * n + carry;
		arr[j] = total % 10;
		carry = total / 10;
	}

}

int main()
{
	int n;
	scanf("%d", &n);

	int a[505] = { 0 };
	int b[505] = { 0 };

	a[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		mul(i, a);
		add(a, b);
	}

	int len = 505;
	while (len > 0 && b[len - 1] == 0)
	{
		len--;
	}
	for (int i = len - 1; i >= 0; i--)
	{
		printf("%d", b[i]);
	}
	return 0;
}