#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "CQueue.h"

int main() {
	int N, temp, predec, succ;
	List* list;
	Queue q; QueueInit(&q);

	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("File open error!\n");
		exit(1);
	}

	fscanf(fp, "%d", &N);
	list = (List*)malloc(sizeof(List) * N);
	for (int i = 0;i < N;i++) {
		ListInit(&list[i]);
		list[i].head->data = 0; // count(the number of immediate predecessors)
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			fscanf(fp, "%d", &temp);
			
			if (temp == 1) {
				LInsert(&list[i], j);
				list[j].head->data += 1; // i is predecessor of j
			}
		}
	}

	// topology sort
	for (int i = 0;i < N;i++) {
		if (list[i].head->data == 0) {
			Enqueue(&q, i);
		}
	}
	
	for (int i = 0;i < N;i++) {
		predec = Dequeue(&q);
		printf("%d ", predec);

		if (LFirst(&list[predec], &succ)) {
			list[succ].head->data -= 1;

			if (list[succ].head->data == 0)
				Enqueue(&q, succ);

			while (LNext(&list[predec], &succ)) {
				list[succ].head->data -= 1;

				if (list[succ].head->data == 0)
					Enqueue(&q, succ);
			}
		}
	}

	return 0;
}