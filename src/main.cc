
#include "general_settings.h"
using namespace std;

int main(){

    unordered_map<string, double> graph_distance;

    GraphNode a(0, 0, INT_MAX, 4);
    GraphNode b(1, 1, INT_MAX, 2);
    GraphNode c(2, 2, INT_MAX, 4);
    GraphNode d(3, 3, INT_MAX, 4.5);
    GraphNode e(4, 4, INT_MAX, 2);
    GraphNode f(5, 5, INT_MAX, INT_MAX);
    GraphNode g(6, 6, INT_MAX, INT_MAX);

    concatenate(&f, &a, graph_distance, 1.5);
    concatenate(&a, &b, graph_distance, 2);
    concatenate(&b, &c, graph_distance, 3);
    concatenate(&c, &g, graph_distance, 4);
    concatenate(&f, &d, graph_distance, 2);
    concatenate(&d, &e, graph_distance, 3);
    concatenate(&e, &g, graph_distance, 2);

    //double dis = getDijkstraDistance(&a, &e, graph_distance);
    //cout<<"dis = "<<dis<<endl;
    //printGraphDFS(&a);
    A_star(&f, &g, graph_distance);

    graph_distance.clear();
	return 0;
}







