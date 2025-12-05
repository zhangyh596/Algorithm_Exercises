#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	int i;
//	scanf("%d", &i);
//	char op = 0;
//	int num1, num2;
//	int result;
//	char arr[100];
//	for (int j = 0; j < i; j++)
//	{
//		char first_char;
//		scanf(" %c", &first_char);
//		if (first_char >= 'a' && first_char <= 'c')
//		{
//			op = first_char;
//			scanf("%d %d", &num1, &num2);
//		}
//		else
//		{
//			ungetc(first_char, stdin);
//			scanf("%d %d", &num1, &num2);
//		}
//		switch (op)
//		{
//		case 'a':
//			result = num1 + num2;
//			sprintf(arr, "%d+%d=%d", num1, num2, result);
//			break;
//		case 'b':
//			result = num1 - num2;
//			sprintf(arr, "%d-%d=%d", num1, num2, result);
//			break;
//		case 'c':
//			result = num1 * num2;
//			sprintf(arr, "%d*%d=%d", num1, num2, result);
//			break;
//		}
//		printf("%s\n", arr);
//		printf("%zu\n", strlen(arr));
//	}
//	return 0;
//}


//
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int i;
//	scanf("%d", &i);
//	char op = 0;
//	int num1, num2;
//	int result;
//	char arr[100];
//	for (int k = 0; k < i; k++)
//	{
//		char tmp_op;
//		int tmp_num1, tmp_num2;
//		char first_char;
//		scanf(" %c", &first_char);
//		if (first_char >= 'a' && first_char <= 'c')
//		{
//			op = first_char;
//			scanf("%d %d", &num1, &num2);
//		}
//		else
//		{
//			ungetc(first_char, stdin);
//			scanf("%d %d", &num1, &num2);
//		}
//		switch (op)
//		{
//		case 'a':result = num1 + num2;
//			break;
//		case 'b':result = num1 - num2;
//			break;
//		case 'c':result = num1 * num2;
//			break;
//		}
//		switch (op)
//		{
//		case 'a':sprintf(arr, "%d+%d=%d", num1, num2, result);
//			break;
//		case 'b':sprintf(arr, "%d-%d=%d", num1, num2, result);
//			break;
//		case 'c':sprintf(arr, "%d*%d=%d", num1, num2, result);
//			break;
//		}
//		printf("%s\n", arr);
//		printf("%zu\n", strlen(arr));
//	}
//	return 0;
//}




#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int num1, num2;
    char op_char;
    char expr[100];
} question;

int main()
{
    int i;
    scanf("%d", &i);
    getchar();

    char arr[50][100];
    question questions[50];

    // 读取所有输入
    for (int j = 0; j < i; j++)
    {
        fgets(arr[j], sizeof(arr[j]), stdin);
        // 去除换行符
        arr[j][strcspn(arr[j], "\n")] = '\0';
    }

    char last_op = 0;

    for (int j = 0; j < i; j++)
    {
        int a = 0, b = 0;
        int result = 0;
        char op = 0;

        // 正确的解析方法
        // 先检查第一个字符是否是字母
        if (strlen(arr[j]) > 0 && arr[j][0] >= 'a' && arr[j][0] <= 'c')
        {
            // 有三个数据：运算符 + 两个数字
            sscanf(arr[j], "%c %d %d", &op, &a, &b);
            last_op = op;
        }
        else
        {
            // 只有两个数字，使用上一个运算符
            sscanf(arr[j], "%d %d", &a, &b);
            op = last_op;
        }

        // 根据运算符计算
        switch (op)
        {
        case 'a':
            questions[j].op_char = '+';
            questions[j].num1 = a;
            questions[j].num2 = b;
            result = a + b;
            break;
        case 'b':
            questions[j].op_char = '-';
            questions[j].num1 = a;
            questions[j].num2 = b;
            result = a - b;
            break;
        case 'c':
            questions[j].op_char = '*';
            questions[j].num1 = a;
            questions[j].num2 = b;
            result = a * b;
            break;
        }

        sprintf(questions[j].expr, "%d%c%d=%d", a, questions[j].op_char, b, result);
    }

    for (int j = 0; j < i; j++)
    {
        printf("%s\n%zu\n", questions[j].expr, strlen(questions[j].expr));
    }

    return 0;
}