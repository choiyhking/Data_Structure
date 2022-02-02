#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

int WhoIsPreced(int d1, int d2);
void fileRead(FILE* fp, List* plist);
void concat(List* plist1, List* plist2);
Node* invert(List* plist);
void print(List plist);

int main() {
	FILE* fp1, * fp2;
	List list1, list2;

	LInit(&list1); LInit(&list2);
	SetSortRule(&list1, WhoIsPreced); SetSortRule(&list2, WhoIsPreced);

	fp1 = fopen("input1.txt", "r");
	fp2 = fopen("input2.txt", "r");
	if (fp1 == NULL || fp2 == NULL) {
		printf("FILE OPEN ERROR!\n");
		exit(1);
	}

	fileRead(fp1, &list1);
	printf("First:\n");
	print(list1);

	fileRead(fp2, &list2);
	printf("Second:\n");
	print(list2);

	printf("Concatenate:\n");
	concat(&list1, &list2);
	print(list1);

	printf("Invert:\n");
	list1.head->next = invert(&list1);
	print(list1);

	return 0;
}

int WhoIsPreced(int d1, int d2) {
	if (d1 < d2) {
		return 0;
	}
	else {
		return 1;
	}
}

void fileRead(FILE* fp, List* plist) {
	int data;
	
	while (!feof(fp)) {
		fscanf(fp, "%d", &data);
		LInsert(plist, data);
	}
}

void concat(List* plist1, List* plist2) { // concatenate plist2 to plist1
	Node* temp;

	for (temp = plist1->head->next;temp->next != NULL;temp = temp->next) {
	}

	temp->next = plist2->head->next;
}

Node* invert(List* plist) { 
	Node* cur = plist->head->next;
	Node* middle = NULL;
	Node* trail;

	while (cur) {
		trail = middle;
		middle = cur;
		cur = cur->next;
		middle->next = trail;
	}

	return middle;
}

void print(List plist) {
	int temp;

	if (LFirst(&plist, &temp)) {
		printf("(%p, %d, %p) ", plist.cur, temp, plist.cur->next);

		while (LNext(&plist, &temp)) {
			printf("(%p, %d, %p) ", plist.cur, temp, plist.cur->next);
		}
	}
	printf("\n\n");
}