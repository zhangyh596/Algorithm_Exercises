#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

typedef struct Toy
{
    int dir;
    char name[20];
}Toy;

Toy toys[100005];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &toys[i].dir, toys[i].name);
    }

    int pos = 0;
    for (int i = 0; i < m; i++)
    {
        int a, s;
        scanf("%d %d", &a, &s);

        if ((a + toys[pos].dir) % 2 == 0)
        {
            pos = (pos - s) % n;
            if (pos < 0)
            {
                pos = pos + n;
            }
        }
        else
        {
            pos = (pos + s) % n;
        }
    }

    printf("%s", toys[pos].name);

    return 0;
}