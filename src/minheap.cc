#include "minheap.h"

using namespace std;

void minHeapify(BinaryTreeNode* A, int mode){  
    double minimal;
    int flag = -1; 
    if(mode == HEAP_VAL){
        minimal = A -> graphnode -> val;
        if(A -> left && A -> left -> graphnode -> val <= minimal){
            minimal = A -> left -> graphnode -> val;
            flag = LEFT;
        }
        if(A -> right && A -> right -> graphnode -> val <= minimal){
            minimal = A -> right -> graphnode -> val;
            flag = RIGHT;
        }
    }elif(mode == HEAP_F_SCORE){
        minimal = A -> graphnode -> f_score;
        if(A -> left && A -> left -> graphnode -> f_score <= minimal){
            minimal = A -> left -> graphnode -> f_score;
            flag = LEFT;
        }
        if(A -> right && A -> right -> graphnode -> f_score <= minimal){
            minimal = A -> right -> graphnode -> f_score;
            flag = RIGHT;
        }
    }
    if(LEFT == flag){
        graphnodeSwap(A,  A -> left);
        minHeapify(A -> left, mode);
    }elif(RIGHT == flag){
        graphnodeSwap(A,  A -> right);
        minHeapify(A -> right, mode);
    }
}

// build from a regular binary-tree
void buildMinHeap(BinaryTreeNode* A, int mode){
    int HeapSize = getTreeSize(A);
    serializeTree(A);
    for (int i = HeapSize / 2; i >= 0; i--){
        minHeapify(findId(A, i), mode);
    }
}

GraphNode* extractTop(BinaryTreeNode*& T, int mode){
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
    minHeapify(T, mode);
    return min;
}

void deleteTop(BinaryTreeNode*& T, int mode){
    if(!T) return;
    if(!T -> left && !T -> right){
         T = NULL;
         return;
    }
    serializeTree(T);
    int HeapSize = getTreeSize(T);
    graphnodeSwap(T, findId(T, HeapSize - 1));
    cutLastLeaf(T);
    minHeapify(T, mode);
}

void minHeapInsert(BinaryTreeNode*& T,  GraphNode* ins, int mode){
    binaryTreeInsert(T, ins);
    serializeTree(T);
    int count_temp = getTreeSize(T) - 1;
    if(mode == HEAP_VAL){
        while (count_temp > 0 && findId(T, count_temp) -> parent -> graphnode -> val > findId(T, count_temp) -> graphnode -> val){
            graphnodeSwap(findId(T, count_temp), findId(T, count_temp) -> parent);
            count_temp = findId(T, count_temp) -> parent -> id;
        }
    }elif(mode == HEAP_F_SCORE){
        while (count_temp > 0 && findId(T, count_temp) -> parent -> graphnode -> f_score > findId(T, count_temp) -> graphnode -> f_score){
            graphnodeSwap(findId(T, count_temp), findId(T, count_temp) -> parent);
            count_temp = findId(T, count_temp) -> parent -> id;
        }
    }
}





