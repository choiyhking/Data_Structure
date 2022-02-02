#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

int PrioirtComp(int d1, int d2);
void levelorderTraverse(Heap* ph);

int main() {
	int temp;
	Heap heap; HeapInit(&heap, &PrioirtComp);

	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("File Open Error!\n");
		exit(1);
	}

	while (!feof(fp)) {
		fscanf(fp, "%d", &temp);
		HInsert(&heap, temp);
	}

	levelorderTraverse(&heap);
	
	HDelete(&heap);
	levelorderTraverse(&heap);
	
	HDelete(&heap);
	levelorderTraverse(&heap);
	
	HInsert(&heap, 13);
	levelorderTraverse(&heap);

	return 0;
}

int PrioirtComp(int d1, int d2) {
	return d1 - d2;
}

void levelorderTraverse(Heap* ph) {
	printf("LevelOrder:\n");

	for (int i = 1;i <= ph->numOfData;i++) {
		printf("%d ", ph->heapArr[i]);
	}
	printf("\n");
}