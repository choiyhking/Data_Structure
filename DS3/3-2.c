#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodePointer;
typedef struct node
{
	int data;
	nodePointer link;
}node;

// function prototype
nodePointer add(nodePointer ptr, int data);

int main()
{
	int f, r; 
	// 'f' means number of friends and 'r' means words in rhyme
	
	printf("Number of friends: ");
	scanf("%d", &f);
	
	printf("Words in rhyme: ");
	scanf("%d", &r);
	
	nodePointer last, queue = NULL, prev = NULL; // prev는 삭제할 노드의 선행 노드
	
	// 게임 참여인원 초기화
	for(int i=1;i<=f;i++)
		queue = add(queue, i);
	
	// 처음과 끝을 이어주기
	for(last = queue;last->link != NULL;last = last->link);
		last->link = queue;
	
	// 게임시작!
	nodePointer now = queue; // 현재 위치

	for(int temp=f;temp>1;temp--) // 1명이 남을 때 까지 진행
	{
		for(int i=0;i<r-1;i++)
		{
			prev = now;
			now = now->link;
		}
		// for문을 마친 now는 탈락할 번호를 가리킴
		prev->link = now->link; // 삭제
		free(now);
		now = prev->link;
	}
	
	printf("Number %d is left\n", now->data);
	
	return 0;
}

nodePointer add(nodePointer ptr, int data)
{
	nodePointer newNode, last;
	newNode = (nodePointer)malloc(sizeof(newNode));
	
	newNode->data = data;
	newNode->link = NULL;
	
	if(ptr == NULL)
		ptr = newNode;
	else
	{
		for(last = ptr;last->link != NULL;last = last->link);
		last->link = newNode;
	}
	
	return ptr;
}