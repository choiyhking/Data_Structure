#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodePointer;
typedef struct node
{
	int num;
	nodePointer link;
}node;

nodePointer addNode(nodePointer ptr, int num);
nodePointer delete(nodePointer ptr, nodePointer trail, nodePointer x);

int main()
{
	int f, r;
	nodePointer ptr = NULL, trail, temp;
	
	printf("Number of friends: ");
	scanf("%d", &f);
	
	printf("Words in rhyme: ");
	scanf("%d", &r);
	
	// init
	for(int i=1; i<=f; i++)
		ptr = addNode(ptr, i);
	
	// create circular linked list
	for(temp=ptr; temp->link != NULL; temp=temp->link);
	temp->link = ptr;
	
	temp = ptr;
	// Game start!
	while(f > 1)
	{
		for(int i=0; i<r-1; i++)
		{
			trail = temp;
			temp = temp->link;
		}
			
		ptr = delete(ptr, trail, temp);
		f--; 
		temp = trail->link;
	}
	
	printf("Number %d is left\n", temp->num);
	
	return 0;
}

nodePointer addNode(nodePointer ptr, int num)
{
	nodePointer new, last;
	
	new = (nodePointer)malloc(sizeof(new));
	new->num = num;
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

nodePointer delete(nodePointer ptr, nodePointer trail, nodePointer x)
{
	if(trail)
		trail->link = x->link;
	else // 맨 앞 노드를 삭제하는 경우
		ptr = ptr->link;
	
	free(x);
	
	return ptr;
}