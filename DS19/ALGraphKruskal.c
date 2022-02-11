#include <stdio.h>
#include <stdlib.h>
#include "ALGraphKruskal.h"
#include "LStack.h"

int PQWeightComp(Edge d1, Edge d2) {
	return d1.weight - d2.weight; // for descending 
}

void GraphInit(ALGraph* pg, int nv) {
	pg->numV = nv;
	pg->numE = 0;
	pg->adjList = (List*)malloc(sizeof(List) * nv);
	
	for (int i = 0;i < nv;i++) {
		ListInit(&(pg->adjList[i]));
	}

	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);

	// for Kruskal algoritm
	HeapInit(&(pg->pqueue), PQWeightComp);
}

void GraphDestroy(ALGraph* pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

void AddEdge(ALGraph* pg, int fromV, int toV, int weight) {
	LInsert(&pg->adjList[fromV], toV);
	LInsert(&pg->adjList[toV], fromV);

	pg->numE += 1;

	// for Kruskal algoritm
	Edge edge = { fromV, toV, weight };
	HInsert(&(pg->pqueue), edge);
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

int visitVertex(ALGraph* pg, int visitV) {
	if (pg->visitInfo[visitV] == 0) {
		pg->visitInfo[visitV] = 1;
		
		//printf("%d ", visitV);
		return TRUE;
	}

	return FALSE;
}

void RemoveWayEdge(ALGraph* pg, int fromV, int toV) {
	int edge;

	if (LFirst(&(pg->adjList[fromV]), &edge)) {
		if (edge == toV) {
			LRemove(&(pg->adjList[fromV]));
		}

		while (LNext(&(pg->adjList[fromV]), &edge)) {
			if (edge == toV) {
				LRemove(&(pg->adjList[fromV]));

				break;
			}
		}
	}
}

void RemoveEdge(ALGraph* pg, int fromV, int toV) {
	RemoveWayEdge(pg, fromV, toV);
	RemoveWayEdge(pg, toV, fromV);
	(pg->numE)--;
}

void RecoverEdge(ALGraph* pg, int fromV, int toV, int weight) {
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
}

int IsConnVertex(ALGraph* pg, int v1, int v2) { // using DFS
	Stack stack; StackInit(&stack);
	int visitV = v1;
	int nextV;

	visitVertex(pg, visitV);
	SPush(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV)) {
		int visitFlag = FALSE;

		if (nextV == v2) {
			memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
			return TRUE;
		}

		if (visitVertex(pg, nextV)) {
			SPush(&stack, nextV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else {
			while (LNext(&(pg->adjList[visitV]), &nextV)) {
				if (nextV == v2) {
					memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
					return TRUE;
				}

				if (visitVertex(pg, nextV)) {
					SPush(&stack, nextV);
					visitV = nextV;
					visitFlag = TRUE;

					break;
				}
			}
		}

		if (visitFlag == FALSE) {
			if (SIsEmpty(&stack)) {
				break;
			}
			else {
				visitV = SPop(&stack);
			}
		}
	}

	memset(pg->visitInfo, 0, sizeof(int)* pg->numV);
	return FALSE;
}

void ConKruskalMST(ALGraph* pg) {
	Edge recvEdge[20];
	Edge edge;
	int eidx = 0;

	while (pg->numE + 1 > pg->numV) {
		edge = HDelete(&(pg->pqueue));
		RemoveEdge(pg, edge.v1, edge.v2);
	
		if (!IsConnVertex(pg, edge.v1, edge.v2)) {
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
			recvEdge[eidx++] = edge;
		}
	}

	for (int i = 0;i < eidx;i++) {
		HInsert(&(pg->pqueue), recvEdge[i]);
	}
}

void ShowGraphEdgeWeightInfo(ALGraph* pg) {
	int sum = 0;

	Heap copyPQ = pg->pqueue;
	Edge edge;

	while (!HIsEmpty(&copyPQ)) {
		edge = HDelete(&copyPQ);
		sum += edge.weight;
		printf("(%d, %d)\n", edge.v1, edge.v2);
	}

	printf("Cost: %d\n", sum);
}