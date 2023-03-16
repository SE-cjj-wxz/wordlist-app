#include "scc.h"
#include <iostream>

SCC::SCC(vector<int>& indices, vector<Node>& gNodes) {
    for (int i = 0; i < indices.size(); i++) {
        Node node;
        node.circle = gNodes[i].circle;
        node.circleValue = gNodes[i].circleValue;
        nodes.push_back(node);
        this->indices = indices;
    }
    for (int i = 0; i < gNodes.size(); i++) {
        for (auto e = gNodes[i].edges.begin(); e != gNodes[i].edges.end(); e++) {
            Edge edge(e->word);
            edge.value = e->value;
            for (int j = 0; j < indices.size(); j++) {
                if (indices[j] == e->to) {
                    edge.to = j;
                    nodes[i].addEdge(edge);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            pathValue[i][j] = 0; 
        }
    }
    // if (nodes.size() > 1) {
    //     print(); 
    // }
}

void SCC::getLongestDist() {
    for (int i = 0; i < nodes.size(); i++) {
        vector<string> path;
        vector<bool> vis(nodes.size(), false);
        dfs(i, i, path, vis, 0); 
    }
}

void SCC::dfs(int u, int root, vector<string>& path, vector<bool>& vis, int value) {
    bool flag = false;
    if (!vis[u]) {
        vis[u] = 1;
        flag = true;
        for (auto e = nodes[u].circle.begin(); e != nodes[u].circle.end(); e++) {
            path.push_back(e->word);
        }
        value += nodes[u].circleValue;
    }

    if (value > pathValue[root][u]) {
        pathValue[root][u] = value;
        this->path[root][u] = path; 
    }

    for (auto e = nodes[u].edges.begin(); e != nodes[u].edges.end(); e++) {
        int v = e->to;
        if (e->color == WHITE) {
            e->color = GRAY;
            path.push_back(e->word);
            dfs(v, root, path, vis, value + e->value);
            e->color = WHITE;
            path.pop_back();
        }
    }
    if (flag) {
        for (auto e = nodes[u].circle.begin(); e != nodes[u].circle.end(); e++) {
            path.pop_back();
        }
        value -= nodes[u].circleValue; 
        vis[u] = 0; 
    }
}

