#define COMP(a, b) (a>b) ? 1 : ((a==b) ? 0 : -1)

#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodePointer;
typedef struct node
{
	int coef; // 계수
	int expon; // 지수
	nodePointer link;
}node;
nodePointer a, b, c;

nodePointer addNode(nodePointer ptr, int coef, int expon);
nodePointer init(FILE *fp, nodePointer ptr);
nodePointer addPoly(nodePointer x, nodePointer y);
void printPoly(nodePointer ptr);

int main()
{
	FILE *fp1, *fp2;
	
	fp1 = fopen("DS11/a.txt", "r");
	if(fp1 == NULL)
	{
		fprintf(stderr, "File 1 error!\n");
		exit(EXIT_FAILURE);
	}
	
	fp2 = fopen("DS11/b.txt", "r");
	if(fp2 == NULL)
	{
		fprintf(stderr, "File 2 error!\n");
		exit(EXIT_FAILURE);
	}
	
	a = init(fp1, a);
	b = init(fp2, b);
	
	c = addPoly(a, b);
	printPoly(c);
	
	return 0;
}

nodePointer addNode(nodePointer ptr, int coef, int expon)
{
	nodePointer new, last;
	
	new = (nodePointer)malloc(sizeof(new));
	new->coef = coef;
	new->expon = expon;
	new->link = NULL;
	
	if(!ptr)
		ptr = new;
	else
	{
		for(last=ptr; last->link != NULL; last=last->link);
		last->link = new;
	}
	
	return ptr;
}

nodePointer init(FILE *fp, nodePointer ptr)
{
	int n, coef, expon; // n: non-zero term의 개수
	
	fscanf(fp, "%d", &n);
	
	for(int i=0; i<n; i++)
	{
		fscanf(fp, "%d %d", &coef, &expon);
		ptr = addNode(ptr, coef, expon);
	}
	
	return ptr;
}

nodePointer addPoly(nodePointer x, nodePointer y)
{
	int sum;
	
	while(x && y)
	{
		switch(COMP(x->expon, y->expon))
		{
			case 1:
				c = addNode(c, x->coef, x->expon);
				x = x->link;
				break;
			case 0:
				sum = x->coef + y->coef;
				if(sum)
				{
					c = addNode(c, sum, x->expon);
					x = x->link; y = y->link;
				}
				break;
			case -1:
				c = addNode(c, y->coef, y->expon);
				y = y->link;
				break;
		}
	}
	
	for(;x != NULL; x=x->link)
		c = addNode(c, x->coef, x->expon);
	
	for(;y != NULL; y=y->link)
		c = addNode(c, y->coef, y->expon);
	
	return c;
}

void printPoly(nodePointer ptr)
{
	nodePointer last;
	
	for(last=ptr; last != NULL; last=last->link)
	{
		if(last->expon)
		{
			if(last->coef > 0)
				printf("+%dx^%d", last->coef, last->expon);
			else
				printf("%dx^%d", last->coef, last->expon);
		}
		else // expon = 0
		{
			if(last->coef > 0)
				printf("+%d", last->coef);
			else
				printf("-%d", last->coef);
		}
	}
	printf("\n");
}