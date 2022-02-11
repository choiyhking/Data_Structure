#pragma once

#include "ALEdge.h" // for Kruskal algoritm

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef Edge HData; // for Kruskal algoritm(int -> Edge)
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap {
	PriorityComp* comp;
	int numOfData;
	HData heapAry[HEAP_LEN];
}Heap;

void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);