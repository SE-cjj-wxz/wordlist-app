#include "node.h"

Node::Node() {
    color = WHITE;
    degree = 0;
    value = 0;
    circleValue = 0;
    prev = 0;
}

void Node::addEdge(Edge e) {
    if (e.isCircle()) {
        circle.push_back(e);
        circleValue += e.word.size();
    } else {
        edges.push_back(e); 
    }
}

void Node::mergeResult(vector<Node>::iterator other, Edge e) {
    for (int i = 0; i < other->result.size(); i++) {
        this->result.push_back(other->result[i] + " " + e.word);
    }
    this->result.push_back(e.word);
}

void Node::countSelfCircle() {
    vector<string> tmp;
    for (auto s = circle.begin(); s != circle.end(); s++) {
        for (auto r = result.begin(); r != result.end(); r++) {
            tmp.push_back(*r + " " + s->word);
        }
    }

    result.insert(result.end(), tmp.begin(), tmp.end());
    
    for (auto s = circle.begin(); s != circle.end(); s++) {
        result.push_back(s->word);
    }
}

void Node::removeSingleChain() {
    for (auto r = result.begin(); r != result.end(); ) {
        bool flag = false;
        for (int i = 0; i < r->size(); i++) {
            if (r->at(i) == ' ') {
                flag = true;
                break;
            }
        }
        if (!flag) {
            result.erase(r);
        } else {
            r++;
        }
    }
}