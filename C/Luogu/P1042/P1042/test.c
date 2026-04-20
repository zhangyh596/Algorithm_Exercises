#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

char s[100000];

int main()
{
	int len = 0;
	char ch;

	while (1)
	{
		scanf(" %c", &ch);
		if (ch == 'E')
		{
			s[len++] = ch;
			break;
		}
		s[len++] = ch;
	}

	int W = 0, L = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == 'W')
		{
			W++;
		}
		else if (s[i] == 'L')
		{
			L++;
		}
		else if (s[i] == 'E')
		{
			printf("%d:%d\n", W, L);
			break;
		}

		if ((W >= 11 || L >= 11) && abs(W - L) >= 2)
		{
			printf("%d:%d\n", W, L);
			W = 0, L = 0;
		}
	}
	printf("\n");

	W = 0, L = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == 'W')
		{
			W++;
		}
		else if (s[i] == 'L')
		{
			L++;
		}
		else if (s[i] == 'E')
		{
			printf("%d:%d\n", W, L);
			break;
		}

		if ((W >= 21 || L >= 21) && abs(W - L) >= 2)
		{
			printf("%d:%d\n", W, L);
			W = 0, L = 0;
		}
	}

	return 0;
}