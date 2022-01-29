#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListBaseStack.h";

int main() {
	char input[MAX];
	int i, len = strlen(input), flag = 1;
	Stack stack;

	StackInit(&stack);

	gets(input);

	for (i = 0;i < len && flag == 1;i++) {
		switch (input[i]) {
			case '(': case '{': case '[':
				SPush(&stack, input[i]);
				break;

			case ')': 
				if (SIsEmpty(&stack) || SPop(&stack) != '(')
					flag = -1; // not balanced
				break;

			case '}': 
				if (SIsEmpty(&stack) || SPop(&stack) != '{')
					flag = -1;
				break;
			
			case ']':
				if (SIsEmpty(&stack) || SPop(&stack) != '[')
					flag = -1;
				break;
		}
	}

	if (flag == -1 || !SIsEmpty(&stack))
		printf("Not balanced\n");
	else
		printf("Balance\n");

	return 0;
}