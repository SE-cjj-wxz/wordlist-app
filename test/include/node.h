#ifndef __NODE_H__
#define __NODE_H__

#include "edge.h"
#include <vector> 

class Node {
public: 
    int color;
    int degree;
    int circleValue;
    int value;
    Edge* prev;
    int preNode;
    vector<Edge> circle;
    vector<Edge> edges;
    vector<string> result;

    explicit Node();
    void addEdge(Edge e);
    
    void mergeResult(vector<Node>::iterator, Edge);
    void countSelfCircle(); // deal self circle
    void removeSingleChain();
};


#endif 