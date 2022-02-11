#include "Heap.h"

void HeapInit(Heap* ph, PriorityComp pc) {
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
	return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap* ph, int idx) {
	if (GetLChildIDX(idx) > ph->numOfData) // no child node
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfData) // only left child node
		return GetLChildIDX(idx); 
	else { // both
		if (ph->comp(ph->heapAry[GetLChildIDX(idx)], ph->heapAry[GetRChildIDX(idx)]) < 0) // d2 is higher priority than d1
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap* ph, HData data) {
	int idx = ph->numOfData + 1;

	while (idx != 1) {
		if (ph->comp(data, ph->heapAry[GetParentIDX(idx)]) > 0) {
			ph->heapAry[idx] = ph->heapAry[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}

	ph->heapAry[idx] = data;
	ph->numOfData += 1;
}

HData HDelete(Heap* ph) {
	HData rdata = ph->heapAry[1];
	HData lastElem = ph->heapAry[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) {
		if (ph->comp(lastElem, ph->heapAry[childIdx]) >= 0)
			break; // find correct place!

		ph->heapAry[parentIdx] = ph->heapAry[childIdx];
		parentIdx = childIdx;
	}

	ph->heapAry[parentIdx] = lastElem;
	ph->numOfData -= 1;
	
	return rdata;
}