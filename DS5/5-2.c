#define MAX_TERMS 100
#define COMPARE(a, b) (a>b ? 1 : ((a==b) ? 0 : -1))

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int coef;
	int exp;
}polynomial;
polynomial a[MAX_TERMS];

int n, idx = 0, startA, finishA, startB, finishB, startC, finishC;

void readPoly(FILE *fp);
void addPoly();
void printPoly(int start, int finish);

int main()
{
	FILE *fp1, *fp2;
	
	fp1 = fopen("DS5/a.txt", "r");
	fp2 = fopen("DS5/b.txt", "r");
	if(!fp1 && !fp2)
	{
		printf("File error!\n");
		exit(1);
	}
	
	startA = 0;
	readPoly(fp1);
	finishA = startA + n - 1;
	
	startB = finishA + 1;
	readPoly(fp2);
	finishB = startB + n - 1;
	startC = finishB + 1;
	
	addPoly();
	printPoly(startC, finishC);
	
	return 0;
}

void readPoly(FILE *fp)
{	
	fscanf(fp, "%d", &n); // the number of non-zero terms
	while(!feof(fp)){
		fscanf(fp, "%d %d", &a[idx].coef, &a[idx].exp);
		idx++;
	}
}

void addPoly()
{
	int avail = startC;
	int sum = 0;
	
	while(startA<=finishA && startB<=finishB)
	{
		switch(COMPARE(a[startA].exp, a[startB].exp))
		{
			case 1:
				a[avail].coef = a[startA].coef;
				a[avail++].exp = a[startA++].exp;
				break;
				
			case -1:
				a[avail].coef = a[startB].coef;
				a[avail++].exp = a[startB++].exp;
				break;
				
			case 0:
				sum = a[startA].coef + a[startB].coef; 
				if(sum)
				{
					a[avail].coef = sum;
					a[avail++].exp = a[startA].exp;
					startA++; startB++;
				}
				break;
		}
	}
	
	for(;startA<=finishA;avail++, startA++)
	{
		a[avail].coef = a[startA].coef;
		a[avail].exp = a[startA].exp;
	}
	
	for(;startB<=finishB;avail++, startB++)
	{
		a[avail].coef = a[startB].coef;
		a[avail].exp = a[startB].exp;
	}
	
	finishC = avail - 1;
}

void printPoly(int start, int finish)
{
	for(int i=start;i<=finish;i++)
	{	
		if(a[i].exp == 0)
		{
			printf("%d", a[i].coef);
			break;
		}
		printf("%dX^%d + ", a[i].coef, a[i].exp);
	}
	printf("\n");
}