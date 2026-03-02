#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
	int note[200] = { 0 };
	int left = 0;
	int max_len = 0;
	int len = strlen(s);
	for (int right = 0; right < len; right++)
	{
		char c = s[right];

		while (note[c] == 1)
		{
			note[s[left]] = 0;
			left++;
		}

		note[c] = 1;

		if (right - left + 1 > max_len)
		{
			max_len = right - left + 1;
		}
	}
	return max_len;
}