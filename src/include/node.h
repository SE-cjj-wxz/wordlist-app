#ifndef __NODE_H__
#define __NODE_H__

#include "edge.h"
#include <vector> 

#define WHITE 0
#define GRAY 1
#define BLACK 2

class Node {
public: 
    char ch; 
    int color;
    int degree;
    int circle;
    int value;
    vector<Edge> edges;
    vector<string> result;

    explicit Node(char c);
    void addEdge(Edge e);
};


#endif 