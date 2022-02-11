#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "ALGraphKruskal.h"

int main() {
	int N, weight;
	
	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("FILE OPEN ERROR!\n");
		exit(1);
	}

	ALGraph graph; 

	fscanf(fp, "%d", &N);

	GraphInit(&graph, N);

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			fscanf(fp, "%d", &weight);

			if (weight != 0 && i < j) { // check only upper matrix(¡ñ undirected graph)
				AddEdge(&graph, i, j, weight);
			}
		}
	}
	//ShowGraphEdgeInfo(&graph);
	
	ConKruskalMST(&graph);

	printf("Selected Edges:\n");
	ShowGraphEdgeWeightInfo(&graph);

	GraphDestroy(&graph);

	return 0;
}