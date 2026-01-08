#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int main()
{
	int x1, x2, y1, y2;
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	int dy = y1 - y2;
	int dx = x1 - x2;
	if (dx < 0)//保证分母一直为正数
	{
		dx = -dx;
		dy = -dy;
	}
	//计算k，b
	int g1 = gcd(abs(dy), abs(dx));
	int k_mol = dy / g1;
	int k_den = dx / g1;
	int b_mol = y1 * k_den - k_mol * x1;
	int b_den = k_den;
	int g2 = gcd(abs(b_mol), abs(b_den));
	b_mol = b_mol / g2;
	b_den = b_den / g2;
	//开始输出
	printf("y=");
	if (k_den == 1)
	{
		printf("%dx", k_mol);
	}
	else
	{
		printf("%d/%d*x", k_mol, k_den);
	}
	if (b_mol != 0)
	{
		if (b_mol > 0)
		{
			printf("+");
		}
		else
		{

		}
		if (b_den == 1)
		{
			printf("%d", b_mol);
		}
		else
		{
			printf("%d/%d", b_mol, b_den);
		}
	}
	return 0;
}