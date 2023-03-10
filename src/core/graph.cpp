#include "graph.h"

Graph::Graph(char* words[], int len) {
    for (int i = 0; i < 26; i++) {
        Node node;
        nodes.push_back(node);
    }

    for (int i = 0; i < len; i++) {
        string word = words[i]; 
        Edge edge(word);
        if (!edge.isCircle()) {
            nodes[edge.to].degree++;
        }
        nodes[word.at(0) - 'a'].addEdge(edge);
    }
}

bool Graph::hasCircle() {
    bool circle = false; 
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i].circle.size() > 1) {
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
        int v = e->to;
        if (nodes[v].color == GRAY) {
            circle = true; 
        } else if (nodes[v].color == WHITE) {
            dfsCircle(v, circle);
        }
    }
    nodes[u].color = BLACK; 
}

void Graph::countChains(vector<string>& resultBuf) {
    queue< vector<Node>::iterator > q;
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        if (it->degree == 0) {
            it->countSelfCircle();
            q.push(it);
        }
    }

    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        for (auto e = node->edges.begin(); e != node->edges.end(); e++) {
            nodes[e->to].degree--;
            nodes[e->to].mergeResult(node, *e);
            if (nodes[e->to].degree == 0) { 
                nodes[e->to].countSelfCircle();
                q.push(nodes.begin() + e->to);
            }
        }
    }

    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        it->removeSingleChain();
        resultBuf.insert(resultBuf.end(), it->result.begin(), it->result.end());
    }
}