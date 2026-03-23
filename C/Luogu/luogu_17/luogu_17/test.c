#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{
	char words[4][101];
	for (int i = 0; i < 4; i++)
	{
		fgets(words[i], 101, stdin);
	}
	int count[26] = { 0 };
	int max_count = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; words[i][j]; j++)
		{
			if (words[i][j] >= 'A' && words[i][j] <= 'Z')
			{
				count[words[i][j] - 'A']++;
				if (count[words[i][j] - 'A'] > max_count)
				{
					max_count = count[words[i][j] - 'A'];
				}
			}
		}
	}
	for (int i = max_count; i > 0; i--)
	{
		for (int j = 0; j < 26; j++)
		{
			if (count[j] >= i)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
			if (j < 25)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	for (int i = 0; i < 26; i++)
	{
		printf("%c", 'A' + i);
		if (i < 25)
			printf(" ");
	}
	return 0;
}


//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//
//int main()
//{
//	char lines[4][101];
//	int count[26] = { 0 };//存储26个字母的出现次数
//	int max_count = 0;//标记最大次数
//	for (int i = 0; i < 4; i++)
//	{
//		fgets(lines[i], 101, stdin);
//	}
//	//统计每个字母出现次数
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; lines[i][j] != '\0'; j++)
//		{
//			if (isupper(lines[i][j]))
//			{
//				int index = lines[i][j] - 'A';
//				count[index]++;
//
//				if (count[index] > max_count)
//				{
//					max_count = count[index];
//				}
//			}
//		}
//	}
//	//绘制柱状图
//	for (int i = max_count; i > 0; i--)
//	{
//		for (int letter = 0; letter < 26; letter++)
//		{
//			if (count[letter] >= i)
//				printf("*");
//			else
//				printf(" ");
//			if (letter < 25)
//				printf(" ");
//		}
//		printf("\n");
//	}
//	//输出字母标签
//	for (int letter = 0; letter < 26; letter++)
//	{
//		printf("%c", 'A' + letter);
//		if (letter < 25)
//			printf(" ");
//	}
//	return 0;
//}