#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

Node* MakeTreeNode(){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

Data GetData(Node* bt) {
	return bt->data;
}

void SetData(Node* bt, Data data) {
	bt->data = data;
}

Node* GetLeftSubTree(Node* bt) {
	return bt->left;
}

Node* GetRightSubTree(Node* bt) {
	return bt->right;
}

void MakeLeftSubTree(Node* main, Node* sub) {
	if (main->left != NULL) {
		free(main->left);
	}

	main->left = sub;
}

void MakeRightSubTree(Node* main, Node* sub) {
	if (main->right != NULL) {
		free(main->right);
	}

	main->right = sub;
}

void PreorderTraverse(Node* bt) {
	if (bt == NULL)
		return;

	printf("%c ", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

void InorderTraverse(Node* bt) {
	if (bt == NULL)
		return;

	InorderTraverse(bt->left);
	printf("%c ", bt->data);
	InorderTraverse(bt->right);
}

void PostorderTraverse(Node* bt) {
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%c ", bt->data);
}