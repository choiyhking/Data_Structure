#include <stdio.h>
#include <stdlib.h>
#include "CQueue.h"

void QueueInit(Queue* pq) {
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue* pq) {
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos) {
	if (pos == Q_LEN - 1) // last idx
		return 0; // circular
	else
		return pos + 1;
}

void Enqueue(Queue* pq, Data data) {
	if (NextPosIdx(pq->rear) == pq->front) {
		printf("Stack is full!\n");
		exit(1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->qArr[pq->rear] = data;
}

Data Dequeue(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("Stack is empty!\n");
		exit(1);
	}

	pq->front = NextPosIdx(pq->front);
	
	return pq->qArr[pq->front];
}

Data QPeek(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("Stack is empty!\n");
		exit(1);
	}

	return pq->qArr[NextPosIdx(pq->front)];
}