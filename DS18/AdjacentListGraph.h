#include "DLinkedList.h"

typedef struct _graph {
	int numV; // the number of vertices
	int numE; // the number of edges
	List* adjList;

	int* visitInfo; // for searching(DFS, BFS)
}ALGraph;

void GraphInit(ALGraph* pg, int nv);

void GraphDestroy(ALGraph* pg);

void AddEdge(ALGraph* pg, int fromV, int toV);

void ShowGraphEdgeInfo(ALGraph* pg);

void DFShowGraphVertex(ALGraph* pg, int startV);
void BFShowGraphVertex(ALGraph* pg, int startV);