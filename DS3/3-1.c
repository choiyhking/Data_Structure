#define SWAP(x, y, t) (t=x, x=y, y=t)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int* ary, int n);

int main() {
	int n, temp;
	FILE* fp1, * fp2;
	clock_t start, stop;

	fopen_s(&fp1, "unsorted.txt", "w+");
	fopen_s(&fp2, "sorted.txt", "w+");
	if (fp1 == NULL || fp2 == NULL) {
		printf("FILE OPEN ERROR!\n");
		exit(1);
	}

	scanf_s("%d", &n);

	int* ary = (int*)malloc(sizeof(int) * n);

	srand((unsigned int)time(NULL)); // seed init

	// rand: generate random number [0 ~ RAND_MAX]
	for (int i = 0;i < n;i++) {
		temp = rand();
		ary[i] = temp;
		fprintf(fp1, "%d ", temp);
	}
	
	start = clock();
	selectionSort(ary, n);
	stop = clock();

	for (int i = 0;i < n;i++) {
		fprintf(fp2, "%d ", ary[i]);
	}

	double duration = ((double)(stop - start) / CLOCKS_PER_SEC);
	printf("Time: %.10f\n", duration);

	fclose(fp1); fclose(fp2);
	free(ary);

	return 0;
}

void selectionSort(int* ary, int n) {
	int minIdx, temp;

	for (int i = 0;i < n-1;i++) {
		minIdx = i;
		
		for (int j = i+1;j < n;j++) {
			if (ary[j] < ary[minIdx]) // Ascending
				minIdx = j;
		}
		SWAP(ary[i], ary[minIdx], temp);
	}
}