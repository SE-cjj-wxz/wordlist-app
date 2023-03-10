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

    int maxLen = -1;
    vector<Node>::iterator node;

    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        if (it->value > maxLen) {
            maxLen = it->value;
            node = it;
        }
    }

    while (node->prev) {
        resultBuf.insert(resultBuf.end(), node->circle.begin(), node->circle.end());
        resultBuf.push_back(node->prev->word);
        node = node->prev->word.at(0) - 'a' + nodes.begin();
    }
    resultBuf.insert(resultBuf.end(), node->circle.begin(), node->circle.end());
    
    reverse(resultBuf.begin(), resultBuf.end());
}

void Graph::regularValue() {
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        it->circleValue = it->circle.size();
        for (auto e = it->edges.begin(); e != it->edges.end(); e++) {
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
    
    vector<int> SCC; 
    cleanColor();
    for (int i = order.size() - 1; i >= 0; i--) {
        if (nodes[order[i]].color == WHITE) {
            dfsOrder(order[i], SCC);
            SCCs.push_back(SCC);
            SCC.clear();
        }
    }

    // for (auto scc = SCCs.begin(); scc != SCCs.end(); scc++) {
    //     for (auto i = scc->begin(); i != scc->end(); i++) {
    //         cout << char(*i + 'a') << " ";
    //     }
    //     cout << endl;
    // }
}