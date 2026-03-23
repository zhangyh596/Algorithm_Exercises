#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* detectCycle(struct ListNode* head) {
	struct ListNode* slow = head;
	struct ListNode* fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			//此时慢指针和头节点距离环开头的节点相同
			struct ListNode* p1 = head;
			struct ListNode* p2 = slow;

			while (p1 != p2)
			{
				p1 = p1->next;
				p2 = p2->next;
			}
			return p1;
		}
	}
	return NULL;
}