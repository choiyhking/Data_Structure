#define MAX 100000

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, num;
	
	printf("Number: ");
	scanf("%d", &num);
	
	if(num > MAX)
	{
		printf("Wrong number!\n");
		exit(1);
	}
	
	for(i=2;i<num;i++)
	{
		if((num % i) == 0)
			break;
	}
	
	if(i == num)
		printf("Prime\n");
	else
		printf("Not Prime\n");
	
	return 0;
}