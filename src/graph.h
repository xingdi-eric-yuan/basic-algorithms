#pragma once
#include "general_settings.h"

using namespace std;

void concatenate(GraphNode*, GraphNode*, unordered_map<string, int> &, int);

int getDistance(GraphNode*, GraphNode*, unordered_map<string, int> &);

void printGraphBFS(GraphNode*);

void printGraphDFS(GraphNode*);

