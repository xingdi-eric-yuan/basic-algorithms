#pragma once
#include "general_settings.h"

using namespace std;

void printArray(const vector<double>&);

int partition(vector<double>&, int, int);

void quickSort(vector<double>&, int, int);

void merge(vector<double>&, int, int, int);

void mergeSort(vector<double>&, int, int);

double quickSelect(vector<double>&, int, int, int);

void rightRotate(vector<double>&, int);

void leftRotate(vector<double>&, int);

int binarySearch(vector<double>&, int, int, double);

int generalBinarySearch(vector<double>&, int, int, double);