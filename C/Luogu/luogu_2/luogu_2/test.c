#define _CRT_SECURE_NO_WARNINGS 1

//Œ Ã‚¥˙¬Î

//#include <stdio.h>
//
//int main()
//{
//	int arr[9] = { 0 };
//	char ch;
//	for (int i = 0; i < 9; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	scanf("%c", &ch);
//	int sum = 0;
//	int j = 1;
//	for (int i = 0; i < 9; i++)
//	{
//		sum += arr[i] * j;
//		j++;
//	}
//	int ret = sum % 11;
//	if (ret == 10 && ch == 'X')
//	{
//		printf("Right\n");
//	}
//	else if (ret == ch - '0')
//	{
//		printf("Right\n");
//	}
//	else
//	{
//		printf("%d-%d%d%d-%d%d%d%d%d-%d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], ret);
//	}
//	return 0;
//}



#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{
    char ch[20];
    scanf("%s", ch);
    int sum = 0;
    int j = 1;
    int i = 0;
    while (ch[i] != '\0' && j <= 9)
    {
        if (ch[i] != '-')
        {
            sum = sum + (ch[i] - '0') * j;
            j++;
        }
        i++;
    }
    int r = sum % 11;
    char CorrectCode;
    if (r == 10)
    {
        CorrectCode = 'X';
    }
    else
    {
        CorrectCode = r + '0';
    }
    int CheckCode = strlen(ch) - 1;
    if (ch[CheckCode] == CorrectCode)
    {
        printf("Right\n");
    }
    else
    {
        ch[CheckCode] = CorrectCode;
        printf("%s\n", ch);
    }
    return 0;
}