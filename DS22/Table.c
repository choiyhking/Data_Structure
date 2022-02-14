#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

void TBLInit(Table* pt, HashFunc* f) {
	for (int i = 0;i < MAX_TBL;i++) {
		pt->tbl[i].status = EMPTY;
	}
	pt->hf = f;
}

void TBLInsert(Table* pt, Key k, Value v) {
	int hv = pt->hf(k);

	if (pt->tbl[hv].status == INUSE) {
		while (pt->tbl[hv].status == INUSE) { // Linear probing
			hv += 1;
		}
	}

	pt->tbl[hv].key = k;
	pt->tbl[hv].value = v;
	pt->tbl[hv].status = INUSE;
}

Value TBLDelete(Table* pt, Key k) {
	int hv = pt->hf(k);

	if ((pt->tbl[hv]).status != INUSE) {
		return NULL;
	}
	else {
		(pt->tbl[hv]).status = DELETED;
		return (pt->tbl[hv]).value;
	}
}

Value TBLSearch(Table* pt, Key k) {
	int hv = pt->hf(k);
	
	if ((pt->tbl[hv]).status != INUSE)
		return NULL;
	else
		return (pt->tbl[hv]).value;
}