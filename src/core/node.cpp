#include "node.h"

Node::Node(char c) {
    ch = c;
    color = WHITE;
    degree = 0;
    int value = 0;
}

void Node::addEdge(Edge e) {
    if (e.isCircle()) {
        circle++;
        value += e.word.size();
    } else {
        edges.push_back(e); 
    }
}