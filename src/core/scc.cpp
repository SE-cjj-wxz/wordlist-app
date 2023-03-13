#include "scc.h"
#include <iostream>

SCC::SCC(vector<int>& indices, vector<Node>& gNodes) {
    for (int i = 0; i < indices.size(); i++) {
        Node node;
        nodes.push_back(node);
        node.circle = gNodes[i].circle;
        node.circleValue = gNodes[i].circleValue;
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

void SCC::print() {
    for (int i = 0; i < nodes.size(); i++) {
        cout << char(indices[i] + 'a') << ": ";
        for (auto e = nodes[i].edges.begin(); e != nodes[i].edges.end(); e++) {
            cout << char(indices[e->to] + 'a') << " ";
        }
        cout << endl;
    }
}

void SCC::getLongestDist() {
    for (int i = 0; i < nodes.size(); i++) {
        vector<string> path;
        dfs(i, i, path, 0); 
    }
}

void SCC::dfs(int u, int root, vector<string>& path, int value) {
    // cout << char(indices[u]+'a') << " " << char(indices[root]+'a') << " " << value << endl;
    for (auto e = nodes[u].circle.begin(); e != nodes[u].circle.end(); e++) {
        path.push_back(e->word);
        value += e->value; 
    }

    if (value > pathValue[root][u]) {
        pathValue[root][u] = value;
        this->path[root][u] = path; 
    }

    if (u+'a' == 't' && u == root) {
        cout << pathValue[u][root] << endl;
    }

    for (auto e = nodes[u].edges.begin(); e != nodes[u].edges.end(); e++) {
        int v = e->to;
        if (e->color == WHITE) {
            e->color = GRAY;
            path.push_back(e->word);
            dfs(v, root, path, value + e->value);
            e->color = WHITE;
            path.pop_back();
        }
    }
    for (auto e = nodes[u].circle.begin(); e != nodes[u].circle.end(); e++) {
        path.pop_back();
        value -= e->value; 
    }
}

