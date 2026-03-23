#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char word[11];
	fgets(word, 11, stdin);
	word[strcspn(word, "\n")] = '\0';
	char article[1000001];
	fgets(article, 1000001, stdin);
	article[strcspn(article, "\n")] = '\0';
	int word_len = strlen(word);
	int article_len = strlen(article);
	int count = 0;
	int firstpos = -1;
	int i = 0;
	while (i < article_len)
	{
		while (i < article_len && article[i] == ' ')
		{
			i++;
		}
		int start = i;
		while (i < article_len && article[i] != ' ')
		{
			i++;
		}
		int current_len = i - start;
		if (current_len == word_len)
		{
			int match = 1;
			for (int j = 0; j < word_len; j++)
			{
				if (tolower(article[start + j] )!=tolower( word[j]))
				{
					match = 0;
					break;
				}
			}
			if (match == 1)
			{
				count++;
				if (firstpos == -1)
				{
					firstpos = start;
				}
			}
		}

	}
	if (count > 0)
	{
		printf("%d %d", count, firstpos);
	}
	else
	{
		printf("-1");
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
//	char word[11];
//	char article[1000001];
//	fgets(word, 11, stdin);
//	fgets(article, 1000001, stdin);
//	word[strcspn(word, "\n")] = '\0';
//	article[strcspn(article, "\n")] = '\0';
//	int word_len = strlen(word);
//	int article_len = strlen(article);
//	for (int i = 0; i < word_len; i++)
//	{
//		word[i] = tolower(word[i]);//×ª»»³ÉÐ¡Ð´
//	}
//	int count = 0;
//	int first = -1;
//	int i = 0;
//	while (i < article_len)
//	{
//		while (i < article_len && article[i] == ' ')
//		{
//			i++;
//		}
//		int start = i;
//		while (i < article_len && article[i] != ' ')
//		{
//			i++;
//		}
//		int current_len = i - start;
//		if (current_len == word_len)
//		{
//			int match = 1;
//			for (int j = 0; j < word_len; j++)
//			{
//				if (tolower(article[start + j]) != word[j])
//				{
//					match = 0;
//					break;
//				}
//			}
//			if (match)
//			{
//				count++;
//				if (first == -1)
//				{
//					first = start;
//				}
//			}
//		}
//	}
//	if (count > 0)
//	{
//		printf("%d %d\n", count, first);
//	}
//	else
//	{
//		printf("-1");
//	}
//	return 0;
//}