#include <stdio.h>
#include <stdlib.h>
#include "LStack.h"

void StackInit(Stack* pstack) {
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack) {
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, SData data) {
	SNode* newNode = (SNode*)malloc(sizeof(SNode));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}
SData SPop(Stack* pstack) {
	SData rdata;
	SNode* rnode;

	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!\n");
		exit(1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

SData SPeek(Stack* pstack) {
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!\n");
		exit(1);
	}

	return pstack->head->data;
}