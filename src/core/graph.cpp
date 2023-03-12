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

Graph::Graph(int n) {
    for (int i = 0; i < n; i++) {
        Node node;
        nodes.push_back(node);
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

void Graph::removeEdgeByHead(int u) {
    for (auto e = nodes[u].edges.begin(); e != nodes[u].edges.end(); e++) {
        nodes[e->to].degree--;
    }
    nodes[u].edges.clear(); 
    nodes[u].circle.clear();
    nodes[u].value = 0;
    nodes[u].circleValue = 0;
}

void Graph::initNodeValue(char head) {
    if (head == '\0') {
        for (int i = 0; i < nodes.size(); i++) {
            nodes[i].value = 0;
        }
    } else {
        for (int i = 0; i < nodes.size(); i++) {
            if (i == head - 'a') {
                nodes[i].value = 0;
            } else {
                nodes[i].value = -1; 
            }
        }
    }
}

void Graph::getLongestChain(vector<string>& resultBuf, char head, char tail, char ban, bool allow_circle) {
    if (!allow_circle && hasCircle()) {
        throw exception(); // illegal circle
    }
    if (ban != '\0') {
        removeEdgeByHead(ban - 'a');
    }
    initNodeValue(head); //deal -h 

    queue< vector<Node>::iterator > q;
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        if (it->degree == 0) {
            if (it->value >= 0) {
                it->value += it->circleValue;
            }
            q.push(it);
        }
    }

    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        for (auto e = node->edges.begin(); e != node->edges.end(); e++) {
            int v = e->to;
            nodes[v].degree--;
            if (node->value >= 0 && node->value + e->value > nodes[v].value) {
                nodes[v].value = node->value + e->value;
                nodes[v].prev = &(*e);
            }
            if (nodes[v].degree == 0) { 
                if (nodes[v].value >= 0) {
                    nodes[v].value += nodes[v].circleValue;
                }
                q.push(nodes.begin() + v);
            }
        }
    }    

    int maxLen = 0;
    vector<Node>::iterator node;

    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        if (tail != '\0' && tail != it - nodes.begin() + 'a') {
            continue;
        }
        if (it->value > maxLen) {
            maxLen = it->value;
            node = it;
        }
    }

    while (node->prev) {
        for (auto e = node->circle.begin(); e != node->circle.end(); e++) {
            resultBuf.push_back(e->word);
        }
        resultBuf.push_back(node->prev->word);
        node = node->prev->word.at(0) - 'a' + nodes.begin();
    }
    for (auto e = node->circle.begin(); e != node->circle.end(); e++) {
        resultBuf.push_back(e->word);
    }
    
    reverse(resultBuf.begin(), resultBuf.end());
}

void Graph::regularValue() {
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        it->circleValue = it->circle.size();
        for (auto e = it->edges.begin(); e != it->edges.end(); e++) {
            e->value = 1;
        }
        for (auto e = it->circle.begin(); e != it->circle.end(); e++) {
            e->value = 1;
        }
    }
}

void Graph::cleanColor() {
    for (auto node = nodes.begin(); node != nodes.end(); node++) {
        node->color = WHITE;  
    }
}

void Graph::reverseGraph(Graph& graph) {
    for (auto node = graph.nodes.begin(); node != graph.nodes.end(); node++) {
        for (auto e = node->edges.begin(); e != node->edges.end(); e++) {
            string word = e->word;
            reverse(word.begin(), word.end());
            Edge edge(word);
            this->nodes[word.at(0) - 'a'].addEdge(edge);
        }
    }
}

void Graph::dfsOrder(int u, vector<int>& order) {
    nodes[u].color = GRAY;
    for (auto e = nodes[u].edges.begin(); e != nodes[u].edges.end(); e++) {
        int v = e->to;
        if (nodes[v].color == WHITE) {
            dfsOrder(v, order); 
        }
    }
    order.push_back(u);
}

void Graph::getSCC() {
    Graph rGraph(26);
    rGraph.reverseGraph(*this);
    vector<int> order;
    for (auto node = rGraph.nodes.begin(); node != rGraph.nodes.end(); node++) {
        if (node->color == WHITE) {
            rGraph.dfsOrder(node - rGraph.nodes.begin(), order);
        }
    }
    
    vector<int> indices;
    vector<Node> gNodes;
    cleanColor();
    for (int i = order.size() - 1; i >= 0; i--) {
        if (nodes[order[i]].color == WHITE) {
            dfsOrder(order[i], indices);
            for (int j = 0; j < indices.size(); j++) {
                gNodes.push_back(nodes[indices[j]]);
            }
            SCC scc(indices, gNodes);
            SCCs.push_back(scc); 
            indices.clear();
            gNodes.clear();
        }
    }
}

void Graph::getLongestChainOnCircle(vector<string>& resultBuf, char head, char tail, char ban) {
    if (ban != '\0') {
        removeEdgeByHead(ban - 'a');
    }
    initNodeValue(head); //deal -h 

    getSCC();

    for (auto scc = SCCs.begin(); scc != SCCs.end(); scc++) {
        scc->getLongestDist();
    }

    reverse(SCCs.begin(), SCCs.end());  //toposort

    for (auto scc = SCCs.begin(); scc != SCCs.end(); scc++) {
        vector<int> tempValue;
        for (int i = 0; i < scc->indices.size(); i++) {
            tempValue.push_back(nodes[scc->indices[i]].value);
        }
        for (int i = 0; i < scc->indices.size(); i++) {
            int v = scc->indices[i];
            int maxu = -1;
            for (int j = 0; j < scc->indices.size(); j++) {
                int u = scc->indices[j];
                if (tempValue[j] >= 0 && tempValue[j] + scc->pathValue[u][v] > nodes[v].value) {
                    nodes[v].value = tempValue[j] + scc->pathValue[u][v];
                    maxu = u;
                }
            }
            if (maxu >= 0) {
                nodes[v].result = nodes[maxu].result;
                nodes[v].result.insert(nodes[v].result.end(), scc->path[maxu][v].begin(), scc->path[maxu][v].end());
            }
        }
        for (int i = 0; i < scc->indices.size(); i++) {
            int u = scc->indices[i];
            for (auto e = nodes[u].edges.begin(); e != nodes[u].edges.end(); e++) {
                int v = e->to;
                if (find(scc->indices.begin(), scc->indices.end(), v) == scc->indices.end()) {
                    if (nodes[u].value >= 0 && nodes[u].value + e->value > nodes[v].value) {
                        nodes[v].value = nodes[u].value + e->value;
                        nodes[v].result = nodes[u].result;
                        nodes[v].result.push_back(e->word);
                    }
                }
            }
        }
    }

    int maxLen = 0;
    vector<Node>::iterator node;

    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        if (tail != '\0' && tail != it - nodes.begin() + 'a') {
            continue;
        }
        if (it->value > maxLen) {
            maxLen = it->value;
            node = it;
        }
    }

    resultBuf = node->result; 
}