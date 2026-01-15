#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int days[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };

int isleapyear(int n)
{
	if ((n % 100 != 0 && n % 4 == 0) || n % 400 == 0)
		return 1;
	return 0;
}

int main()
{
	int date1, date2;
	scanf("%d %d", &date1, &date2);
	int count = 0;
	for (int i = date1 / 10000; i <= date2 / 10000; i++)
	{
		int month = i % 10 * 10 + (i / 10) % 10;
		int day = (i / 100) % 10 * 10 + (i / 1000) % 10;
		int current_date = 0;
		if (isleapyear(i))
		{
			if (month >= 1 && month <= 12 && day <= 29)
			{
				current_date = i * 10000 + month * 100 + day;
				if (current_date >= date1 && current_date <= date2)
				{
					count++;
					continue;
				}
			}
		}

		if (month >= 1 && month <= 12 && day <= days[month])
		{
			current_date = i * 10000 + month * 100 + day;
			if (current_date >= date1 && current_date <= date2)
			{
				count++;
			}
		}
	}
	printf("%d", count);
	return 0;
}