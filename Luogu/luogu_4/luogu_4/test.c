#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	for (int d1 = 1; d1 <= 9; d1++)
	{
		int num = d1;
		if (num >= a && num <= b && is_prime(num))
			printf("%d\n", num);
	}
	if (11 >= a && 11 <= b)
		printf("11\n");
	for (int d1 = 1; d1 <= 9; d1++)
	{
		for (int d2 = 0; d2 <= 9; d2++)
		{
			int num = d1 * 100 + d2 * 10 + d1;
			if (num >= a && num <= b && is_prime(num))
				printf("%d\n", num);
		}
	}
	for (int d1 = 1; d1 <= 9; d1++)
	{
		for (int d2 = 0; d2 <= 9; d2++)
		{
			for (int d3 = 0; d3 <= 9; d3++)
			{
				int num = d1 * 10000 + d2 * 1000 + d3 * 100 + d2 * 10 + d1;
				if (num >= a && num <= b && is_prime(num))
					printf("%d\n", num);
			}
		}
	}
	for (int d1 = 1; d1 <= 9; d1++)
	{
		for (int d2 = 0; d2 <= 9; d2++)
		{
			for (int d3 = 0; d3 <= 9; d3++)
			{
				for (int d4 = 0; d4 <= 9; d4++)
				{
					int num = d1 * 1000000 + d2 * 100000 + d3 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
					if (num >= a && num <= b && is_prime(num))
						printf("%d\n", num);
				}
			}
		}
	}
	return 0;
}



//#define _CRT_SECURE_NO_WARNINGS 1
//
//
//#include <stdio.h>
//#include <stdbool.h>
//#include <math.h>
//
//bool isprime(int n)
//{
//    if (n <= 1)
//    {
//        return false;
//    }
//    if (n == 2)
//    {
//        return true;
//    }
//    if (n % 2 == 0)
//    {
//        return false;
//    }
//    for (int i = 3; i <= sqrt(n); i += 2)
//    {
//        if (n % i == 0)
//        {
//            return false;
//        }
//
//    }
//    return true;
//}
//
//int main()
//{
//    int a, b;
//    scanf("%d %d", &a, &b);
//    for (int d1 = 1; d1 <= 9; d1++)
//    {
//        int palindrome = d1;
//        if (palindrome >= a && palindrome <= b && isprime(palindrome))
//        {
//            printf("%d\n", palindrome);
//        }
//    }
//    if (a <= 11 && b >= 11 && isprime(11))
//    {
//        printf("11\n");
//    }
//    for (int d1 = 1; d1 <= 9; d1++)
//    {
//        for (int d2 = 0; d2 <= 9; d2++)
//        {
//            int palindrome = d1 * 100 + d2 * 10 + d1;
//            if (palindrome >= a && palindrome <= b && isprime(palindrome))
//            {
//                printf("%d\n", palindrome);
//            }
//        }
//    }
//    for (int d1 = 1; d1 <= 9; d1++)
//    {
//        for (int d2 = 0; d2 <= 9; d2++)
//        {
//            for (int d3 = 0; d3 <= 9; d3++)
//            {
//                int palindrome = d1 * 10000 + d2 * 1000 + d3 * 100 + d2 * 10 + d1;
//                if (palindrome >= a && palindrome <= b && isprime(palindrome))
//                {
//                    printf("%d\n", palindrome);
//                }
//            }
//        }
//    }
//    for (int d1 = 1; d1 <= 9; d1++)
//    {
//        for (int d2 = 0; d2 <= 9; d2++)
//        {
//            for (int d3 = 0; d3 <= 9; d3++)
//            {
//                for (int d4 = 0; d4 <= 9; d4++)
//                {
//                    int palindrome = d1 * 1000000 + d2 * 100000 + d3 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
//                    if (palindrome >= a && palindrome <= b && isprime(palindrome))
//                    {
//                        printf("%d\n", palindrome);
//                    }
//                }
//            }
//        }
//    }
//
//    return 0;
//}