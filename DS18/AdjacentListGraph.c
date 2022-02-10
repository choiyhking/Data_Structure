#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "AdjacentListGraph.h"
#include "LStack.h"
#include "CQueue.h"

void GraphInit(ALGraph* pg, int nv) {
	pg->adjList = (List*)malloc(sizeof(List) * nv);
	pg->numV = nv;
	pg->numE = 0;

	for (int i = 0;i < nv;i++) {
		ListInit(&(pg->adjList[i]));
	}

	// for searching
	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void GraphDestroy(ALGraph* pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);

	// for searching
	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

void AddEdge(ALGraph* pg, int fromV, int toV) { // directed graph: <A, B> ¡Á <B, A>
	LInsert(&(pg->adjList[fromV]), toV);
	//LInsert(&(pg->adjList[toV]), fromV); // undirected graph
	
	pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph* pg) {
	int vx; 

	for (int i = 0;i < pg->numV;i++) {
		printf("Vertex %d: ", i);

		if (LFirst(&(pg->adjList[i]), &vx)) {
			printf("%d ", vx);

			while (LNext(&(pg->adjList[i]), &vx)) {
				printf("%d ", vx);
			}
		}
		printf("\n");
	}
}

int VisitVertex(ALGraph* pg, int visitV) {
	if (pg->visitInfo[visitV] == 0) {
		pg->visitInfo[visitV] = 1;

		printf("%d ", visitV);
		return TRUE;
	}
	return FALSE;
}

void DFShowGraphVertex(ALGraph* pg, int startV) {
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE) {
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else {
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
				if (VisitVertex(pg, nextV) == TRUE) {
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE) {
			if (SIsEmpty(&stack) == TRUE)
				break;
			visitV = SPop(&stack);
		}
	}
	printf("\n");

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void BFShowGraphVertex(ALGraph* pg, int startV) {
	Queue queue; QueueInit(&queue);
	int visitV = startV;
	int nextV;

	VisitVertex(pg, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
		if (VisitVertex(pg, nextV) == TRUE) {
			Enqueue(&queue, nextV);
		}

		while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
			if (VisitVertex(pg, nextV) == TRUE) {
				Enqueue(&queue, nextV);
			}
		}

		if (QIsEmpty(&queue) == TRUE) {
			break;
		}
		else {
			visitV = Dequeue(&queue);
		}
	}
	printf("\n");

	memset(pg->adjList, 0, sizeof(int) * pg->numV);
}