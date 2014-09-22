
#include "general_settings.h"
using namespace std;

int main(){

    unordered_map<string, int> graph_distance;

    GraphNode a(0, 0, INT_MAX);
    GraphNode b(1, 1, INT_MAX);
    GraphNode c(2, 2, INT_MAX);
    GraphNode d(3, 3, INT_MAX);
    GraphNode e(4, 4, INT_MAX);
    GraphNode f(5, 5, INT_MAX);

    concatenate(&a, &b, graph_distance, 7);
    concatenate(&a, &f, graph_distance, 14);
    concatenate(&a, &c, graph_distance, 9);
    concatenate(&b, &c, graph_distance, 10);
    concatenate(&b, &d, graph_distance, 15);
    concatenate(&c, &d, graph_distance, 11);
    concatenate(&c, &f, graph_distance, 2);
    concatenate(&d, &e, graph_distance, 6);
    concatenate(&e, &f, graph_distance, 9);

    int dis = getDijkstraDistance(&a, &e, graph_distance);
//    cout<<"dis = "<<dis<<endl;
    printGraphDFS(&a);

	return 0;
}







