#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int main() {
	FILE* fp;
	char exp[MAX];
	int res;
	
	fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("FILE OPEN ERROR!\n");
		exit(1);
	}

	fgets(exp, MAX, fp);

	ConvToPostfix(exp);
	res = EvalPostExp(exp);

	printf("%d\n", res);

	return 0;
}