#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

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
		str[j++] = str[i++];
	}
	str[j] = '\0';
}

int main()
{
	char word[6][200];
	int count = 0;
	int number[6] = { 0 };
	for (int i = 0; i < 6; i++)
	{
		scanf("%s", word[i]);
		int len = strlen(word[i]);
		if (word[i][len - 1] == '.')
			word[i][len - 1] = '\0';
		int num = 0;
		if (strcmp(word[i], "one") == 0 || (strcmp(word[i], "a") == 0 || strcmp(word[i], "another") == 0 || strcmp(word[i], "first") == 0))
		{
			num = 1;
			count++;
		}
		else if (strcmp(word[i], "two") == 0 || strcmp(word[i], "second") == 0)
		{
			num = 2;
			count++;
		}
		else if (strcmp(word[i], "three") == 0 || strcmp(word[i], "third") == 0)
		{
			num = 3;
			count++;
		}
		else if (strcmp(word[i], "four") == 0)
		{
			num = 4;
			count++;
		}
		else if (strcmp(word[i], "five") == 0)
		{
			num = 5;
			count++;
		}
		else if (strcmp(word[i], "six") == 0)
		{
			num = 6;
			count++;
		}
		else if (strcmp(word[i], "seven") == 0)
		{
			num = 7;
			count++;
		}
		else if (strcmp(word[i], "eight") == 0)
		{
			num = 8;
			count++;
		}
		else if (strcmp(word[i], "nine") == 0)
		{
			num = 9;
			count++;
		}
		else if (strcmp(word[i], "ten") == 0)
		{
			num = 10;
			count++;
		}
		else if (strcmp(word[i], "eleven") == 0)
		{
			num = 11;
			count++;
		}
		else if (strcmp(word[i], "twelve") == 0)
		{
			num = 12;
			count++;
		}
		else if (strcmp(word[i], "thirteen") == 0)
		{
			num = 13;
			count++;
		}
		else if (strcmp(word[i], "fourteen") == 0)
		{
			num = 14;
			count++;
		}
		else if (strcmp(word[i], "fifteen") == 0)
		{
			num = 15;
			count++;
		}
		else if (strcmp(word[i], "sixteen") == 0)
		{
			num = 16;
			count++;
		}
		else if (strcmp(word[i], "seventeen") == 0)
		{
			num = 17;
			count++;
		}
		else if (strcmp(word[i], "eighteen") == 0)
		{
			num = 18;
			count++;
		}
		else if (strcmp(word[i], "nineteen") == 0)
		{
			num = 19;
			count++;
		}
		else if (strcmp(word[i], "twenty") == 0)
		{
			num = 20;
			count++;
		}
		if (num != 0)
		{
			int ret = num * num % 100;
			number[count - 1] = ret;
		}
	}
	if (count == 0)
	{
		printf("0\n");
		return 0;
	}
	qsort(number, count, sizeof(int), compare);
	char result[100] = { 0 };
	char tmp[3] = { 0 };
	for (int i = 0; i < count; i++)
	{
		sprintf(tmp, "%02d", number[i]);
		strcat(result, tmp);
	}
	remove_leading_zero(result);
	printf("%s\n", result);
	return 0;
}

//
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int compare(const void* a, const void* b)
//{
//	return *(int*)a - *(int*)b;
//}
//void removeleadingzero(char* str)
//{
//	int len = strlen(str);
//	int i = 0;
//	while (i < len && str[i] == '0')
//	{
//		i++;
//	}
//	if (i > 0)
//	{
//		int j = 0;
//		while (i < len)
//		{
//			str[j++] = str[i++];
//		}
//		str[j] = '\0';
//	}
//}
//int main()
//{
//	char words[6][20];
//	int numbers[6];
//	int count = 0;
//	for (int i = 0; i < 6; i++)
//	{
//		scanf("%s", words[i]);
//		int len = strlen(words[i]);
//		if (words[i][len - 1] == '.')
//		{
//			words[i][len - 1] = '\0';
//		}
//		char* word = words[i];
//		int num = -1;//标记数字
//		if (strcmp(word, "one") == 0 || strcmp(word, "a") == 0 || strcmp(word, "another") == 0 || strcmp(word, "first") == 0)
//		{
//			num = 1;
//		}
//		else if (strcmp(word, "two") == 0 || strcmp(word, "both") == 0 || strcmp(word, "second") == 0)
//		{
//			num = 2;
//		}
//		else if (strcmp(word, "three") == 0 || strcmp(word, "third") == 0)
//		{
//			num = 3;
//		}
//		else if (strcmp(word, "four") == 0)
//		{
//			num = 4;
//		}
//		else if (strcmp(word, "five") == 0)
//		{
//			num = 5;
//		}
//		else if (strcmp(word, "six") == 0)
//		{
//			num = 6;
//		}
//		else if (strcmp(word, "seven") == 0)
//		{
//			num = 7;
//		}
//		else if (strcmp(word, "eight") == 0)
//		{
//			num = 8;
//		}
//		else if (strcmp(word, "nine") == 0)
//		{
//			num = 9;
//		}
//		else if (strcmp(word, "ten") == 0)
//		{
//			num = 10;
//		}
//		else if (strcmp(word, "eleven") == 0)
//		{
//			num = 11;
//		}
//		else if (strcmp(word, "twelve") == 0)
//		{
//			num = 12;
//		}
//		else if (strcmp(word, "thirteen") == 0)
//		{
//			num = 13;
//		}
//		else if (strcmp(word, "fourteen") == 0)
//		{
//			num = 14;
//		}
//		else if (strcmp(word, "fifteen") == 0)
//		{
//			num = 15;
//		}
//		else if (strcmp(word, "sixteen") == 0)
//		{
//			num = 16;
//		}
//		else if (strcmp(word, "seventeen") == 0)
//		{
//			num = 17;
//		}
//		else if (strcmp(word, "eighteen") == 0)
//		{
//			num = 18;
//		}
//		else if (strcmp(word, "nineteen") == 0)
//		{
//			num = 19;
//		}
//		else if (strcmp(word, "twenty") == 0)
//		{
//			num = 20;
//		}
//		if (num != -1)
//		{
//			int result = (num * num) % 100;
//			numbers[count] = result;
//			count++;
//		}
//	}
//	if (count == 0)//一个数字没找到
//	{
//		printf("0\n");
//		return 0;
//	}
//	qsort(numbers, count, sizeof(int), compare);//快速将numbers从大到小排序
//	char result[100] = { 0 };
//	char tmp[3];
//	for (int i = 0; i < count; i++)
//	{
//		sprintf(tmp, "%02d", numbers[i]);
//		strcat(result, tmp);
//	}
//	removeleadingzero(result);
//	printf("%s\n", result);
//	return 0;
//}