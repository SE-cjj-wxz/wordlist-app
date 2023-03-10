#include "scc.h"

SCC::SCC(vector<int>& indices, vector<Node>& gNodes) {
    for (int i = 0; i < indices.size(); i++) {
        Node node;
        nodes.push_back(node);
        node.circle = gNodes[i].circle;
        node.circleValue = gNodes[i].circleValue;
        map[indices[i]] = i;
        this->indices = indices;
    }
    for (int i = 0; i < gNodes.size(); i++) {
        for (auto e = gNodes[i].edges.begin(); e != gNodes[i].edges.end(); e++) {
            Edge edge(e->word);
            edge.value = e->value;
            edge.to = map[e->to];
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            pathValue[i][j] = 0; 
        }
    }
}

void SCC::getLongestDist() {
    for (int i = 0; i < nodes.size(); i++) {
        vector<vector<Edge>::iterator> path;
        dfs(i, i, path, 0); 
    }
}

void SCC::dfs(int u, int root, vector<vector<Edge>::iterator>& path, int value) {
    for (auto e = nodes[u].circle.begin(); e != nodes[u].circle.end(); e++) {
        path.push_back(e);
        value += e->value; 
    }
    if (value > pathValue[root][u]) {
        pathValue[root][u] = value;
        this->path[root][u] = path;
    }
    for (auto e = nodes[u].edges.begin(); e != nodes[u].edges.end(); e++) {
        int v = e->to;
        if (e->color == WHITE) {
            e->color = GRAY;
            path.push_back(e);
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

