#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include "node.h"
#include <string.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std; 

class Graph {
public:
    explicit Graph(char* words[], int len);
    void countChains(vector<string>& resultBuf);

    bool hasCircle();
    void dfsCircle(int, bool&);
    void removeEdgeByHead(int u);
    void initNodeValue(char head);
    void getLongestChain(vector<string>& resultBuf, char head, char tail, char ban, bool allow_circle);

    void regularValue();

private:
    vector<Node> nodes;
};

#endif