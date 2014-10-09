#include "binary_tree.h"

using namespace std;

BinaryTreeNode *createBinaryTree(vector<GraphNode*> &vec, int head, int tail){
    if(head > tail) return NULL;
    if(head == tail){
        BinaryTreeNode *node = new BinaryTreeNode(vec[head]);
        return node;
    }
    int mid = head + (tail - head + 1) / 2;
    BinaryTreeNode *node = new BinaryTreeNode(vec[mid]);
    BinaryTreeNode *l = createBinaryTree(vec, head, mid - 1);
    BinaryTreeNode *r = createBinaryTree(vec, mid + 1, tail);
    node -> left = l;
    node -> right = r;
    if(l) l -> parent = node;
    if(r) r -> parent = node;
    return node;
}

void tree2Vectors(BinaryTreeNode *root, int height, vector<vector<BinaryTreeNode*> > &layer){
    if(!root) return;
    while(height >= layer.size()){
        vector<BinaryTreeNode*> tmp;
        layer.push_back(tmp);
    }
    layer[height].push_back(root);
    if(root -> left) tree2Vectors(root -> left, height + 1, layer);
    if(root -> right) tree2Vectors(root -> right, height + 1, layer);
}

void printTree(BinaryTreeNode *root){
    if(!root) cout<<"NULL"<<endl;;
    vector<vector<BinaryTreeNode*> > layer;
    tree2Vectors(root, 0, layer);
    for(int i = 0; i < layer.size(); i++){
        cout<<"layer["<<i<<"] : ";
        for(int j = 0; j < layer[i].size(); j++){
            cout<<layer[i][j] -> graphnode -> val<<", ";
        }
        cout<<endl;
    }
}

void serializeTree(BinaryTreeNode *root){
    if(!root) return;
    vector<vector<BinaryTreeNode*> > layer;
    tree2Vectors(root, 0, layer);
    int counter = 0;
    for(int i = 0; i < layer.size(); i++){
        for(int j = 0; j < layer[i].size(); j++){
            layer[i][j] -> id = counter;
            ++ counter;
        }
    }
    for(int i = 0; i < layer.size(); i++){
        layer[i].clear();
    }
    layer.clear();

}

void valSwap(BinaryTreeNode* a,  BinaryTreeNode* b){
    int temp;
    temp = a -> graphnode -> val;
    a -> graphnode -> val = b -> graphnode -> val;
    b -> graphnode -> val = temp;
}

void graphnodeSwap(BinaryTreeNode* a,  BinaryTreeNode* b){
    GraphNode* temp;
    temp = a -> graphnode;
    a -> graphnode = b -> graphnode;
    b -> graphnode = temp;
}


BinaryTreeNode* findVal(BinaryTreeNode* T, int wanted){
    BinaryTreeNode* Result  =  NULL;  
    if (!T) return NULL;
    if (T -> graphnode -> val == wanted) return T;
    else{
        Result = findVal(T -> left, wanted);
        if(Result) return Result;
        Result = findVal(T -> right, wanted);
        if(Result) return Result;
    }
    return NULL;
}

BinaryTreeNode* findId(BinaryTreeNode* T, int wanted){
    BinaryTreeNode* Result  =  NULL;  
    if (!T) return NULL;
    if (T -> id == wanted) return T;
    else{
        Result = findId(T -> left, wanted);
        if(Result) return Result;
        Result = findId(T -> right, wanted);
        if(Result) return Result;
    }
    return NULL;
}

int getTreeSize(BinaryTreeNode *root){
    if(!root) return 0;
    return getTreeSize(root -> left) + getTreeSize(root -> right) + 1;
}

int getTreeHeight(BinaryTreeNode *root){
    if(!root) return 0;
    int left = getTreeHeight(root -> left);
    int right = getTreeHeight(root -> right);
    return (left > right ? left : right) + 1;
}

