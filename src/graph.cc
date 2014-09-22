
#include "graph.h"
using namespace std;

void concatenate(GraphNode *a, GraphNode *b, unordered_map<string, int> &graph_distance, int distance){

    a -> neighbor.push_back(b);
    b -> neighbor.push_back(a);
    string str = to_string(a -> id) + '-' + to_string(b -> id);
    unordered_map<string, int>::const_iterator got = graph_distance.find (str);
    if(got == graph_distance.end()){
        graph_distance[str] = distance;
    }
}

int getDistance(GraphNode *a, GraphNode *b, unordered_map<string, int> &graph_distance){
    int res = INT_MAX;
    string str = to_string(a -> id) + '-' + to_string(b -> id);
    unordered_map<string, int>::const_iterator got = graph_distance.find (str);
    if(got != graph_distance.end()) res = graph_distance.at(str);
    else{
        str = to_string(b -> id) + '-' + to_string(a -> id);
        got = graph_distance.find(str);
        if(got != graph_distance.end()) res = graph_distance.at(str);
    }
    return res;
}

void printGraphBFS(GraphNode *a){
    if(!a) return;
    unordered_set<int> black;
    unordered_set<int> gray;
    queue<GraphNode*> Q;
    Q.push(a);
    while(1){
        if(Q.empty()) break;
        GraphNode* p = Q.front();
        Q.pop();
        gray.insert(p -> id);
        cout<<"Here comes node id "<<p -> id<<", val = "<<p -> val<<", range = "<<p -> range<<endl;
        for(int i = 0; i < p -> neighbor.size(); i++){
            if( black.find(p -> neighbor[i] -> id) == black.end() &&
                gray.find(p -> neighbor[i] -> id) == gray.end() ){ 
                Q.push(p -> neighbor[i]);
                gray.insert(p -> neighbor[i] -> id);
            }
        }
        black.insert(p -> id);
    }
}

void printGraphDFS(GraphNode *a){
    if(!a) return;
    unordered_set<int> black;
    stack<GraphNode*> S;
    S.push(a);
    while(!S.empty()){
        while(!S.empty() && black.find(S.top() -> id) != black.end()) S.pop();
        if(S.empty()) break;
        GraphNode* p = S.top();
        S.pop();
        cout<<"Here comes node id "<<p -> id<<", val = "<<p -> val<<", range = "<<p -> range<<endl;
        for(int i = 0; i < p -> neighbor.size(); i++){
            S.push(p -> neighbor[i]);
        }
        black.insert(p -> id);
    }
}
