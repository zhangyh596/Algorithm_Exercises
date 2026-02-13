#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

int main()
{
	int a, b, c;
	int tmp[100][3];
	int k = 0;
	for (int i = 123; i <= 329; i++)
	{
		a = i;
		b = 2 * a;
		c = 3 * a;
		int used[10] = { 0 };//标记数字的使用情况
		int nums[3] = { a,b,c };
		int flag = true;
		for (int j = 0; j < 3; j++)
		{
			int current_num = nums[j];
			while (current_num > 0)
			{
				int digit = current_num % 10;
				if (digit == 0 || used[digit] == 1)
				{
					flag = false;
					break;
				}
				used[digit] = 1;
				current_num = current_num / 10;
			}
			if (flag == false)
			{
				break;
			}
		}
		if (flag == false)
			continue;
		tmp[k][0] = a;
		tmp[k][1] = b;
		tmp[k][2] = c;
		k++;
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", tmp[i][j]);
		}
		printf("\n");
	}
	return 0;
}