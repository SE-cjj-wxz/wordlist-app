#include "graph.h"

Graph::Graph(char* words[], int len) {
    for (int i = 0; i < 26; i++) {
        Node node('a' + i);
        nodes.push_back(node);
    }

    for (int i = 0; i < len; i++) {
        string word = words[i]; 
        Edge edge(word, word.size(), word.at(word.size()-1));
        nodes[word.at(0) - 'a'].addEdge(edge);
    }
}

bool Graph::hasCircle() {
    bool circle = false; 
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].circle > 1) {
            return true;
        }
        if (nodes[i].color == WHITE) {
            dfsCircle(i, circle);
        }
    }
    return circle;
}

void Graph::dfsCircle(int u, bool& circle) {
    nodes[u].color = GRAY;
    for (auto e = nodes[u].edges.begin(); e != nodes[u].edges.end(); e++) {
        int v = e->to - 'a';
        if (nodes[v].color == GRAY) {
            circle = true; 
        } else if (nodes[v].color == WHITE) {
            dfsCircle(v, circle);
        }
    }
    nodes[u].color = BLACK; 
}