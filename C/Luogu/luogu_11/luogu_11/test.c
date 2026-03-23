#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <math.h>

int isprime(int n)
{
	if (n < 2)
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
	char word[100];
	scanf("%s", word);
	int count[26] = { 0 };
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		count[word[i] - 'a']++;
	}
	int maxn = 0;
	int minn = 100;
	for (int i = 0; i < 26; i++)
	{
		if (count[i] > 0)
		{
			if (count[i] > maxn)
				maxn = count[i];
			if (count[i] < minn)
				minn = count[i];
		}
	}
	int ret = maxn - minn;
	if (isprime(ret))
	{
		printf("Lucky Word\n");
		printf("%d", ret);
	}
	else
	{
		printf("No Answer\n");
		printf("0");
	}
	return 0;
}


//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//
//int isprime(int n)
//{
//	if (n <= 1)
//		return 0;
//	if (n == 2)
//		return 1;
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	char word[100];
//	int count[26] = { 0 };
//	scanf("%s", word);
//	int len = strlen(word);
//	for (int i = 0; i < len; i++)
//	{
//		count[word[i] - 'a']++;
//	}
//	int maxn = 0;
//	int minn = 100;
//	for (int i = 0; i < 26; i++)
//	{
//		if (count[i] > 0)
//		{
//			if (count[i] > maxn)
//				maxn = count[i];
//			if (count[i] < minn)
//				minn = count[i];
//		}
//	}
//	if (isprime(maxn - minn))
//		printf("Lucky Word\n%d", maxn - minn);
//	else
//		printf("No Answer\n0");
//	return 0;
//}