#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

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
	struct student best;
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%s %d %d %d", s[i].name, &s[i].chinese, &s[i].math, &s[i].english);
		s[i].total = s[i].chinese + s[i].math + s[i].english;
		if (s[i].total > max)
		{
			best = s[i];
			max = s[i].total;
		}
	}
	printf("%s %d %d %d", best.name, best.chinese, best.math, best.english);
	return 0;
}