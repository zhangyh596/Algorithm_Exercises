#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

typedef struct {
	struct ListNode* head;
	struct ListNode* tail;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
	MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
	if (obj == NULL)
	{
		return NULL;
	}

	obj->head = NULL;
	obj->tail = NULL;
	return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
	if (index < 0 || obj->head == NULL)
	{
		return - 1;
	}

	struct ListNode* pcur = obj->head;
	for (int i = 0; i < index; i++)
	{
		pcur = pcur->next;
		if (pcur == NULL)
		{
			return -1;
		}
	}
	return pcur->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (newnode == NULL)
	{
		return;
	}
	newnode->val = val;
	newnode->next = NULL;

	newnode->next = obj->head;
	obj->head = newnode;
	if (obj->tail == NULL)
	{
		obj->tail = newnode;
	}
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (newnode == NULL)
	{
		return;
	}
	newnode->val = val;
	newnode->next = NULL;

	if (obj->head == NULL)
	{
		obj->head = obj->tail = newnode;
	}
	else
	{
		obj->tail->next = newnode;
		obj->tail = newnode;
	}
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
	if (index == 0)
	{
		myLinkedListAddAtHead(obj, val);
		return;
	}

	struct ListNode* prev = NULL;// 存放下标为index节点的前一个的节点
	struct ListNode* pcur = obj->head;
	for (int i = 0; i < index; i++)
	{
		prev = pcur;
		if (prev == NULL)
		{
			return;
		}
		pcur = pcur->next;
	}

	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (newnode == NULL)
	{
		return;
	}
	newnode->val = val;
	newnode->next = NULL;

	prev->next = newnode;
	newnode->next = pcur;

	if (pcur == NULL)
	{
		obj->tail = newnode;
	}
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
	struct ListNode* prev = NULL;
	struct ListNode* pcur = obj->head;
	for (int i = 0; i < index; i++)
	{
		if (pcur == NULL)
		{
			return;
		}
		prev = pcur;
		pcur = pcur->next;
	}
	if (pcur == NULL)
	{
		return;
	}

	if (pcur == obj->tail)
	{
		obj->tail = prev;
	}

	if (prev == NULL)
	{
		obj->head = pcur->next;
	}
	else
	{
		prev->next = pcur->next;
	}
	free(pcur);
}

void myLinkedListFree(MyLinkedList* obj) {
	if (obj == NULL)
	{
		return;
	}

	struct ListNode* pcur = obj->head;
	while (pcur != NULL)
	{
		struct ListNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/