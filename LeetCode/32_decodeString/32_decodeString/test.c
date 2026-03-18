#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* decodeString(char* s) {
	char* stack = (char*)malloc(100005 * sizeof(char));
	int top = -1;

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != ']')
		{
			top++;
			stack[top] = s[i];
		}
		else
		{
			int char_start = top;//让char_start指向]前面的字母
			while (char_start >= 0 && stack[char_start] != '[')
			{
				char_start--;
			}
			char_start++;//让char_start指向[后面的第一个有效字母

			int len = top - char_start + 1;//字符串长度
			char* tmp = (char*)malloc(len);//把要拷贝的字符串存进一个临时数组里面
			int index = 0;
			for (int m = char_start; m <= top; m++)
			{
				tmp[index] = stack[m];
				index++;
			}

			int num_end = char_start - 2;//数字的个位（即[前面的数字）
			int num_start = num_end;
			while (num_start >= 0 && stack[num_start] >= '0' && stack[num_start] <= '9')
			{
				num_start--;
			}
			num_start++;//指向数字的最高位

			//将字符形式的数字转换成真正的数字k
			int k = 0;
			for (int j = num_start; j <= num_end; j++)
			{
				k = k * 10 + stack[j] - '0';
			}

			top = num_start - 1;//准备把嵌套的解码后的字符串重新压入栈
			for (int count = 0; count < k; count++)
			{
				for (int j = 0; j < len; j++)
				{
					top++;
					stack[top] = tmp[j];
				}
			}
		}
	}
	top++;
	stack[top] = '\0';
	return stack;
}