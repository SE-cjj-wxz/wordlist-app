#ifndef __SCC_H__
#define __SCC_H__

#include "node.h"

class SCC {
public:
    vector<Node> nodes;
    vector<int> indices; // map Graph node to SCC node
    vector<Edge*> path[30][30];
    int pathValue[30][30];
    
    explicit SCC(vector<int>& indices, vector<Node>& gNodes);
    void getLongestDist();
    void dfs(int u, int root, vector<Edge*>& path, vector<bool>& vis, vector<bool>& edgeVis, int value);
};

#endif