#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

void HeapInit(Heap* ph, PriorityComp pc) {
	ph->comp = pc;
	ph->numOfData = 0;
}

int HIsEmpty(Heap* ph) {
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIdx(int idx) {
	return idx / 2;
}

int GetLChildIdx(int idx) {
	return idx * 2;
}

int GetRChildIdx(int idx) {
	return idx * 2 + 1;
}

int GetHiPriChilIdx(Heap* ph, int idx) {
	if (GetLChildIdx(idx) > ph->numOfData)
		return 0;
	else if (GetLChildIdx(idx) == ph->numOfData)
		return GetLChildIdx(idx);
	else {
		if (ph->comp(ph->heapAry[GetLChildIdx(idx)], ph->heapAry[GetRChildIdx(idx)]) < 0)
			return GetRChildIdx(idx);
		else
			return GetLChildIdx(idx);
	}
}

void HInsert(Heap* ph, Data data) {
	int idx = ph->numOfData + 1;

	while (idx != 1) {
		if (ph->comp(data, ph->heapAry[GetParentIdx(idx)]) > 0) {
			ph->heapAry[idx] = ph->heapAry[GetParentIdx(idx)];
			idx = GetParentIdx(idx);
		}
		else
			break;
	}

	ph->heapAry[idx] = data;
	ph->numOfData += 1;
}

Data HDelete(Heap* ph) {
	Data rdata = ph->heapAry[1];
	Data lastElem = ph->heapAry[ph->numOfData];

	int pIdx = 1;
	int cIdx;

	while (cIdx = GetHiPriChilIdx(ph, pIdx)) {
		if (ph->comp(lastElem, ph->heapAry[cIdx]) >= 0)
			break;

		ph->heapAry[pIdx] = ph->heapAry[cIdx];
		pIdx = cIdx;
	}

	ph->heapAry[pIdx] = lastElem;
	ph->numOfData -= 1;
	
	return rdata;
}