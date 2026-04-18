#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* deleteNode(struct ListNode* head, int val) {
	struct ListNode dummy;
	dummy.next = head;

	struct ListNode* prev = &dummy;
	struct ListNode* pcur = dummy.next;
	while (pcur != NULL && pcur->val != val)
	{
		prev = pcur;
		pcur = pcur->next;
	}

	prev->next = pcur->next;
	free(pcur);

	return dummy.next;
}