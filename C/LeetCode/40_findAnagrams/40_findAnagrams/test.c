#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int* findAnagrams(char* s, char* p, int* returnSize) {
//	int* ans = (int*)malloc(sizeof(int) * 30000);
//	int index = 0;
//
//	int count1[26] = { 0 };//记录26个字母每次出现的次数
//	for (int i = 0; p[i] != '\0'; i++)
//	{
//		count1[p[i] - 'a']++;
//	}
//
//	int count2[26] = { 0 };//记录s中每个字母出现的次数
//	int left = 0;
//	for (int right = 0; s[right] != '\0'; right++)
//	{
//		char c = s[right];
//		count2[c - 'a']++;
//
//		while (count2[c - 'a'] > count1[c - 'a'])
//		{
//			count2[s[left] - 'a']--;
//			left++;
//		}
//
//		for (int i = 0; i < 26; i++)
//		{
//			if (count2[i] != count1[i])
//			{
//				break;
//			}
//
//			if (i == 25)
//			{
//				ans[index] = left;
//				index++;
//			}
//		}
//	}
//
//	*returnSize = index;
//	return ans;
//}


//优化一下做法
//如果所有的x满足count2[x] <= count1[x] && 对∑count2[x] == ∑count1[x]
//那么这段长度的字符串就满足要求，省去了循环中26次的比较
int* findAnagrams(char* s, char* p, int* returnSize) {
	int* ans = (int*)malloc(sizeof(int) * 30000);
	int index = 0;

	int count1[26] = { 0 };//记录26个字母每次出现的次数
	for (int i = 0; p[i] != '\0'; i++)
	{
		count1[p[i] - 'a']++;
	}
	int len = strlen(p);

	int count2[26] = { 0 };//记录s中每个字母出现的次数
	int left = 0;
	for (int right = 0; s[right] != '\0'; right++)
	{
		char c = s[right];
		count2[c - 'a']++;

		while (count2[c - 'a'] > count1[c - 'a'])
		{
			count2[s[left] - 'a']--;
			left++;
		}

		if (right - left + 1 == len)
		{
			ans[index] = left;
			index++;
		}
	}

	*returnSize = index;
	return ans;
}