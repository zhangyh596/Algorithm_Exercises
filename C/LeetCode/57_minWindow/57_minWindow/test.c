#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* minWindow(char* s, char* t) {
	int note[128] = { 0 };//记录t字符串中字母出现的次数
	int window[128] = { 0 };//记录s字符串中字母出现的次数

	int count = 0;//记录t字符串有多少个不同的字母
	int len_t = strlen(t);
	int len_s = strlen(s);
	for (int i = 0; i < len_t; i++)
	{
		char c = t[i];
		if (note[c] == 0)
		{
			count++;
		}
		note[c]++;
	}

	int min_len = len_s + 1;//记录最短长度(让其等于len_s + 1是为了检验min_len是否改变过，如果没有改变返回NULL)
	int start_pos = 0;//记录起始位置
	int left = 0, right = 0;
	while (right < len_s)
	{
		char c = s[right];
		window[c]++;

		if (window[c] == note[c])
		{
			count--;
			while (count == 0)//如果count==0，一直向后踢出s[left]
			{
				if (right - left + 1 < min_len)
				{
					min_len = right - left + 1;
					start_pos = left;
				}

				char d = s[left];
				window[d]--;
				if (window[d] < note[d])
				{
					count++;
				}
				left++;//left++必须在最后
			}
		}
		right++;//right++必须放在最后
	}

	if (min_len == len_s + 1)
	{
		char* ret = (char*)malloc(1);
		ret[0] = '\0';
		return ret;
	}
	else
	{
		char* ret = (char*)malloc(min_len + 1);
		strncpy(ret, s + start_pos, min_len);
		ret[min_len] = '\0';
		return ret;
	}
}