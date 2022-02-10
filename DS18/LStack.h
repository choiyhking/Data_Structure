#ifndef __LSTACK_H__
#define __LSTACK_H__

#define TRUE 1
#define FALSE 0

typedef int SData;

typedef struct _snode {
	SData data;
	struct _node* next;
}SNode;

typedef struct _listStack {
	SNode* head;
}ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, SData data);
SData SPop(Stack* pstack);
SData SPeek(Stack* pstack);

#endif