#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stack;
int capacity = 1;
int top = -1;

int flag = 1;

void matching(char token);
void stackFull();
void push(char item);
char pop();

int main()
{
	char input[MAX];
	int n = 0;
	
	stack = (char *)malloc(sizeof(char));
	
	fgets(input, MAX, stdin);
	
	input[strlen(input)-1] = '\0'; // fgets()는 마지막에 개행문자가 붙는다("문자열\n\0")
	
	for(;input[n] != '\0' && flag == 1;n++)
	{
		switch(input[n])
		{
			case '(': case '{': case '[':
				push(input[n]);
				break;
			case ')':
				matching('(');
				break;
			case '}':
				matching('{');
				break;
			case ']':
				matching('[');
				break;
		}
	}

	if(flag == 1 && top == -1) // "{{{{{..."와 같은 경우 때문에 stack empty 검사
		printf("Balanced\n");
	else
		printf("Not balanced\n");
	
	return 0;
}

void matching(char token)
{
	if(token != pop())
		flag = -1;
}

void stackFull()
{
	stack = (char *)realloc(stack, 2*capacity*sizeof(char));
	capacity *= 2;
}

void push(char item)
{
	if(top >= capacity - 1)
		stackFull();
	
	stack[++top] = item;
}

char pop()
{
	if(top == -1)
		return ' '; // stack empty일 때 right delimiter가 들어오는 경우 처리
	
	return stack[top--];
}