#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct student
{
	char name[9];
	int chinese;
	int math;
	int english;
	int total;
};

int main()
{
	int N = 0;
	scanf("%d", &N);
	struct student s[1001];
	for (int i = 0; i < N; i++)
	{
		scanf("%s %d %d %d", s[i].name, &s[i].chinese, &s[i].math, &s[i].english);
		s[i].total = s[i].chinese + s[i].math + s[i].english;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (abs(s[i].chinese - s[j].chinese) <= 5 && abs(s[i].math - s[j].math) <= 5 && abs(s[i].english - s[j].english) <= 5 && abs(s[i].total - s[j].total) <= 10)
				printf("%s %s]n", s[i].name, s[j].name);
		}
	}
	return 0;
}