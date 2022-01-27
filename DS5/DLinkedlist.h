#pragma once

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	int coef;
	int expon;
	struct _node* next;
}Node;

typedef struct _dlist {
	struct _node* head;
	struct _node* cur;
	struct _node* before;
	int numOfData;
	int (*comp)(Data d1, Data d2);
}DList;

typedef DList List;

void ListInit(List* plist);

void LInsert(List* plist, Data coef, Data expon);

int LFirst(List* plist, Data* coef, Data* expon);
int LNext(List* plist, Data* coef, Data* expon);

//Data LRemove(List* plist);

int LCount(List* plist);

void SetSortRule(List* plist, int (*comp)(Data d1, Data d2));