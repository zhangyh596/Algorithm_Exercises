#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{
	char s1[2005], s2[2005];
	scanf("%s %s", s1, s2);
	int len1 = strlen(s1), len2 = strlen(s2);
	int a[2005] = { 0 }, b[2005] = { 0 }, c[4005] = { 0 };
	for (int i = 0; i < len1; i++)
	{
		a[i] = s1[len1 - 1 - i] - '0';
	}
	for (int i = 0; i < len2; i++)
	{
		b[i] = s2[len2 - 1 - i] - '0';
	}
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			c[i + j] += a[i] * b[j];
		}
	}
	for (int k = 0; k < len1 + len2; k++)
	{
		if (c[k] >= 10)
		{
			c[k + 1] += c[k] / 10;
			c[k] = c[k] % 10;
		}
	}
	int len = len1 + len2;
	while (len > 1 && c[len - 1] == 0)
	{
		len--;
	}
	for (int i = len - 1; i >= 0; i--)
	{
		printf("%d", c[i]);
	}
	return 0;
}