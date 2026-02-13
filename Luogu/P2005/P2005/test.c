#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int a[25000], b[25000], c[25000], r[25000];

int Compare(int a[], int b[], int lenA, int lenB)
{
	if (lenA > lenB)
	{
		return 1;
	}
	else if (lenA < lenB)
	{
		return -1;
	}
	else
	{
		for (int i = lenA - 1; i >= 0; i--)
		{
			if (a[i] > b[i])
			{
				return 1;
			}
			else if (a[i] < b[i])
			{
				return -1;
			}
		}
	}
	return 0;
}

int Sub(int r[], int b[], int lenR, int lenB)
{
	for (int i = 0; i < lenR; i++)
	{
		int val = 0;//存储当前要减去的数
		if (i < lenB)
		{
			val = b[i];
		}
		else
		{
			val = 0;
		}
		if (r[i] < val)
		{
			r[i] += 10;
			r[i + 1]--;
		}
		r[i] -= val;
	}
	//去除前导零
	while (lenR > 1 && r[lenR - 1] == 0)
	{
		lenR--;
	}
	return lenR;
}

void div(int a[], int b[], int c[], int r[], int lenA, int lenB)
{
	int len_r = 0;//余数长度

	//从最高位开始处理
	for (int i = lenA - 1; i >= 0; i--)
	{
		for (int j = len_r; j > 0; j--)
		{
			r[j] = r[j - 1];
		}
		r[0] = a[i];
		len_r++;
		//去除前导零,因为可能会出现00导致Compare出问题
		while (len_r > 1 && r[len_r - 1] == 0)
		{
			len_r--;
		}

		int ans = 0;
		while (Compare(r, b, len_r, lenB) >= 0)
		{
			len_r = Sub(r, b, len_r, lenB);//更新r和它的长度
			ans++;
		}
		c[i] = ans;
	}
}

int main()
{
	char s1[25000], s2[25000];
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

	div(a, b, c, r, len1, len2);

	while (len1 > 1 && c[len1 - 1] == 0)
	{
		len1--;
	}
	for (int i = len1 - 1; i >= 0; i--)
	{
		printf("%d", c[i]);
	}
}