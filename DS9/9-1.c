#define MAX 100

#include <stdio.h>
#include <stdlib.h>

typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos, operand} precedence;

// lparen부터 eos까지의 우선순위 값
int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

// 수식
char input[MAX];

// stack
precedence *stack;
int capacity = 1;
int top = -1;

// prototype
void stackFull();
void push(precedence item);
precedence pop();
precedence getToken(char *symbol, int *idx);
void to_Postfix();
char getOp(precedence token);

int main()
{
	FILE *fp;
	
	stack = (precedence *)malloc(sizeof(precedence));
	
	fp = fopen("DS9/input.txt", "r");
	if(fp == NULL)
	{
		fprintf(stderr, "File error!\n");
		exit(EXIT_FAILURE);
	}
	
	fgets(input, MAX, fp);
	
	to_Postfix();
	
	return 0;
}

void stackFull()
{
	stack = (precedence *)realloc(stack, 2*capacity*sizeof(precedence));
	capacity *= 2;
}

void push(precedence item)
{
	if(top >= capacity - 1)
		stackFull();
	
	stack[++top] = item;
}

precedence pop()
{
	if(top <= -1)
		printf("Stack is empty!\n");
	
	return stack[top--];
}

precedence getToken(char *symbol, int *idx)
{
	*symbol = input[(*idx)++];
	
	switch(*symbol)
	{
		case '(': return lparen;
		case ')': return rparen;
		case '+': return plus;
		case '-': return minus;
		case '*': return times;
		case '/': return divide;
		case '%': return mod;
		case '\0': return eos; // end of string
		default: return operand;
	}
}

void to_Postfix()
{
	precedence token;
	char symbol;
	int idx = 0; 
	
	push(eos); // 스택 초기화(isp = 0)
	
	for(token = getToken(&symbol, &idx); token != eos; token = getToken(&symbol, &idx))
	{
		if(token == operand)
			printf("%c", symbol);
		
		else if(token == rparen)
		{
			while(stack[top] != lparen)
				printf("%c", getOp(pop()));
			pop(); // lparen 버리기
		}
		else
		{
			if(isp[stack[top]] >= icp[token])
				printf("%c", getOp(pop()));
			push(token);
		}
		
	}
	
	// stack에 남아있는 것들 빼주기
	while((token=pop()) != eos)
		printf("%c", getOp(token));
	
	printf("\n");
}

char getOp(precedence token)
{
	switch(token)
	{
		case plus: return '+';
		case minus: return '-';
		case times: return '*';
		case divide: return '/';
		case mod: return '%';
	}
}