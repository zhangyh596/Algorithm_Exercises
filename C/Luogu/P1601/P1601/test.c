#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int a[505], b[505], c[505];

int main()
{
	char s1[505], s2[505];
	scanf("%s %s", s1, s2);
	int len1 = strlen(s1), len2 = strlen(s2);
	for (int i = 0; i < len1; i++)
	{
		a[i] = s1[len1 - 1 - i] - '0';
	}
	for (int i = 0; i < len2; i++)
	{
		b[i] = s2[len2 - 1 - i] - '0';
	}
	int len = len1 > len2 ? len1 : len2;
	for (int i = 0; i < len; i++)
	{
		c[i] += a[i] + b[i];
		c[i + 1] += c[i] / 10;
		c[i] = c[i] % 10;
	}
	if (c[len] > 0)
	{
		printf("%d", c[len]);
	}
	for (int i = len - 1; i >= 0; i--)
	{
		printf("%d", c[i]);
	}
	return 0;
}