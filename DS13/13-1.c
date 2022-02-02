#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "DLinkedlist.h"
#include "ListbaseStack.h"

void operation(List* plist, Stack* pstack, int* flag);

int main() {
	int n, m, x, y;
	int* flag;
	List* list;
	Stack stack; StackInit(&stack);

	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("FILE OPEN ERROR!\n");
		exit(1);
	}

	fscanf(fp, "%d %d", &n, &m);
	
	flag = (int*)calloc(n, sizeof(int)); // init dynamic array with 0

	list = (List*)malloc(sizeof(List) * n);
	for (int i = 0;i < n;i++) {
		LInit(&list[i]);
	}
	
	while (!feof(fp)) {
		fscanf(fp, "%d %d", &x, &y);
		LInsert(&list[x], y);
		LInsert(&list[y], x);
	}

	for (int i = 0;i < n;i++) {
		if (!flag[i]) { // not printed
			printf("New Class: ");
			printf("%d ", i);
			flag[i] = TRUE;

			operation(&list[i], &stack, flag);

			while(!SIsEmpty(&stack)) {
				int data = SPop(&stack);

				operation(&list[data], &stack, flag);
			}

			printf("\n");
		}

		
	}

	return 0;
}

void operation(List* plist, Stack* pstack, int* flag) {
	int temp;

	if (LFirst(plist, &temp)) {
		if (!flag[temp]) {
			printf("%d ", temp);
			flag[temp] = TRUE;

			SPush(pstack, temp);
		}

		while (LNext(plist, &temp)) {
			if (!flag[temp]) {
				printf("%d ", temp);
				flag[temp] = TRUE;

				SPush(pstack, temp);
			}
		}
	}
}