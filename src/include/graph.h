#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include "node.h"
#include <string.h>
#include <queue>
#include <iostream>
using namespace std; 

class Graph {
public:
    explicit Graph(char* words[], int len);
    bool hasCircle();
    void dfsCircle(int, bool&);
    void countChains(vector<string>& resultBuf);

private:
    vector<Node> nodes;
};

#endif