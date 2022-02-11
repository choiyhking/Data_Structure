#include <stdio.h>
#include <stdlib.h>
#include "LStack.h"

void StackInit(Stack* pstack) {
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack) {
	if (pstack->head == NULL) {
		return TRUE;
	}
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data) {
	SNode* newNode = (SNode*)malloc(sizeof(SNode));
	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

Data SPop(Stack* pstack) {
	if (SIsEmpty(pstack)) {
		printf("Stack is empty!\n");
		exit(1);
	}

	SNode* rnode = pstack->head;
	Data rdata = rnode->data;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

Data SPeek(Stack* pstack) {
	if (SIsEmpty(pstack)) {
		printf("Stack is empty!\n");
		exit(1);
	}

	return pstack->head->data;
}