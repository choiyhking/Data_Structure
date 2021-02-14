#define MAX_TERMS 101

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int col;
	int row;
	int value;
}term;
term a[MAX_TERMS], b[MAX_TERMS];

void fastTranspose();
void printMat(term *mat);

int main()
{
	FILE *fp1, *fp2;
	int m1, m2, n1, n2; // 'm'은 행, 'n'은 열의 갯수 
	int cnt = 0; // non-zero term의 갯수
	int temp1, temp2;
	
	fp1 = fopen("DS6/mat1.txt", "r");
	fp2 = fopen("DS6/mat2.txt", "r");
	if(!fp1 || !fp2)
	{
		printf("File error!\n");
		exit(1);
	}
	
	fscanf(fp1, "%d %d", &m1, &n1);
	fscanf(fp2, "%d %d", &m2, &n2);
	if((m1 != m2) || (n1 != n2))
	{
		printf("Wrong matrix size!\n");
		exit(1);
	}
	
	// 초기화(row major order, 3-tuple)
	a[0].row = m1;
	a[0].col = n1;
	
	for(int i=0;i<m1*n1;i++)
	{
		fscanf(fp1, "%d", &temp1);
		fscanf(fp2, "%d", &temp2);
		
		if(temp1 + temp2)
		{
			cnt++;
			a[cnt].row = i/4;
			a[cnt].col = i%4;
			a[cnt].value = temp1 + temp2;
		}
	}
	a[0].value = cnt;
	
	printf("Matrix Addition:\n");
	printMat(a);
	
	printf("Transpose Matrix:\n");
	fastTranspose();
	printMat(b);
	
	return 0;
}

void fastTranspose()
{
	int rowTerms[MAX_TERMS], startingPos[MAX_TERMS]; // 원래는 MAX_COL을 정의해줘야 함
	int numCols = a[0].col, numTerms = a[0].value;
	
	b[0].row = numCols; b[0].col = a[0].row; b[0].value = numTerms;
	
	for(int i=0;i<numCols;i++)
		rowTerms[i] = 0;
	
	for(int i=1;i<=numTerms;i++)
		rowTerms[a[i].col]++;
	
	startingPos[0] = 1;
	for(int i=1;i<numCols;i++)
		startingPos[i] = startingPos[i-1] + rowTerms[i-1];
	
	for(int i=1;i<=numTerms;i++)
	{
		int j = startingPos[a[i].col]++;
		b[j].row = a[i].col;
		b[j].col = a[i].row;
		b[j].value = a[i].value;
	}
}

void printMat(term *mat)
{
	for(int i=0;i<=mat[0].value;i++)
		printf("%d %d %d\n", mat[i].row, mat[i].col, mat[i].value);
}