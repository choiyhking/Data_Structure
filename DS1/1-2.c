#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	
	int ary[MAX];
	int cnt = 0;
	
	fp = fopen("DS1/input.txt", "r");
	
	if(fp == NULL)
	{
		printf("File error!\n");
		exit(1);
	}
	
	while(!feof(fp))
		fscanf(fp, "%d", &ary[cnt++]);
	
	int max = ary[0], min = ary[0];

	for(int i=1;i<cnt;i++)
	{
		if(ary[i] > max)
			max = ary[i];
		if(ary[i] < min)
			min = ary[i];
	}
	
	printf("Min: %d\n", min);
	printf("Max: %d\n", max);
	
	return 0;
}