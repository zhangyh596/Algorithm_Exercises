#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int a, b, c, d, e, f, g, h, k, x, y;

int main()
{
	scanf("%d %d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &k, &x, &y);
	int N = (y + a - 1) / a;//需要打的歌数
	int ans = 0;//花费loveca的个数
	d += x;
	while (N--)
	{
		if ((d - b) < 0)
		{
			ans++;
			d += c;
			d -= b;

			if ((f + g) >= e)
			{
				f = f + g - e;
				c += h;
				d += c;
				e += k;
			}
			else
			{
				f = f + g;
			}
		}
		else
		{
			d -= b;
			if ((f + g) >= e)
			{
				f = f + g - e;
				c += h;
				d += c;
				e += k;
			}
			else
			{
				f = f + g;
			}
		}
	}
	printf("%d", ans);
	return 0;
}