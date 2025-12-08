#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//反转字符串
void reverse(char* str, int start, int end)
{
	while (start < end)
	{
		char tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

//去除前导零
void remove_leading_zero(char* str)
{
	int len = strlen(str);
	int i = 0;
	while (i < len - 1 && str[i] == '0')
	{
		i++;
	}
	int j = 0;
	while (i < len)
	{
		str[j] = str[i];
		j++;
		i++;
	}	
	str[j] = '\0';
}

//去除后置零
void remove_trailing_zero(char* str)
{
	int len = strlen(str);
	int i = len - 1;
	while (i > 0 && str[i] == '0')
	{
		i--;
	}
	str[i + 1] = '\0';
}

int main()
{
	char s[25];
	scanf("%s", s);
	int len = strlen(s);
	bool isdecimal = false, isfraction = false, ispersent = false;
	int split = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '.')
		{
			isdecimal = true;
			split = i;
			break;
		}
		else if (s[i] == '/')
		{
			isfraction = true;
			split = i;
			break;
		}
		else if (s[i] == '%')
		{
			ispersent = true;
			split = i;
			break;
		}
	}
	if (isdecimal)
	{
		char integer[20] = { 0 };
		strncpy(integer, s, split);
		char decimal[20] = { 0 };
		strcpy(decimal, s + split + 1);
		reverse(integer, 0, strlen(integer) - 1);
		reverse(decimal, 0, strlen(decimal) - 1);
		remove_leading_zero(integer);
		remove_trailing_zero(decimal);
		printf("%s.%s", integer,decimal);
	}
	else if (isfraction)
	{
		char molecule[20] = { 0 };
		strncpy(molecule, s, split);
		char denominator[20] = { 0 };
		strcpy(denominator, s + split + 1);
		reverse(molecule, 0, strlen(molecule) - 1);
		reverse(denominator, 0, strlen(denominator) - 1);
		remove_leading_zero(molecule);
		remove_leading_zero(denominator);
		printf("%s/%s", molecule, denominator);
	}
	else if (ispersent)
	{
		char molecule[20] = { 0 };
		strncpy(molecule, s, split);
		reverse(molecule, 0, strlen(molecule) - 1);
		remove_leading_zero(molecule);
		printf("%s%%", molecule);
	}
	else
	{
		reverse(s, 0, strlen(s) - 1);
		remove_leading_zero(s);
		printf("%s", s);
	}
	return 0;
}

//
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <string.h>
//#include <stdbool.h>
//
//void reverse(char* str, int start, int end)
//{
//	while (start < end)
//	{
//		char tmp = str[start];
//		str[start] = str[end];
//		str[end] = tmp;
//		start++;
//		end--;
//	}
//}
//void removeleadingzero(char* str)
//{
//	int len = strlen(str);
//	int i = 0;
//	while (i < len - 1 && str[i] == '0')
//	{
//		i++;
//	}
//	if (i > 0)
//	{
//		int j = 0;
//		while (i < len)
//		{
//			str[j] = str[i];
//			j++;
//			i++;
//		}
//		str[j] = '\0';
//	}
//}
//void removetrailingzero(char* str)
//{
//	int len = strlen(str);
//	int i = len - 1;
//	while (i > 0 && str[i] == '0')
//	{
//		i--;
//	}
//	str[i + 1] = '\0';
//}
//int main()
//{
//	char s[30];
//	scanf("%s", s);
//	int len = strlen(s);
//	bool isdecimal = false, isfraction = false, ispersent = false;
//	int split = 0;//分隔号
//	for (int i = 0; i < len; i++)
//	{
//		if (s[i] == '.')
//		{
//			isdecimal = true;
//			split = i;
//			break;
//		}
//		else if (s[i] == '/')
//		{
//			isfraction = true;
//			split = i;
//			break;
//		}
//		else if (s[i] == '%')
//		{
//			ispersent = true;
//			split = i;
//			break;
//		}
//	}
//	if (isdecimal)
//	{
//		char integer[15] = { 0 };
//		char decimal[15] = { 0 };
//		strncpy(integer, s, split);
//		strcpy(decimal, s + split + 1);
//		reverse(integer, 0, strlen(integer) - 1);
//		removeleadingzero(integer);
//		reverse(decimal, 0, strlen(decimal) - 1);
//		removetrailingzero(decimal);
//		printf("%s.%s\n", integer, decimal);
//	}
//	else if (isfraction)
//	{
//		char numerator[15] = { 0 };
//		char denominator[15] = { 0 };
//		strncpy(numerator, s, split);
//		strcpy(denominator, s + split + 1);
//		reverse(numerator, 0, strlen(numerator) - 1);
//		removeleadingzero(numerator);
//		reverse(denominator, 0, strlen(denominator) - 1);
//		removeleadingzero(denominator);
//		printf("%s/%s\n", numerator, denominator);
//	}
//	else if (ispersent)
//	{
//		char number[30] = { 0 };
//		strncpy(number, s, split);
//		reverse(number, 0, strlen(number) - 1);
//		removeleadingzero(number);
//		printf("%s%%\n", number);
//	}
//	else
//	{
//		reverse(s, 0, strlen(s) - 1);
//		removeleadingzero(s);
//		printf("%s\n", s);
//	}
//	return 0;
//}