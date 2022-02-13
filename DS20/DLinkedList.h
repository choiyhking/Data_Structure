#pragma once

#define TRUE 1 
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
}Node;

typedef struct _linkedlist {
	Node* head;
	Node* cur;
	Node* before;
	int numOfData;
}LinkedList;

typedef LinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data);

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);

Data LRemove(List* plist);

int LCount(List* plist);