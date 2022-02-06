#pragma once

#include "BinaryTree.h"

void BSTMakeAndInit(Node** pRoot);

Data BSTGetNodeData(Node* bst);

void BSTInsert(Node** pRoot, Data data);

Node* BSTSearch(Node* bst, Data target);

Node* BSTRemove(Node** pRoot, Data target);