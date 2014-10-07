#pragma once
//#include "binary_tree.h"
#include "general_settings.h"

using namespace std;

void minHeapify(BinaryTreeNode*, int mode = 0);

void buildMinHeap(BinaryTreeNode*, int mode = 0);

GraphNode* extractTop(BinaryTreeNode*&, int mode = 0);

void deleteTop(BinaryTreeNode*&, int mode = 0);

void minHeapInsert(BinaryTreeNode*&, GraphNode*, int mode = 0);
