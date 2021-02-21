#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nfind(char *string, char *pat);

int main()
{
	FILE *fp;
	
	char string[MAX], pat[MAX];
	int res; // 시작 위치
	
	fp = fopen("DS7/input.txt", "r");
	if(fp == NULL)
	{
		printf("File error!\n");
		exit(1);
	}
	
	fgets(string, MAX, fp);
	fgets(pat, MAX, fp);
	
	res = nfind(string, pat);
	
	printf("The pattern \"%s\" is found at the position %d.\n", pat, res);
	
	return 0;
}

int nfind(char *string, char *pat)
{
	int lasts = strlen(string) - 1;
	int lastp = strlen(pat) - 1;
	int i, j, start, endmatch, res;
	
	for(start=0, endmatch=lastp;endmatch<=lasts;start++, endmatch++)
	{
		if(string[endmatch] == pat[lastp]) // 맨 마지막 문자부터 비교
		{
			for(i=start, j=0;i<endmatch, j<lastp;i++, j++)
				if(string[i] != pat[j]) break;
			
			if(j == lastp) return res = start;
		}
		else
			continue;
	}
	
	return -1; // 발견하지 못했을 경우
}