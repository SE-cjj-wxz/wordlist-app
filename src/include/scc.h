#ifndef __SCC_H__
#define __SCC_H__

#include "node.h"

class SCC {
public:
    vector<Node> nodes;
    int map[30]; // map SCC node to Graph node
    vector<string>* path[30][30];
    
    explicit SCC(vector<int>& indices, vector<Node>& gNodes);
};

#endif