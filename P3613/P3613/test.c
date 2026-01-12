#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct query
{
	int op;
	int i;
	int j;
	int k;
	int time;
};

struct query arr[100005];
int ans_arr[100005];//用来存储答案
int op_arr[100005];//用来记录原本第i次操作是不是查询

int cmp(const void* a, const void* b)
{
	struct query* pa = (struct query*)a;
	struct query* pb = (struct query*)b;

	if (pa->i != pb->i)
		return pa->i - pb->i;
	else if (pa->j != pb->j)
		return pa->j - pb->j;
	return pa->time - pb->time;
}

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &arr[i].op);
		op_arr[i] = arr[i].op;
		if (arr[i].op == 1)
		{
			scanf("%d %d %d", &arr[i].i, &arr[i].j, &arr[i].k);
		}
		else if (arr[i].op == 2)
		{
			scanf("%d %d", &arr[i].i, &arr[i].j);
		}
		arr[i].time = i;
	}
	qsort(arr, q, sizeof(struct query), cmp);
	int ans = 0;
	for (int i = 0; i < q; i++)
	{
		if (i >0 &&(arr[i].i != arr[i - 1].i || arr[i].j != arr[i - 1].j))
		{
			ans = 0;
		}
		if (arr[i].op == 1)
		{
			ans = arr[i].k;
		}
		else if (arr[i].op == 2)
		{
			ans_arr[arr[i].time] = ans;
		}
	}
	for (int i = 0; i < q; i++)
	{
		if (op_arr[i] == 2)
		{
			printf("%d\n", ans_arr[i]);
		}
	}
	return 0;
}