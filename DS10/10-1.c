#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodePointer;
typedef struct node
{
	int data;
	nodePointer link;
}node;

nodePointer addNode(nodePointer ptr, int data);
nodePointer concat(nodePointer ptr1, nodePointer ptr2);
nodePointer invert(nodePointer ptr);
void printList(nodePointer ptr);

int main()
{
	FILE *fp1, *fp2;
	int num;
	nodePointer first = NULL, second = NULL;
	
	fp1 = fopen("DS10/input1.txt", "r");
	if(fp1 == NULL)
	{
		fprintf(stderr, "File 1 error!\n");
		exit(EXIT_FAILURE);
	}
	
	fp2 = fopen("DS10/input2.txt", "r");
	if(fp2 == NULL)
	{
		fprintf(stderr, "File 2 error!\n");
		exit(EXIT_FAILURE);
	}
	
	while(fscanf(fp1, "%d", &num) != EOF)
		first = addNode(first, num);
	
	while(fscanf(fp2, "%d", &num) != EOF)
		second = addNode(second, num);
	
	printf("<First>\n");
	printList(first);
	
	printf("<Second>\n");
	printList(second);

	printf("<Concatenate>\n");
	first = concat(first, second);
	printList(first);

	printf("<Invert>\n");
	first = invert(first);
	printList(first);

	return 0;
}

nodePointer addNode(nodePointer ptr, int data)
{
	nodePointer new, last;
	
	new = (nodePointer)malloc(sizeof(new));
	new->data = data;
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

nodePointer concat(nodePointer ptr1, nodePointer ptr2)
{
	nodePointer temp;
	
	for(temp=ptr1; temp->link != NULL; temp=temp->link);
	temp->link = ptr2;
	
	return ptr1;
}

nodePointer invert(nodePointer ptr)
{
	nodePointer middle, trail;
	middle = NULL;
	
	while(ptr)
	{
		trail = middle;
		middle = ptr;
		ptr = ptr->link;
		middle->link = trail;
	}
	
	return middle;
}

void printList(nodePointer ptr)
{
		for (; ptr != NULL; ptr=ptr->link)
			printf("(%p,  %d,  %p)  ", ptr, ptr->data, ptr->link);
		printf("\n\n");
}