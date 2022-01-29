#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include "InfixToPostfix.h"

int main() {
	FILE* fp;
	char exp[MAX];

	fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("FILE OPEN ERROR!\n");
		exit(1);
	}

	fgets(exp, MAX, fp);

	ConvToPostfix(exp);

	printf("%s\n", exp);

	return 0;
}