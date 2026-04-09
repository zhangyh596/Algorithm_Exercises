#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
	struct ListNode dummy;
	dummy.val = -1;
	dummy.next = head;

	struct ListNode* prev = &dummy;
	for (int i = 0; i < left - 1; i++)
	{
		prev = prev->next;// 让ptail走到left节点的前一个节点
	}

	struct ListNode* curr_prev = NULL;
	struct ListNode* pcur = prev->next;
	struct ListNode* node1 = pcur;
	for (int i = 0; i < right - left + 1; i++)
	{
		struct ListNode* next = pcur->next;
		pcur->next = curr_prev;

		curr_prev = pcur;
		pcur = next;
	}

	prev->next = curr_prev;
	node1->next = pcur;

	return dummy.next;
}

