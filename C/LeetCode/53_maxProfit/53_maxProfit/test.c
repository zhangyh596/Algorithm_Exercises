#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//暴力超时
//int maxProfit(int* prices, int pricesSize) {
//	int max = 0;
//	for (int i = 0; i < pricesSize; i++)
//	{
//		for (int j = i + 1; j < pricesSize; j++)
//		{
//			if (prices[j] - prices[i] > max)
//			{
//				max = prices[j] - prices[i];
//			}
//		}
//	}
//	return max;
//}

int maxProfit(int* prices, int pricesSize) {
	//开辟一个数组，记录前i天的买入到底最低价格
	int min[100005] = { 0 };

	min[0] = prices[0];
	for (int i = 1; i < pricesSize; i++)
	{
		if (prices[i] < min[i - 1])
		{
			min[i] = prices[i];
		}
		else
		{
			min[i] = min[i - 1];
		}
	}

	int max = 0;
	for (int i = 0; i < pricesSize; i++)
	{
		if (prices[i] - min[i] > max)
		{
			max = prices[i] - min[i];
		}
	}
	return max;
}