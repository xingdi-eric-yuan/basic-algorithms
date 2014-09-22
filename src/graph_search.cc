#include "graph_search.h"
using namespace std;


int getDijkstraDistance(GraphNode *a, GraphNode *b, unordered_map<string, int> &graph_distance){
    unordered_set<int> visited;
    int res = 0;
    if(!a || !b) return res;
    a -> range = 0;
    GraphNode *p = a;
    vector<BinaryTreeNode*> Q;
    while(1){
        if(p != a && Q.empty()) break;
        //cout<<"@@@ "<<p -> id<<endl;
        BinaryTreeNode *heaproot = NULL;
        for(int i = 0; i < p -> neighbor.size(); i++){
            if(visited.find(p -> neighbor[i] -> id) == visited.end()){
                //cout<<"   ## "<<p -> neighbor[i] -> id<<endl;
                minHeapInsert(heaproot, p -> neighbor[i]);
                p -> neighbor[i] -> range = p -> neighbor[i] -> range < 
                                            (p -> range + getDistance(p, p -> neighbor[i], graph_distance)) ?
                                            p -> neighbor[i] -> range :
                                            (p -> range + getDistance(p, p -> neighbor[i], graph_distance));
            }
        }
        //printTree(heaproot);
        visited.insert(p -> id);
        Q.push_back(heaproot);

        while(!Q.empty() && isEmpty(Q[0])) Q.erase(Q.begin());
        while(!isEmpty(Q[0]) && visited.find(getTreeTop(Q[0]) -> id) != visited.end()) deleteTop(Q[0]);
        while(!Q.empty() && isEmpty(Q[0])) Q.erase(Q.begin());
        //if(!Q.empty()) printTree(Q[0]);
        if(!Q.empty() && ! isEmpty(Q[0])) p = extractTop(Q[0]);
    }
    return b -> range;
}

