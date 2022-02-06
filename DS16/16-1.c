#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main() {
	int temp;

	FILE* fp1 = fopen("input1.txt", "r");
	FILE* fp2 = fopen("input2.txt", "r");
	if (fp1 == NULL || fp2 == NULL) {
		printf("File Open Error!\n");
		exit(1);
	}

	Node* bst;
	BSTMakeAndInit(&bst);
	
	while (!feof(fp1)) {
		fscanf(fp1, "%d", &temp);
		BSTInsert(&bst, temp);
	}

	printf("PreorderTraverse: ");
	PreorderTraverse(bst);

	printf("\nInorderTraverse: ");
	InorderTraverse(bst);
	
	printf("\nPostorderTraverse: ");
	PostorderTraverse(bst);

	printf("\nSearch: ");
	while (!feof(fp2)) {
		fscanf(fp2, "%d", &temp);
		if (BSTSearch(bst, temp) == NULL) // not found
			printf("0 ");
		else
			printf("1 ");
	}

	return 0;
}