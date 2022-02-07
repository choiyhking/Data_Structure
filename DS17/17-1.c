#define _CRT_SECURE_NO_WARNINGS
#define MAX_KEY 101 // maximum number of keys in each runs(100 + '999')

#include <stdio.h>
#include <stdlib.h>

int comp(int d1, int d2);
void LevelorderTraverse(int ary[], int k);
void InorderTraverse(int ary[], int idx, int k);

int main() {
	int k, temp, cnt = 0, j = 0; // k: the number of 'run'
	int** runs, **check;
	int wTree[100];

	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("File Open Error!\n");
		exit(1);
	}

	fscanf(fp, "%d", &k);

	runs = (int**)malloc(sizeof(int*) * k);
	for (int i = 0;i < k;i++) {
		runs[i] = (int*)malloc(sizeof(int) * MAX_KEY);
	}

	// to find the next num in each run
	check = (int**)calloc(k, sizeof(int*));
	for (int i = 0;i < k;i++) {
		check[i] = (int*)calloc(MAX_KEY, sizeof(int));
	}

	// run init
	while (!feof(fp)) {
		fscanf(fp, "%d", &temp);

		if (temp == -1) { // last of each run
			runs[cnt++][j] = 999;
			j = 0;
		}
		else {
			runs[cnt][j++] = temp;
		}
	}
	
	// winner tree init
	int minRunidx = 0;
	for (int i = 0;i < k;i++) {
		if (runs[minRunidx][0] > runs[i][0])
			minRunidx = i; // for restructing

		wTree[i + k] = runs[i][0];

		check[i][0] = 1; // used
	}

	// structing
	int cur = k; // starting pos
	while (cur > 1) {
		for (int i = cur;i < 2*cur;i=i+2) { // compare with siblings -> i+2: next sibling group
			if (comp(wTree[i], wTree[i + 1]))
				wTree[i / 2] = wTree[i + 1]; // smaller node is winner!
			else
				wTree[i / 2] = wTree[i];
		}

		cur /= 2; // level - 1
	}
	
	printf("Winner: %d\n", wTree[1]);
	LevelorderTraverse(wTree, k);

	printf("Inorder: ");
	InorderTraverse(wTree, 1, k);

	// restructing
	int nextIdx = 0;
	while (check[minRunidx][nextIdx] == 1) {
		nextIdx++;
	}
	
	wTree[minRunidx + k] = runs[minRunidx][nextIdx];

	cur = minRunidx + k;
	if (cur % 2 == 1)
		cur--;

	for (;cur > 1;cur/=2) { 
		if (cur % 2 == 1)
			cur--;

		if (comp(wTree[cur], wTree[cur + 1]))
			wTree[cur / 2] = wTree[cur + 1];
		else
			wTree[cur / 2] = wTree[cur];
	}

	printf("\nWinner: %d\n", wTree[1]);
	LevelorderTraverse(wTree, k);

	printf("Inorder: ");
	InorderTraverse(wTree, 1, k);

	for (int i = 0;i < k;i++) {
		free(runs[i]);
	}
	free(runs);

	return 0;
}

int comp(int d1, int d2) {
	if (d1 >= d2)
		return 1;
	else
		return 0;
}

void LevelorderTraverse(int ary[], int k) {
	printf("Level Order: ");

	for (int i = 1;i < 2 * k; i++) {
		printf("%d ", ary[i]);
	}
	printf("\n");
}

void InorderTraverse(int ary[], int idx, int k) {
	if (idx > 2*k - 1) // out of bound
		return;

	InorderTraverse(ary, idx * 2, k);
	printf("%d ", ary[idx]);
	InorderTraverse(ary, idx * 2 + 1, k);
}