#define _CRT_SECURE_NO_WARNINGS

#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

int DataPriComp(int d1, int d2);
void Swap(int ary[], int a, int b);
int Partition(int ary[], int left, int right);
void QuickSort(int ary[], int left, int right);

int main() {
	int n, temp, i = 0;
	int ary[MAX];
	Heap h; HeapInit(&h, DataPriComp);

	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("File open error!\n");
		exit(1);
	}

	fscanf(fp, "%d", &n);
	while (!feof(fp)) {
		fscanf(fp, "%d", &temp);
		ary[i++] = temp;
		HInsert(&h, temp);
	}

	printf("Heap Sort\n");
	for (int i = 0;i < n;i++) {
		printf("%d ", HDelete(&h));
	}

	printf("\nQuick Sort\n");
	QuickSort(ary, 0, n-1);

	for (int i = 0;i < n;i++) {
		printf("%d ", ary[i]);
	}

	return 0;
}

int DataPriComp(int d1, int d2) {
	//return d1 - d2;
	return d2 - d1;
}

void Swap(int ary[], int a, int b) {
	int temp = ary[a];
	ary[a] = ary[b];
	ary[b] = temp;
}

int Partition(int ary[], int left, int right) {
	int pivot = ary[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (pivot >= ary[low] && low <= right) {
			low++;
		}

		while (pivot <= ary[high] && high >= (left + 1)) {
			high--;
		}

		if (low <= high) {
			Swap(ary, low, high);
		}
	}

	Swap(ary, left, high);
	return high;
}

void QuickSort(int ary[], int left, int right) {
	if (left <= right) {
		int pivot = Partition(ary, left, right);
		QuickSort(ary, left, pivot - 1);
		QuickSort(ary, pivot + 1, right);
	}
}