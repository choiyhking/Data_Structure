#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int *stack;
int capacity = 1;
int top = -1;

char input[MAX];

void stackFull();
void push(int num);
int pop();
void eval();

int main()
{
	FILE *fp;
	
	stack = (int *)malloc(sizeof(int));
	
	fp = fopen("DS9/input.txt", "r");
	if(fp == NULL)
	{
		fprintf(stderr, "File error!\n");
		exit(EXIT_FAILURE);
	}
	
	fgets(input, MAX, fp);
	
	eval();
	
	return 0;
}

void stackFull()
{
	stack = (int *)realloc(stack, 2*capacity*sizeof(int));
	capacity *= 2;
}

void push(int num)
{
	if(top >= capacity - 1)
		stackFull();
	
	stack[++top] = num;
}

int pop()
{
	if(top <= -1)
		printf("Stack is empty!\n");
	
	return stack[top--];
}

void eval()
{
	int idx = 0, n1, n2;
	char symbol;
	
	for(symbol=input[idx++]; symbol != '\0'; symbol=input[idx++])
	{
		if(isdigit(symbol)) // operand
			push(symbol -'0');
		
		else // operater
		{
			n2 = pop(); 
			n1 = pop();
			
			switch(symbol)
			{	
				case '+':
					push(n1 + n2); break;
				case '-':
					push(n1 - n2); break;
				case '*':
					push(n1 * n2); break;
				case '/':
					push(n1 / n2); break;
				case '%':
					push(n1 % n2); break;
			}
		}
	}
	
	// answer
	printf("%d\n", pop());
}