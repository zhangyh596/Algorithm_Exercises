#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
	dummy->next = head;

	struct ListNode* prev = dummy;//记录上一块的尾节点
	struct ListNode* pcur = dummy->next;//记录下一块的头节点

	//遍历总数
	int count = 0;
	while (pcur)
	{
		count++;
		pcur = pcur->next;
	}

	pcur = dummy->next;
	for (int i = 0; i < count / k; i++)
	{
		struct ListNode* start = pcur;//记住最开始的头节点
		struct ListNode* groupPrev = NULL;
		int j = 0;
		while (j < k)
		{
			struct ListNode* next = pcur->next;
			pcur->next = groupPrev;
			groupPrev = pcur;
			pcur = next;
			j++;
		}
		start->next = pcur;
		prev->next = groupPrev;
		prev = start;
	}
	return dummy->next;
}