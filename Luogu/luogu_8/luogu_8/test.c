#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int arr[101] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int found = 0;
		for (int j = 0; j < n && found == 0; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (arr[i] == arr[j] + arr[k])
				{
					count++;
					found = 1;
				}
			}
		}
	}
	printf("%d", count);
	return 0;
}




//#include <stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int nums[100] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &nums[i]);
//	}
//	int count = 0;
//	int arr[20001] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			int sum = nums[i] + nums[j];
//			arr[sum] = 1;
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[nums[i]] == 1)
//			count++;
//	}
//	printf("%d", count);
//	return 0;
//}