#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nfind(char* string, char* pat);

int main() {
	FILE* fp;
	char string[MAX], pat[MAX];
	int idx;

	fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("FILE OPEN ERROR!\n");
		exit(1);
	}

	fgets(string, MAX, fp);
	fgets(pat, MAX, fp);

	idx = nfind(string, pat);

	if (idx) {
		printf("The pattern \"%s\" is found at the position %d\n", pat, idx);
	}

	return 0;
}

int nfind(char* string, char* pat) {
	int lasts = strlen(string) - 1;
	int lastp = strlen(pat) - 1;
	int i, j, start, endmatch, res; // 'i' moves on the string, 'j' on the pat 

	for (start = 0, endmatch = lastp;endmatch <= lasts;start++, endmatch++) {
		if (string[endmatch] == pat[lastp]) { // compare from last char
			for (i = start, j = 0;i < endmatch, j < lastp;i++, j++) {
				if (string[i] != pat[j]) 
					break;
			}
			if (j == lastp) // found
				return res = start;
		}
	}

	return -1; // not found
}