#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void LInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->numOfData = 0;
}

void FInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = plist->head->next;

	plist->head->next = newNode;

	(plist->numOfData)++;
}

void SInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* pred = plist->head;

	newNode->data = data;

	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}

void LInsert(List* plist, Data data) {
	if (plist->comp == NULL) {
		FInsert(plist, data);
	}
	else {
		SInsert(plist, data);
	}
}

int LFirst(List* plist, Data* pdata) {
	if (plist->head->next == NULL) {
		return FALSE;
	}

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List* plist, Data* pdata) {
	if (plist->cur->next == NULL) {
		return FALSE;
	}

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;

	return TRUE;
}

Data LRemove(List* plist) {
	Node* rpos = plist->cur;
	Data rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;

	return rdata;
}

int LCount(List* plist) {
	return plist->numOfData;
}

void SetSortRule(List* plist, int(*comp)(Data d1, Data d2)) {
	plist->comp = comp;
}