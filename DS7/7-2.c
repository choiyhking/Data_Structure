#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fail(char* pat, char* failure);
int pmatch(char* string, char* pat, char* failure);
void printFailure(char* pat, char* failure);

int main() {
	FILE* fp;
	char string[MAX], pat[MAX], failure[MAX];
	int idx;

	fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("FILE OPEN ERROR!\n");
		exit(1);
	}

	fgets(string, MAX, fp);
	fgets(pat, MAX, fp);

	fail(pat, failure);
	idx = pmatch(string, pat, failure);

	printFailure(pat, failure);

	printf("The pattern \"%s\" is found at the position %d\n", pat, idx);

	return 0;
}

void fail(char* pat, char* failure) {
	int i, j, n = strlen(pat);

	failure[0] = -1;
	
	for (j = 1; j < n; j++) {
		i = failure[j - 1];

		while ((pat[j] != pat[i + 1]) && i >= 0)
			i = failure[i];

		if (pat[j] == pat[i + 1])
			failure[j] = i + 1;
		else
			failure[j] = -1;
	}
}

int pmatch(char* string, char* pat, char* failure) {
	int i = 0, j = 0;
	int lens = strlen(string);
	int lenp = strlen(pat);

	while (i < lens && j < lenp) {
		if (string[i] == pat[j]) {
			i++; j++;
		}
		else if (j == 0)
			i++;
		else
			j = failure[j - 1] + 1;
	}

	return ((j == lenp) ? (i - lenp) : -1);
}

void printFailure(char* pat, char* failure) {
	printf("Failure function:");
	
	printf("\n%-5c", 'j');
	for (int i = 0;i < strlen(pat);i++)
		printf("%3d", i);

	printf("\n%-5s", "pat");
	for (int i = 0;i < strlen(pat);i++)
		printf("%3c", pat[i]);

	printf("\n%-5c", 'f');
	for (int i = 0;i < strlen(pat);i++)
		printf("%3d", failure[i]);

	printf("\n\n");
}