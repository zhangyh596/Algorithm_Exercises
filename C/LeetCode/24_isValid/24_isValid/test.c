#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
	char stack[10005];
	int top = -1;
	int len = strlen(s);

	for (int i = 0; i < len; i++)
	{
		char c = s[i];
		if (c == '(' || c == '[' || c == '{')
		{
			top++;
			stack[top] = c;
		}
		else if (c == ')')
		{
			if (top == -1)
			{
				return false;
			}

			if (stack[top] == '(')
			{
				top--;
			}
			else
			{
				return false;
			}
		}
		else if (c == ']')
		{
			if (top == -1)
			{
				return false;
			}

			if (stack[top] == '[')
			{
				top--;
			}
			else
			{
				return false;
			}
		}
		else if (c == '}')
		{
			if (top == -1)
			{
				return false;
			}

			if (stack[top] == '{')
			{
				top--;
			}
			else
			{
				return false;
			}
		}
	}

	if (top != -1)
		return false;
	else
		return true;
}