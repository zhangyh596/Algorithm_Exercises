#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int q[2000005];
int ans[1000005];
int head, tail;
int main()
{
	int n;
	scanf("%d", &n);
	head = 1;
	tail = n + 1;
	for (int i = 1; i <= n; i++)
	{
		q[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		q[tail] = q[head];
		tail++;
		head++;
		ans[q[head]] = i;
		head++;
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}