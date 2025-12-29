#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int main()
{
	double  v, angle;
	scanf("%lf %lf", &v, &angle);
	double t = v * cos(angle) / 10;
	double x = v * sin(angle) * t;
	double y = 5 * t * t;
	printf("%lf %lf", x, y);
	return 0;
}