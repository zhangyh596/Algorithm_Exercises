#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* prev = NULL;
    struct ListNode* pcur = slow->next;// 指向后半段链表的头节点
    slow->next = NULL;// 让前半段链表的尾节点指向NULL
    while (pcur)
    {
        struct ListNode* next = pcur->next;
        pcur->next = prev;
        prev = pcur;
        pcur = next;
    }

    // 合并两个链表
    struct ListNode* list1 = head;
    struct ListNode* list2 = prev;
    while (list1 && list2)
    {
        struct ListNode* next1 = list1->next;
        struct ListNode* next2 = list2->next;

        list1->next = list2;
        list2->next = next1;

        list1 = next1;
        list2 = next2;
    }
}