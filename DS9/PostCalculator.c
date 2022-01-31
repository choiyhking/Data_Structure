#pragma once

#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalPostExp(char exp[]) {
	Stack stack;
	StackInit(&stack);

	int explen = strlen(exp), op1, op2;
	char tok;

	for (int i = 0;i < explen;i++) {
		tok = exp[i];

		if (isdigit(tok)) {
			SPush(&stack, tok - '0');
		}
		else {
			op2 = SPop(&stack);
			op1 = SPop(&stack);

			switch (tok) {
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			}
		}
	}
	
	return SPop(&stack);
}