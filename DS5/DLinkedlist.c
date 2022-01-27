#include <stdio.h>
#include <stdlib.h>
#include "DLinkedlist.h"

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->numOfData = 0;
}

void FInsert(List* plist, Data coef, Data expon) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->coef = coef;
	newNode->expon = expon;
	
	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

void SInsert(List* plist, Data coef, Data expon) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* pred = plist->head;

	newNode->coef = coef;
	newNode->expon = expon;

	while (pred->next != NULL && plist->comp(expon, pred->next->expon) == 0) {
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}

void LInsert(List* plist, Data coef, Data expon) {
	if (plist->comp == NULL)
		FInsert(plist, coef, expon);
	else
		SInsert(plist, coef, expon);
}

int LFirst(List* plist, Data* coef, Data* expon) {
	if (plist->head->next == NULL)
		return FALSE;
	
	plist->before = plist->head;
	plist->cur = plist->head->next;

	*coef = plist->cur->coef;
	*expon = plist->cur->expon;

	return TRUE;
}
int LNext(List* plist, Data* coef, Data* expon) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	
	*coef = plist->cur->coef;
	*expon = plist->cur->expon;
	
	return TRUE;
}

//Data LRemove(List* plist) {}

int LCount(List* plist) {
	return plist->numOfData;
}

void SetSortRule(List* plist, int (*comp)(Data d1, Data d2)) {
	plist->comp = comp;
}