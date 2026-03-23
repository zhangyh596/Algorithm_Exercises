#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* phead = NULL;
	struct ListNode* ptail = NULL;

	int carry = 0;
	while (l1 || l2 || carry)
	{
		struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
		newnode->next = NULL;

		int n1 = l1 ? l1->val : 0;
		int n2 = l2 ? l2->val : 0;
		int sum = n1 + n2 + carry;
		carry = sum / 10;
		newnode->val = sum % 10;

		if (phead == NULL)
		{
			phead = ptail = newnode;
		}
		else
		{
			ptail->next = newnode;
			ptail = newnode;
		}

		if (l1)
		{
			l1 = l1->next;
		}
		if (l2)
		{
			l2 = l2->next;
		}
	}
	return phead;
}