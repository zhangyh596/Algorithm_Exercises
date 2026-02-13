#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{
	char s1[10090], s2[10090],s3[10090];
	scanf("%s %s", s1, s2);
	int a[10090] = { 0 }, b[10090] = { 0 }, c[10090] = { 0 };
	int len1 = strlen(s1), len2 = strlen(s2);
	int len = 0;
	if (len1 < len2) 
	{
		strcpy(s3, s1);
		strcpy(s1, s2);
		strcpy(s2, s3);
		len = len1;
		len1 = len2;
		len2 = len;
		printf("-");
	}
	else if (len1 == len2 && strcmp(s1, s2) < 0) 
	{
		strcpy(s3, s1);
		strcpy(s1, s2);
		strcpy(s2, s3);
		printf("-");
	}
	for (int i = 0; i < len1; i++)
	{
		a[i] = s1[len1 - 1 - i] - '0';
	}
	for (int i = 0; i < len2; i++)
	{
		b[i] = s2[len2 - 1 - i] - '0';
	}
	len = len1 > len2 ? len1 : len2;
	for (int i = 0; i < len; i++)
	{
		if (a[i] < b[i])
		{
			a[i] += 10;
			a[i + 1]--;
		}
		c[i] = a[i] - b[i];
	}
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