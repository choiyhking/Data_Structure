#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "AdjacentListGraph.h"

int main() {
	int N, temp; // the number of vertices

	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("File Open Error!\n");
		exit(1);
	}

	ALGraph graph; 

	fscanf(fp, "%d", &N);

	GraphInit(&graph, N);

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			fscanf(fp, "%d", &temp);

			if (temp == 1) {
				AddEdge(&graph, i, j);
			}
		}
	}

	ShowGraphEdgeInfo(&graph);

	printf("DFS: ");
	DFShowGraphVertex(&graph, 0);

	printf("BFS: ");
	BFShowGraphVertex(&graph, 0);

	return 0;
}