#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

const char* arr[10][5] =
{
        {"XXX", "X.X", "X.X", "X.X", "XXX"}, // 0
        {"..X", "..X", "..X", "..X", "..X"}, // 1
        {"XXX", "..X", "XXX", "X..", "XXX"}, // 2
        {"XXX", "..X", "XXX", "..X", "XXX"}, // 3
        {"X.X", "X.X", "XXX", "..X", "..X"}, // 4
        {"XXX", "X..", "XXX", "..X", "XXX"}, // 5
        {"XXX", "X..", "XXX", "X.X", "XXX"}, // 6
        {"XXX", "..X", "..X", "..X", "..X"}, // 7
        {"XXX", "X.X", "XXX", "X.X", "XXX"}, // 8
        {"XXX", "X.X", "XXX", "..X", "XXX"}  // 9
};
int main()
{
    int n;
    scanf("%d", &n);
    char num[101];
    scanf("%s", num);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int digit = num[j] - '0';
            printf("%s", arr[digit][i]);
            if (j < n - 1)
            {
                printf(".");
            }
        }
        printf("\n");
    }
	return 0;
}




#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
    char digits[10][5][4] =
    {
        {"XXX", "X.X", "X.X", "X.X", "XXX"}, // 0
        {"..X", "..X", "..X", "..X", "..X"}, // 1
        {"XXX", "..X", "XXX", "X..", "XXX"}, // 2
        {"XXX", "..X", "XXX", "..X", "XXX"}, // 3
        {"X.X", "X.X", "XXX", "..X", "..X"}, // 4
        {"XXX", "X..", "XXX", "..X", "XXX"}, // 5
        {"XXX", "X..", "XXX", "X.X", "XXX"}, // 6
        {"XXX", "..X", "..X", "..X", "..X"}, // 7
        {"XXX", "X.X", "XXX", "X.X", "XXX"}, // 8
        {"XXX", "X.X", "XXX", "..X", "XXX"}  // 9
    };
    int n = 0;
    char nums[101];
    scanf("%d", &n);
    scanf("%s", nums);
    for (int row = 0; row < 5; row++)
    {
        for (int i = 0; i < n; i++)
        {
            int digit = nums[i] - '0';
            printf("%s", digits[digit][row]);
            if (i < n - 1)
            {
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}