void binaryTreeInsert(BinaryTreeNode*& T, GraphNode* value){
    if(!T){
        BinaryTreeNode *newone = new BinaryTreeNode(value);
        T = newone;
        return;
    }
    std::queue<BinaryTreeNode*> visited, unvisited; 
    BinaryTreeNode *newone = new BinaryTreeNode(value);
    BinaryTreeNode* current;
    unvisited.push(T); 
    while(!unvisited.empty()){
        current = unvisited.front(); 
        if(!current -> left){
            current -> left = newone;
            newone -> parent = current;
            break;
        }else{
            unvisited.push(current -> left); 
            if(!current -> right){
                current -> right = newone;
                newone -> parent = current;
                break;
            }else{
                unvisited.push(current -> right);
            }
        }
        visited.push(current);
        unvisited.pop();
    }
}

bool isEmpty(BinaryTreeNode* root){
    return (!root);
}

void cutLeaf(BinaryTreeNode*& A,  int num){
    if(!A -> left && ! A -> right && num == 0) A = NULL;
    serializeTree(A);
    BinaryTreeNode *tmp = findId(A, num);
    if (tmp == tmp -> parent -> left){
        tmp -> parent -> left = NULL;
    }elif(tmp == tmp -> parent -> right){
        tmp -> parent -> right = NULL;
    }
}

void cutLastLeaf(BinaryTreeNode*& root){
    if(!root -> left && ! root -> right) root = NULL;
    int HeapSize = getTreeSize(root);
    if(HeapSize > 0) cutLeaf(root, HeapSize - 1);
}

GraphNode* getTreeTop(BinaryTreeNode *root){
    return root -> graphnode;
}

bool isInTree(BinaryTreeNode *root, GraphNode *g){
    if(!root) return false;
    if(!g) return false;
    if(root -> graphnode == g) return true;
    return isInTree(root -> left, g) || isInTree(root -> right, g);
}

BinaryTreeNode* rightRotate(BinaryTreeNode *root, BinaryTreeNode* rot){
    BinaryTreeNode *res = root;
    if(!rot -> left && ! rot -> right) return res;
    BinaryTreeNode *pivot = rot -> left;
    rot -> left = pivot -> right;
    if(pivot -> right) pivot -> right -> parent = rot;
    pivot -> parent = rot -> parent;
    if(!rot -> parent) res = pivot;
    elif(rot == rot -> parent -> left) rot -> parent -> left = pivot;
    else rot -> parent -> right = pivot;
    pivot -> right = rot;
    rot ->parent = pivot;
    return res;
}

BinaryTreeNode* leftRotate(BinaryTreeNode *root, BinaryTreeNode *rot){

    BinaryTreeNode *res = root;
    if(!rot -> left && ! rot -> right) return res;
    BinaryTreeNode *pivot = rot -> right;
    rot -> right = pivot -> left;
    if(pivot -> left) pivot -> left -> parent = rot;
    pivot -> parent = rot -> parent;
    if(!rot -> parent) res = pivot;
    elif(rot == rot -> parent -> left) rot -> parent -> left = pivot;
    else rot -> parent -> right = pivot;
    pivot -> left = rot;
    rot ->parent = pivot;
    return res;
}

BinaryTreeNode* mostLeft(BinaryTreeNode *node){
    BinaryTreeNode *res = node;
    while(res -> left) res = res -> left;
    return res;
}

BinaryTreeNode* mostRight(BinaryTreeNode *node){
    BinaryTreeNode *res = node;
    while(res -> right) res = res -> right;
    return res;
}

BinaryTreeNode* successor(BinaryTreeNode *node){
    if(!node) return NULL;
    if(node -> right) return mostLeft(node -> right);
    else{
        BinaryTreeNode *res = node;
        while(1){
            if(!res -> parent) return NULL;
            if(res == res -> parent -> left) return res -> parent;
            res = res -> parent;
        }
    }
}

BinaryTreeNode* predecessor(BinaryTreeNode *node){
    if(!node) return NULL;
    if(node -> left) return mostRight(node -> left);
    else{
        BinaryTreeNode *res = node;
        while(1){
            if(!res -> parent) return NULL;
            if(res == res -> parent -> right) return res -> parent;
            res = res -> parent;
        }
    }
}





