#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//用来存储原字符串和排序过后的字符串
typedef struct
{
	char* original;
	char* key;
}Bag;

Bag s[10005];

int cmp(const void* p1, const void* p2)
{
	return *(char*)p1 - *(char*)p2;
}

int cmpByKey(const void* p1, const void* p2)
{
	Bag* bag1 = (Bag*)p1;
	Bag* bag2 = (Bag*)p2;
	return strcmp(bag1->key, bag2->key);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
	for (int i = 0; i < strsSize; i++)
	{
		s[i].original = (char*)malloc(strlen(strs[i]) + 1);
		s[i].key = (char*)malloc(strlen(strs[i]) + 1);

		strcpy(s[i].original, strs[i]);
		qsort(strs[i], strlen(strs[i]), sizeof(char), cmp);
		strcpy(s[i].key, strs[i]);
	}

	qsort(s, strsSize, sizeof(Bag), cmpByKey);

	int count = 1;
	if (strsSize == 0)
		count = 0;

	for (int i = 1; i < strsSize; i++)
	{
		if (strcmp(s[i].key, s[i - 1].key) == 0)
		{

		}
		else
		{
			count++;
		}
	}

	//开辟数组
	char*** ans = (char***)malloc(sizeof(char**) * count);
	*returnSize = count;
	*returnColumnSizes = (int*)malloc(sizeof(int) * count);

	int index = 0;//记录当前在第几个抽屉
	int i = 0;
	while (i < strsSize)
	{
		int start = i;//记录起点

		while (i < strsSize && strcmp(s[i].key, s[start].key) == 0)
		{
			i++;
		}

		int size = i - start;//大小
		(*returnColumnSizes)[index] = size;

		ans[index] = (char**)malloc(sizeof(char*) * size);
		for (int j = 0; j < size; j++)
		{
			ans[index][j] = (char*)malloc(strlen(s[start + j].original) + 1);
			strcpy(ans[index][j], s[start + j].original);
		}

		index++;//准备进入下一个抽屉
	}

	return ans;
}