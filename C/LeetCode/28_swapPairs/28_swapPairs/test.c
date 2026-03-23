#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

//递归解法
//struct ListNode* swapPairs(struct ListNode* head) {
//	if (head == NULL || head->next == NULL)
//	{
//		return head;
//	}
//
//	struct ListNode* temp = head->next;
//	struct ListNode* nextNode = temp->next;
//
//	temp->next = head;
//	head->next = swapPairs(nextNode);
//	return temp;
//}

//创建哨兵节点
struct ListNode* swapPairs(struct ListNode* head) {
	struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
	dummy->next = head;

	struct ListNode* prev = dummy;
	while (prev->next && prev->next->next)
	{
		struct ListNode* node1 = prev->next;
		struct ListNode* node2 = prev->next->next;
		struct ListNode* temp = node2->next;

		prev->next = node2;
		node2->next = node1;
		node1->next = temp;
		prev = node1;
	}

	struct ListNode* ret = dummy->next;
	free(dummy);
	return ret;
}