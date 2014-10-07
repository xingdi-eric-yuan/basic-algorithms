#pragma once
#include "general_settings.h"

using namespace std;

void concatenate(GraphNode*, GraphNode*, unordered_map<string, double> &, double);

double getDistance(GraphNode*, GraphNode*, const unordered_map<string, double> &);

void printGraphBFS(GraphNode*);

void printGraphDFS(GraphNode*);

