#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//typedef long long LL;
//int main()
//{
//	LL a, c, p, q, r, x;
//	scanf("%lld %lld %lld %lld %lld %lld", &a, &c, &p, &q, &r, &x);
//	while (x > 0)
//	{
//		if (a < c)
//		{
//			x -= p;
//			if (x < 0)
//				break;
//			a++;
//		}
//		else if (a == c)
//		{
//			x -= q;
//			if (x < 0)
//				break;
//		}
//		else
//		{
//			x -= r;
//			if (x < 0)
//				break;
//			a++;
//		}
//	}
//	printf("%lld", a);
//	return 0;
//}

#include <stdio.h>

typedef long long LL;
int main()
{
	LL a, c, p, q, r, x;
	scanf("%lld %lld %lld %lld %lld %lld", &a, &c, &p, &q, &r, &x);

	if (a > c)
	{
		printf("%lld", a + x / r);
	}
	else
	{
		LL time1 = (c - a) * p;
		if (x < time1)
		{
			printf("%lld", a + x / p);
		}
		else
		{
			x -= time1;
			if (x <= q)
			{
				printf("%lld", c);
			}
			else
			{
				x -= q;
				printf("%lld", c + x / r);
			}
		}
	}
	return 0;
}