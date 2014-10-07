#include "graph_search.h"
using namespace std;

void Dijkstra(GraphNode *a, const unordered_map<string, double> &graph_distance){
    unordered_set<int> visited;
    if(!a) return;
    a -> cost = 0;
    GraphNode *p = a;
    vector<BinaryTreeNode*> Q;
    while(1){
        if(p != a && Q.empty()) break;
        BinaryTreeNode *heaproot = NULL;
        for(int i = 0; i < p -> neighbor.size(); i++){
            if(visited.find(p -> neighbor[i] -> id) == visited.end()){
                minHeapInsert(heaproot, p -> neighbor[i]);
                p -> neighbor[i] -> cost = p -> neighbor[i] -> cost < 
                                            (p -> cost + getDistance(p, p -> neighbor[i], graph_distance)) ?
                                            p -> neighbor[i] -> cost :
                                            (p -> cost + getDistance(p, p -> neighbor[i], graph_distance));
            }
        }
        visited.insert(p -> id);
        Q.push_back(heaproot);

        while(!Q.empty() && isEmpty(Q[0])) Q.erase(Q.begin());
        while(!isEmpty(Q[0]) && visited.find(getTreeTop(Q[0]) -> id) != visited.end()) deleteTop(Q[0]);
        while(!Q.empty() && isEmpty(Q[0])) Q.erase(Q.begin());
        if(!Q.empty() && ! isEmpty(Q[0])) p = extractTop(Q[0]);
    }
}

double getDijkstraDistance(GraphNode *a, GraphNode *b, const unordered_map<string, double> &graph_distance){
    if(!a || !b) return 0;
    Dijkstra(a, graph_distance);
    return b -> cost;
}

void reconstruct_path(unordered_map<GraphNode*, GraphNode*> &came_from, GraphNode* current){
    cout<<current -> id<<endl;
    if(came_from.find(current) != came_from.end())
        reconstruct_path(came_from, came_from[current]);
}

void A_star(GraphNode *a, GraphNode *b, const unordered_map<string, double> &graph_distance){

    GraphNode *start = a;
    unordered_map<GraphNode*, GraphNode*> came_from;
    unordered_set<GraphNode*> visited;
    start -> g_score = 0.0;
    start -> f_score = start -> g_score + start -> estimate;
    BinaryTreeNode *openset = NULL;
    minHeapInsert(openset, start, HEAP_F_SCORE);
    while(!isEmpty(openset)){
        GraphNode* current = extractTop(openset, HEAP_F_SCORE);
        if(current == b){
            reconstruct_path(came_from, current);
            return;
        }
        visited.insert(current);
        for(int i = 0; i < current -> neighbor.size(); i++){
            if(visited.find(current -> neighbor[i]) != visited.end()) continue;
            double tentative_g_score = current -> g_score + getDistance(current, current -> neighbor[i], graph_distance);
            if(!isInTree(openset, current -> neighbor[i]) || tentative_g_score < current -> neighbor[i] -> g_score){
                came_from[current -> neighbor[i]] = current;
                current -> neighbor[i] -> g_score = tentative_g_score;
                current -> neighbor[i] -> f_score = current -> neighbor[i] -> g_score + current -> neighbor[i] -> estimate;
                if(!isInTree(openset, current -> neighbor[i])) minHeapInsert(openset, current -> neighbor[i], HEAP_F_SCORE);

            }
        }
    }
    cout<<"Can't find the second input node..."<<endl;
}







