#pragma once

#include <stdio.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

void BSTMakeAndInit(Node** pRoot) {
	*pRoot = NULL;
}

Data BSTGetNodeData(Node* bst) {
	return GetData(bst);
}

void BSTInsert(Node** pRoot, Data data) { // double pointer -> call-by-reference
	Node* pNode = NULL; // parent node
	Node* cNode = *pRoot; // current node
	Node* nNode = NULL; // new node

	while (cNode != NULL) {
		if (data == GetData(cNode))
			return;

		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	nNode = MakeBTreeNode();
	SetData(nNode, data);

	if (pNode != NULL) {
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else // new node is root node
		*pRoot = nNode;
}

Node* BSTSearch(Node* bst, Data target) { // call-by-value
	Node* cNode = bst;
	Data cdata;

	while (cNode != NULL) {
		cdata = GetData(cNode);

		if (target == cdata)
			return cNode;
		else if (target > cdata)
			cNode = GetRightSubTree(cNode);
		else
			cNode = GetLeftSubTree(cNode);
	}

	return NULL; // not found
}

Node* BSTRemove(Node** pRoot, Data target) {
	Node* pVRoot = MakeBTreeNode();
	Node* pNode = pVRoot; // virtual root node
	Node* cNode = *pRoot;
	Node* dNode = NULL;

	ChangeRightSubTree(pVRoot, *pRoot);

	while (cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;

		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL) // target isn't exist
		return NULL;

	dNode = cNode;

	// 1. dNode is 'leaf node'
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}
	// 2. dNode has only one child node
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {
		Node* dcNode; // child node of dNode

		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}
	// 3. dNode has two child nodes
	else {
		Node* mNode = GetRightSubTree(dNode); // alternate node init -> I decided to replace with the smallest value in RST
		Node* mpNode = dNode; // parent node of mNode
		int delData;

		while (GetLeftSubTree(mNode) != NULL) { // to find smallest value in tree, we have to go left until NULL
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		delData = GetData(dNode); // back-up
		SetData(dNode, GetData(mNode));

		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);

		// when the deleted node is root node 
		if (GetRightSubTree(pVRoot) != *pRoot)
			*pRoot = GetRightSubTree(pVRoot);

		free(pVRoot);
		return dNode;
	}
}