#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct student
{
	int id;
	int study_score;
	int quality_score;
	int total;
};
int main()
{
	int N = 0;
	scanf("%d", &N);
	struct student s[1001];
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &s[i].id, &s[i].study_score, &s[i].quality_score);
		if ((s[i].study_score + s[i].quality_score) > 140 && (s[i].study_score * 7 + s[i].quality_score * 3) >= 800)
			printf("Excellent\n");
		else
			printf("Not excellent\n");
	}
	return 0;
}