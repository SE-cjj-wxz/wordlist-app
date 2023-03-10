#ifndef __NODE_H__
#define __NODE_H__

#include "edge.h"
#include <vector> 

#define WHITE 0
#define GRAY 1
#define BLACK 2

class Node {
public: 
    int color;
    int degree;
    vector<string> circle;
    int value;
    vector<Edge> edges;
    vector<string> result;

    explicit Node();
    void addEdge(Edge e);
    
    void mergeResult(vector<Node>::iterator, Edge);
    void countSelfCircle(); // deal self circle
    void removeSingleChain();
};


#endif 