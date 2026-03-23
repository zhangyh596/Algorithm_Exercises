#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

//struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
//	struct ListNode* pcur = head;
//
//	int count = 0;
//	while (pcur)
//	{
//		count++;
//		pcur = pcur->next;
//	}
//
//	if (count == n)
//	{
//		return head->next;
//	}
//
//	struct ListNode* prev = head;
//	int N = count - n - 1;
//	while (N)
//	{
//		prev = prev->next;
//		N--;
//	}
//
//	prev->next = prev->next->next;
//	return head;
//}

//优化：快慢指针（一次遍历）
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
	dummy->val = 0;
	dummy->next = head;
	
	struct ListNode* fast = head;
	struct ListNode* slow = dummy;
	for (int i = 0; i < n; i++)
	{
		fast = fast->next;
	}
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	slow->next = slow->next->next;
	struct ListNode* ret = dummy->next;
	free(dummy);
	return ret;
}