#include <stdio.h>
#include <stdlib.h>
#include "DLinkedlist.h"

int WhoIsPrecede(int d1, int d2);
void printPoly(List* plist);

int main() {
	int n1, n2; // the number of non-zero terms
	int coefA, exponA, coefB, exponB, coefC, exponC;
	
	int flagA = TRUE, flagB = TRUE, sum = 0;

	List listA, listB, listC;
	FILE* fp1, * fp2;
	
	fopen_s(&fp1, "a.txt", "r");
	fopen_s(&fp2, "b.txt", "r");
	if (fp1 == NULL || fp2 == NULL) {
		printf("FILE OPEN ERROR!\n");
		exit(1);
	}

	fscanf_s(fp1, "%d", &n1);
	fscanf_s(fp2, "%d", &n2);
	
	SetSortRule(&listA, WhoIsPrecede);
	SetSortRule(&listB, WhoIsPrecede);
	SetSortRule(&listC, WhoIsPrecede);

	ListInit(&listA);
	ListInit(&listB);
	ListInit(&listC);

	while (!feof(fp1)) {
		fscanf_s(fp1, "%d %d", &coefA, &exponA);
		//printf("%d %d\n", coefA, exponA);
		LInsert(&listA, coefA, exponA);
	}
	while (!feof(fp2)) {
		fscanf_s(fp2, "%d %d", &coefB, &exponB);
		//printf("%d %d\n", coefB, exponB);
		LInsert(&listB, coefB, exponB);
	}

	// 'flag = FALSE' means that there is no more node
	flagA = LFirst(&listA, &coefA, &exponA);
	flagB = LFirst(&listB, &coefB, &exponB);

	while(flagA && flagB) { 
		if (exponA > exponB) {
			LInsert(&listC, coefA, exponA);
			flagA = LNext(&listA, &coefA, &exponA);
		}
		else if (exponA < exponB) {
			LInsert(&listC, coefB, exponB);
			flagB = LNext(&listB, &coefB, &exponB);
		}
		else { // same
			sum = coefA + coefB;
			if (sum)
				LInsert(&listC, sum, exponA);
			flagA = LNext(&listA, &coefA, &exponA);
			flagB = LNext(&listB, &coefB, &exponB);
		}
	}

	// add remaining nodes
	if (!flagA) {
		while (flagB) {
			LInsert(&listC, coefB, exponB);
			flagB = LNext(&listB, &coefB, &exponB);
		}
	}
	else {
		while (flagA) {
			LInsert(&listC, coefA, exponA);
			flagA = LNext(&listA, &coefA, &exponA);
		}
	}

	printPoly(&listC);

	return 0;
}

int WhoIsPrecede(int d1, int d2) {
	if (d1 > d2)
		return 1;
	else
		return 0;
}

void printPoly(List* plist) {
	int coef, expon;

	if (LFirst(plist, &coef, &expon)) { // why not '&plist'..? 
										// maybe 'plist' is already address of listC(plist = &listC)
		printf("%dx^%d + ", coef, expon);

		for (int i = 0;i < LCount(plist) - 1;i++) {
			if (LNext(plist, &coef, &expon)) {
				if (i == LCount(plist) - 2) { // last node
					if (expon == 0)
						printf("%d\n", coef);
					else
						printf("%dx^%d\n", coef, expon);
				}
				else
					printf("%dx^%d + ", coef, expon);
			}

		}
	}
}