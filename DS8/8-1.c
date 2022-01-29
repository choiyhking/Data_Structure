#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

int main() {
	FILE* fp;
	char op;
	int num, data;

	Stack stack;
	StackInit(&stack);

	fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("FILE OPEN ERROR!\n");
		exit(1);
	}

	while (!feof(fp)) {
		fscanf(fp, "%c ", &op);

		if (op == 'I') { // push
			fscanf(fp, "%d ", &num);
			SPush(&stack, num);
		}
		else { // pop
			data = SPop(&stack);
		}
	}

	while (!SIsEmpty(&stack)) {
		printf("%d ", SPop(&stack));
	}

	return 0;
}