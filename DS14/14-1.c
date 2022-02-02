#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

int main() {
	Node* bt1 = MakeTreeNode(); SetData(bt1, 'A');
	Node* bt2 = MakeTreeNode(); SetData(bt2, 'B');
	Node* bt3 = MakeTreeNode(); SetData(bt3, 'C');
	Node* bt4 = MakeTreeNode(); SetData(bt4, 'D');
	Node* bt5 = MakeTreeNode(); SetData(bt5, 'E');
	Node* bt6 = MakeTreeNode(); SetData(bt6, 'F');
	Node* bt7 = MakeTreeNode(); SetData(bt7, 'G');
	Node* bt8 = MakeTreeNode(); SetData(bt8, 'H');
	Node* bt9 = MakeTreeNode(); SetData(bt9, 'I');
	
	MakeLeftSubTree(bt4, bt8);
	MakeRightSubTree(bt4, bt9);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeLeftSubTree(bt3, bt6);
	MakeRightSubTree(bt3, bt7);
	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);

	printf("Preorder:\n");
	PreorderTraverse(bt1);

	printf("\nInorder:\n");
	InorderTraverse(bt1);

	printf("\nPostorder:\n");
	PostorderTraverse(bt1);

	return 0;
}