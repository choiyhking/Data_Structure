#pragma once

#include "DLinkedList.h"
#include "ALEdge.h" 
#include "Heap.h" // Priority queue is almost same sa Heap(PQ can be made based on array, linkedlist, heap) 

typedef struct _algraph {
	int numV;
	int numE;
	List* adjList;
	int* visitInfo;

	// for Kruskal algoritm
	Heap pqueue;
}ALGraph;

void GraphInit(ALGraph* pg, int nv);

void GraphDestroy(ALGraph* pg);

void AddEdge(ALGraph* pg, int fromV, int toV, int weight);

void ShowGraphEdgeInfo(ALGraph* pg);

void ConKruskalMST(ALGraph* pg);

void ShowGraphEdgeWeightInfo(ALGraph* pg);