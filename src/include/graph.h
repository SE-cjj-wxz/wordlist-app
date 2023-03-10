#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include "node.h"
#include <string.h>
#include <queue>
#include <iostream>
#include <algorithm>
#include "scc.h"
using namespace std; 

class Graph {
public:
    explicit Graph(char* words[], int len);
    explicit Graph(int n);
    void countChains(vector<string>& resultBuf);

    bool hasCircle();
    void dfsCircle(int, bool&);
    void removeEdgeByHead(int u);
    void initNodeValue(char head);
    void getLongestChain(vector<string>& resultBuf, char head, char tail, char ban, bool allow_circle);

    void regularValue();

    void cleanColor(); 
    void reverseGraph(Graph& graph);
    void dfsOrder(int u, vector<int>& order);
    void getSCC();
    void getLongestChainOnCircle(vector<string>& resultBuf, char head, char tail, char ban);
    void addSCCPath(vector<string>& resultBuf, int u, int v);

private:
    vector<Node> nodes;
    vector<SCC> SCCs;
};

#endif