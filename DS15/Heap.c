#pragma once

#include "Heap.h"

void HeapInit(Heap* ph, PriorityComp* pc) {
	ph->numOfData = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap* ph) {
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) {
	return idx / 2;
}

int GetLChildIDX(int idx) {
	return idx * 2;
}

int GetRChildIDX(int idx) {
	return idx * 2 + 1;
}

int GetHiPriChildIDX(Heap* ph, int idx) {
	if (GetLChildIDX(idx) > ph->numOfData) // leaf node
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfData) // only left child node
		return GetLChildIDX(idx);
	else {
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap* ph, Data data) {
	int idx = ph->numOfData + 1;

	while (idx != 1) {
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0) { // compare with parent node
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}

	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}

Data HDelete(Heap* ph) {
	Data rdata = ph->heapArr[1];
	Data lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1; // where the last node will be placed
	int childIdx;

	while(childIdx = GetHiPriChildIDX(ph, parentIdx)) {
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	
	return rdata;
}