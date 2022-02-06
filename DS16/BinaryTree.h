#pragma once

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* left;
	struct _node* right;
}Node;

Node* MakeBTreeNode();
Data GetData(Node* bt);
void SetData(Node* bt, Data data);

Node* GetLeftSubTree(Node* bt);
Node* GetRightSubTree(Node* bt);

void MakeLeftSubTree(Node* main, Node* sub);
void MakeRightSubTree(Node* main, Node* sub);

Node* RemoveLeftSubTree(Node* bt);
Node* RemoveRightSubTree(Node* bt);

void ChangeLeftSubTree(Node* main, Node* sub);
void ChangeRightSubTree(Node* main, Node* sub);

void PreorderTraverse(Node* bt);
void InorderTraverse(Node* bt);
void PostorderTraverse(Node* bt);