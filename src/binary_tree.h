#pragma once
#include "general_settings.h"

using namespace std;

BinaryTreeNode* createBinaryTree(vector<GraphNode*>&, int, int);

void printTree(BinaryTreeNode*);

void tree2Vectors(BinaryTreeNode*, int, vector<vector<BinaryTreeNode*> >&);

void serializeTree(BinaryTreeNode*);

void valSwap(BinaryTreeNode*, BinaryTreeNode*);

void graphnodeSwap(BinaryTreeNode*,  BinaryTreeNode*);

BinaryTreeNode* findVal(BinaryTreeNode*,  int);

BinaryTreeNode* findId(BinaryTreeNode*,  int);

int getTreeSize(BinaryTreeNode*);

int getTreeHeight(BinaryTreeNode*);

void binaryTreeInsert(BinaryTreeNode*&, GraphNode*);

bool isEmpty(BinaryTreeNode*);

void cutLeaf(BinaryTreeNode*, int);

void cutLastLeaf(BinaryTreeNode*);

GraphNode* getTreeTop(BinaryTreeNode *);

bool isInTree(BinaryTreeNode*, GraphNode*);

BinaryTreeNode* rightRotate(BinaryTreeNode*, BinaryTreeNode*);

BinaryTreeNode* leftRotate(BinaryTreeNode*, BinaryTreeNode*);