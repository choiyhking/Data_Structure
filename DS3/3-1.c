#define SWAP(x, y, temp) (temp=x, x=y, y=temp) 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int *ary, int n);

int main()
{
	int n;
	int *ary = (int *)malloc(sizeof(int)*n);
	
	FILE *fp1, *fp2;
	clock_t start, stop;
	
	scanf("%d", &n);
	if(n > 10000)
	{
		printf("Wrong input!\n");
		exit(1);
	}
	
	fp1 = fopen("unsorted.txt", "w+");
	fp2 = fopen("sorted.txt", "w+");
	
	// seed값 초기화
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		ary[i] = rand()%2000-1000;
		fprintf(fp1, "%d ", ary[i]);
	}	
	
	start = clock();
	selectionSort(ary, n);
	stop = clock();
	
	for(int i=0;i<n;i++)
		fprintf(fp2, "%d ", ary[i]);
	
	double duration = ((double)(stop - start) / CLOCKS_PER_SEC);
	printf("Time: %.10f\n", duration);
	
	free(ary);
	
	return 0;
}

void selectionSort(int *ary, int n)
{
	int maxIndex, temp;
	
	for(int i=0;i<n-1;i++)
	{
		maxIndex = i;
		for(int j=i+1;j<n;j++)
		{
			if(ary[j]>ary[maxIndex])
				maxIndex = j;
		}
		
		SWAP(ary[i], ary[maxIndex], temp);
	}
}