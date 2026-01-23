#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{
	char s[5005];
	long long b;
	scanf("%s %lld", s, &b);
	int len = strlen(s);
	int a[5005] = { 0 }, c[5005] = { 0 };
	for (int i = 0; i < len; i++)
	{
		a[i] = s[i] - '0';
	}
	long long r = 0;//³õÊ¼»¯ÓàÊý
	for (int i = 0; i < len; i++)
	{
		long long current = r * 10 + a[i];
		c[i] = current / b;
		r = current % b;
	}
	int j = 0;
	while (j < len - 1 && c[j] == 0)
	{
		j++;
	}
	for (; j < len; j++)
	{
		printf("%d", c[j]);
	}
	return 0;
}