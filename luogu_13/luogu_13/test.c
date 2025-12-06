#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{
	int q = 0;
	scanf("%d", &q);
	char str1[100];
	scanf("%s", str1);
	for (int i = 0; i < q; i++)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			char str2[100];
			scanf("%s", str2);
			strcat(str1, str2);
			printf("%s\n", str1);
		}
		else if (op == 2)
		{
			int a, b;
			char tmp[100];
			scanf("%d %d", &a, &b);
			strncpy(tmp, str1 + a, b);
			tmp[b] = '\0';
			strcpy(str1, tmp);
			printf("%s\n", str1);
		}
		else if (op == 3)
		{
			int a;
			scanf("%d", &a);
			char str2[100];
			scanf("%s", str2);
			char tmp[100];
			strncpy(tmp, str1, a);
			tmp[a] = '\0';
			strcat(tmp, str2);
			strcat(tmp, str1 + a);
			strcpy(str1, tmp);
			printf("%s\n", str1);
		}
		else if (op == 4)
		{
			char str2[100];
			scanf("%s", str2);
			char* p = strstr(str1, str2);
			if (p == NULL)
				printf("-1\n");
			else
				printf("%d\n", p - str1);
		}
	}
	return 0;
}



//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	int q;
//	scanf("%d", &q);
//	char arr[101];
//	scanf("%s", arr);
//	for (int i = 0; i < q; i++)
//	{
//		int op;
//		scanf("%d", &op);
//		if (op == 1)
//		{
//			char str[101];
//			scanf("%s", str);
//			strcat(arr, str);
//			printf("%s\n", arr);
//		}
//		else if (op == 2)
//		{
//			int a, b;
//			scanf("%d %d", &a, &b);
//			int len = b - a + 1;
//			char tmp[101];
//			strncpy(tmp, arr + a, b);
//			tmp[b] = '\0';
//			strcpy(arr, tmp);
//			printf("%s\n", arr);
//		}
//		else if (op == 3)
//		{
//			int a;
//			scanf("%d", &a);
//			char str[101];
//			scanf("%s", str);
//			char tmp[101];
//			strncpy(tmp, arr, a);
//			tmp[a] = '\0';
//			strcat(tmp, str);
//			strcat(tmp, arr + a);
//			strcpy(arr, tmp);
//			printf("%s\n", arr);
//		}
//		else if (op == 4)
//		{
//			char str[101];
//			scanf("%s", str);
//			char* p = strstr(arr, str);
//			if (p == NULL)
//				printf("-1\n");
//			else
//				printf("%d\n", p - arr);
//		}
//	}
//	return 0;
//}