#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int count = 0;
	count += n;

	int cigar = 0;
	cigar += n;
	while (cigar >= k)
	{
		count += cigar / k;
		cigar = cigar % k + cigar / k;
	}

	printf("%d", count);
	return 0;
}