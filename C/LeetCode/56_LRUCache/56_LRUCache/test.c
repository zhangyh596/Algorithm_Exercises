#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef struct DListNode {
	int key;
	int value;
	struct DListNode* prev;
	struct DListNode* next;
}DListNode;

typedef struct {
	int size;
	int capacity;
	DListNode* dummy;
	DListNode* hash[10001];
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
	LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));

	obj->capacity = capacity;
	obj->size = 0;

	for (int i = 0; i < 10001; i++)
	{
		obj->hash[i] = NULL;
	}

	obj->dummy = (DListNode*)malloc(sizeof(DListNode));
	obj->dummy->prev = obj->dummy;
	obj->dummy->next = obj->dummy;

	return obj;
}

void removeNode(DListNode* node) {
	DListNode* node1 = node->prev;
	DListNode* node2 = node->next;

	node1->next = node2;
	node2->prev = node1;
}

void addToHead(LRUCache* obj, DListNode* node)
{
	DListNode* dummy = obj->dummy;
	DListNode* old_first = dummy->next;

	node->prev = dummy;
	node->next = old_first;

	old_first->prev = node;
	dummy->next = node;
}

int lRUCacheGet(LRUCache* obj, int key) {
	// 去哈希表(数组)里通过下标直接抓取目标节点
	DListNode* node = obj->hash[key];

	if (node == NULL)
	{
		return -1;
	}

	removeNode(node);
	addToHead(obj, node);

	return node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
	DListNode* node = obj->hash[key];

	if (node != NULL)
	{
		// 老面孔，更新数据并置顶
		node->value = value;
		removeNode(node);
		addToHead(obj, node);
	}
	else
	{
		// 新面孔入场
		DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
		newnode->key = key;
		newnode->value = value;

		obj->hash[key] = newnode;
		addToHead(obj, newnode);
		obj->size++;

		if (obj->size > obj->capacity)
		{
			DListNode* tail = obj->dummy->prev;
			removeNode(tail);
			obj->hash[tail->key] = NULL;

			free(tail);
			obj->size--;
		}
	}
}

void lRUCacheFree(LRUCache* obj) {
	DListNode* pcur = obj->dummy->next;

	while (pcur != obj->dummy)
	{
		DListNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(obj->dummy);
	free(obj);
}