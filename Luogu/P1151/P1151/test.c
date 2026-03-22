#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int k;
	scanf("%d", &k);

	int count = 0;
	for (int i = 10000; i <= 30000; i++)
	{
		int sub1 = i / 100;
		int sub2 = (i % 10000) / 10;
		int sub3 = i % 1000;

		if (sub1 % k == 0 && sub2 % k == 0 && sub3 % k == 0)
		{
			printf("%d\n", i);
			count++;
		}
	}

	if (count == 0)
		printf("No\n");
	return 0;
}