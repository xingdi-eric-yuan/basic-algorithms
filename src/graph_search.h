#pragma once
#include "general_settings.h"

using namespace std;


void Dijkstra(GraphNode*, const unordered_map<string, double> &);

double getDijkstraDistance(GraphNode*, GraphNode*, const unordered_map<string, double>&);


void reconstruct_path(unordered_map<GraphNode*, GraphNode*> &, GraphNode* );

void A_star(GraphNode *, GraphNode *, const unordered_map<string, double> &);






