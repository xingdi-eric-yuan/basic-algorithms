#include "minheap.h"

using namespace std;

void minHeapify(BinaryTreeNode* A){   
    int minimal;
    int flag = -1;
    minimal = A -> graphnode -> val;
    if(A -> left && A -> left -> graphnode -> val <= minimal){
        minimal = A -> left -> graphnode -> val;
        flag = LEFT;
    }
    if(A -> right && A -> right -> graphnode -> val <= minimal){
        minimal = A -> right -> graphnode -> val;
        flag = RIGHT;
    }
    if(LEFT == flag){
        graphnodeSwap(A,  A -> left);
        minHeapify(A -> left);
    }elif(RIGHT == flag){
        graphnodeSwap(A,  A -> right);
        minHeapify(A -> right);
    }
}

// build from a regular binary-tree
void buildMinHeap(BinaryTreeNode* A){
    int HeapSize = getTreeSize(A);
    serializeTree(A);
    for (int i = HeapSize / 2; i >= 0; i--){
        minHeapify(findId(A, i));
    }
}

GraphNode* extractTop(BinaryTreeNode*& T){
    if(!T) return NULL;
    GraphNode* min = T -> graphnode;
    if(!T -> left && !T -> right){
         T = NULL;
         return min;
    }
    serializeTree(T);
    int HeapSize = getTreeSize(T);
    graphnodeSwap(T, findId(T, HeapSize - 1));
    cutLastLeaf(T);
    minHeapify(T);
    return min;
}

void deleteTop(BinaryTreeNode*& T){
    if(!T) return;
    if(!T -> left && !T -> right){
         T = NULL;
         return;
    }
    serializeTree(T);
    int HeapSize = getTreeSize(T);
    graphnodeSwap(T, findId(T, HeapSize - 1));
    cutLastLeaf(T);
    minHeapify(T);
}

void minHeapInsert(BinaryTreeNode*& T,  GraphNode* ins){
    binaryTreeInsert(T, ins);
    serializeTree(T);
    int count_temp = getTreeSize(T) - 1;
    while (count_temp > 0 && findId(T, count_temp) -> parent -> graphnode -> val > findId(T, count_temp) -> graphnode -> val){
        graphnodeSwap(findId(T, count_temp), findId(T, count_temp) -> parent);
        count_temp = findId(T, count_temp) -> parent -> id;
    }
}





