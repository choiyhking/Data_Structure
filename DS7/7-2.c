#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fail(); // 실패함수 생성
int pmatch(); // KMP algorithm
void print_fail_func(int length);

char string[MAX], pat[MAX];
int failure[MAX];

int main()
{
	FILE *fp;

	int pos;
	
	fp = fopen("DS7/input.txt", "r");
	if(fp == NULL)
	{
		printf("File error!\n");
		exit(1);
	}
	
	fgets(string, MAX, fp);
	fgets(pat, MAX, fp);
	
	fail();
	print_fail_func(strlen(pat));
	pos = pmatch();
	
	printf("The pattern \"%s\" is found at the position %d.\n", pat, pos);
	
	return 0;
}

void fail()
{
	int i,  j, n = strlen(pat);

	failure[0] = -1;

	for (j = 1; j < n; j++)
	{
		i = failure[j - 1];
		
		while ((pat[j] != pat[i + 1]) && i >= 0)
			i = failure[i];

		if (pat[j] == pat[i + 1])
			failure[j] = i + 1;
		else
			failure[j] = -1;
	}
}

int pmatch()
{
	int i = 0, j = 0;
	int lens = strlen(string);
	int lenp = strlen(pat);

	while (i < lens && j < lenp)
	{
		if (string[i] == pat[j])
		{
			i++;	j++;
		}
		else if (j == 0)
			i++;
		else
			j = failure[j - 1] + 1;
	}

	return ((j == lenp) ? (i - lenp) : -1);
}

void print_fail_func(int length)
{
	printf("Failure function:\n");

	printf("%-5c", 'j'); // 왼쪽 정렬
	for (int i = 0; i < length; i++)
		printf("%3d", i);
	
	printf("\n%-5s", "pat");
	for (int i = 0; i < length; i++)
		printf("%3c", pat[i]);
	
	printf("\n%-5c", 'f');
	for (int i = 0; i < length; i++)
		printf("%3d", failure[i]);
	
	printf("\n");
}