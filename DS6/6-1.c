#define _CRT_SECURE_NO_WARNINGS
#define MAX_TERMS 101
#define MAX_COLS 10

#include <stdio.h>
#include <stdlib.h>

typedef struct _term {
	int row;
	int col;
	int value;
}term;

void printMat(term mat[]);
void fastTranspose(term mat1[], term mat2[]);

int main() {
	FILE* fp1, * fp2;
	int n1, m1, n2, m2; // the number of rows, cols
	int value1, value2, idx = 0, sum = 0;
	
	term a[MAX_TERMS], b[MAX_TERMS];
	
	fp1 = fopen("mat1.txt", "r");
	fp2 = fopen("mat2.txt", "r");
	if (fp1 == NULL || fp2 == NULL) {
		printf("FILE OPEN ERROR!\n");
		exit(1);
	}

	fscanf(fp1, "%d %d", &n1, &m1);
	fscanf(fp2, "%d %d", &n2, &m2);

	a[idx].row = n1;
	a[idx].col = m1;
	a[idx++].value = 0;

	for (int i = 0;i < n1;i++) {
		for (int j = 0;j < m1;j++) {
			fscanf(fp1, "%d", &value1);
			fscanf(fp2, "%d", &value2);
			
			sum = value1 + value2;
			
			if (sum) {
				a[idx].row = i;
				a[idx].col = j;
				a[idx++].value = sum;
				a[0].value++;
			}
		}
	}

	printf("Matrix Addition:\n");
	printMat(a);
	
	printf("Transpose Matrix:\n");
	fastTranspose(a, b);
	printMat(b);

	return 0;
}

void printMat(term mat[]) {
	int cnt = mat[0].value;

	for (int i = 0;i <= cnt;i++) {
		printf("%d %d %d\n", mat[i].row, mat[i].col, mat[i].value);
	}
}

void fastTranspose(term mat1[], term mat2[]) // mat1 - transpose -> mat2
{
	int rowTerms[MAX_COLS];
	int startingPos[MAX_COLS];

	int numTerms = mat1[0].value;
	int numCols = mat1[0].col;

	mat2[0].row = mat1[0].col;
	mat2[0].col = mat1[0].row;
	mat2[0].value = mat1[0].value;


	for (int i = 0;i < numCols;i++) {
		rowTerms[i] = 0;
	}

	for (int i = 1;i <= numTerms;i++) {
		rowTerms[mat1[i].col]++;
	}

	startingPos[0] = 1;

	for (int i = 1;i < numCols;i++) {
		startingPos[i] = rowTerms[i - 1] + startingPos[i - 1];
	}

	for (int i = 1;i <= numTerms;i++) {
		int j = startingPos[mat1[i].col]++;

		mat2[j].row = mat1[i].col;
		mat2[j].col = mat1[i].row;
		mat2[j].value = mat1[i].value;
	}
}