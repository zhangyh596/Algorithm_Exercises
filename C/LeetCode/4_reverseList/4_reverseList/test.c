#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* prev = NULL;
	struct ListNode* pcur = head;
	while (pcur)
	{
		struct ListNode* next = pcur->next;
		pcur->next = prev;
		prev = pcur;
		pcur = next;
	}
	return prev;
}