#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int N;
int arr[55];

int main()
{
	int card[12] = { 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 16, 4 };
	scanf("%d", &N);
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
		card[arr[i]]--;
	}

	int X = (21 - sum) > 11 ? 11 : 21 - sum;
	int count = 0;
	for (int i = 2; i <= X; i++)
	{
		count += card[i];
	}

	if (count > 52 - N - count)
	{
		printf("VUCI\n");
	}
	else
	{
		printf("DOSTA\n");
	}
	return 0;
}