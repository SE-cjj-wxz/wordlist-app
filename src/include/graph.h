#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include "node.h"
#include <string.h>
#include <queue>
using namespace std; 

class Graph {
public:
    explicit Graph(char* words[], int len);
    bool hasCircle();
    void dfsCircle(int, bool&);

private:
    vector<Node> nodes;
};

#endif