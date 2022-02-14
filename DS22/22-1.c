#define _CRT_SECURE_NO_WARNINGS

/*
* input.txt
* 
* D: size of hash table
* N: input data
* M: search data
* 
* D N M
* K1 K2 K3 ¡¦ KN
* S1 S2 ¡¦ SM
*/

#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

int HFunc(int k) {
	return k % 10;
}

int main() {
	int D, N, M, temp, search;
	Table tb; 
	TBLInit(&tb, HFunc);

	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("File open error!\n");
		exit(1);
	}

	fscanf(fp, "%d %d %d", &D, &N, &M);

	for (int i = 0;i < N;i++) {
		fscanf(fp, "%d", &temp);
		TBLInsert(&tb, temp, temp);
	}

	printf("Hash Table:\n");
	for (int i = 0;i < D;i++) {
		printf("%d: ", i);

		if(tb.tbl[i].value > 0)
			printf("%d ",tb.tbl[i].value);
		printf("\n");
	}

	printf("\nSearch:\n");
	for (int i = 0;i < M;i++) {
		fscanf(fp, "%d", &search);

		if (TBLSearch(&tb, search))
			printf("S");
		else
			printf("F");
	}
	printf("\n");

	return 0;
}