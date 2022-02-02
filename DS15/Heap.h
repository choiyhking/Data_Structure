#pragma once

#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100

typedef int Data;
typedef int PriorityComp(Data d1, Data d2);

typedef struct _heap {
	PriorityComp* comp;
	int numOfData;
	Data heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap* ph, PriorityComp* pc);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, Data data);
Data HDelete(Heap* ph);