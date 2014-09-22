#pragma once
#include "general_settings.h"

using namespace std;

// Definition for singly-linked list.
struct GraphNode {
    int val;
    int id;
    int range;
    vector<GraphNode*> neighbor;
    GraphNode(int x, int y, int z) : id(x), val(y), range(z) {}
};

struct BinaryTreeNode{
    //int val;
    GraphNode *graphnode;
    int id;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode* parent;
    BinaryTreeNode(GraphNode* x) : graphnode(x), id(0), left(NULL), right(NULL), parent(NULL){}
};


