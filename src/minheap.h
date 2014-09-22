#pragma once
//#include "binary_tree.h"
#include "general_settings.h"

using namespace std;

void minHeapify(BinaryTreeNode*);

void buildMinHeap(BinaryTreeNode*);

GraphNode* extractTop(BinaryTreeNode*&);

void deleteTop(BinaryTreeNode*&);

void minHeapInsert(BinaryTreeNode*&, GraphNode*);
