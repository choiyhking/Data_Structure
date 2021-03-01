#include <stdio.h>
#include <stdlib.h>

int *stack;
int capacity = 1;
int top = -1;

void stackFull();
void push(int item);
void pop();

int main()
{
	char input;
	int value;
	FILE *fp;
	
	stack = (int *)malloc(sizeof(int));
	
	fp = fopen("DS8/input.txt", "r");
	if(fp == NULL)
	{
		fprintf(stderr, "File error!\n");
		exit(EXIT_FAILURE);
	}
	
	while(EOF != fscanf(fp, "%c", &input))
	{
		if(input == 'I')
		{
			fscanf(fp, "%d", &value);
			push(value);
		}
		else if(input == 'D')
			pop();
		
		// else는 공백일 경우
	}
	
	/*
	while(!feof(fp))
	{
		fscanf(fp, "%c", &input);
		...
	}
	
	이런 식으로 했을 때, 마지막에 읽은 값('D')이 두 번 나옴.
	=> 입력 스트림이 파일 끝에 이르렀다고 해서 feof()로 바로 알 수 없다.
	*/
	
	for(int i=0;i<=top;i++)
		printf("%d ", stack[i]);
	printf("\n");
	
	return 0;
}

void stackFull()
{
	stack = (int *)realloc(stack, 2*capacity*sizeof(int));
	capacity *= 2;
}

void push(int item)
{
	if(top >= capacity - 1)
		stackFull();
	
	stack[++top] = item;
}

void pop()
{
	if(top == -1)
		printf("Stack is empty!\n");
	
	top--;
	//return stack[top--];
}