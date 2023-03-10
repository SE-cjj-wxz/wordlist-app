#include "scc.h"

SCC::SCC(vector<int>& indices, vector<Node>& gNodes) {
    for (int i = 0; i < indices.size(); i++) {
        Node node;
        nodes.push_back(node);
        node.circle = gNodes[i].circle;
        node.circleValue = gNodes[i].circleValue;
        map[indices[i]] = i;
    }
    for (int i = 0; i < gNodes.size(); i++) {
        for (auto e = gNodes[i].edges.begin(); e != gNodes[i].edges.end(); e++) {
            Edge edge(e->word);
            edge.value = e->value;
            edge.to = map[e->to];
        }
    }
}