#ifndef __EDGE_H__
#define __EDGE_H__

#include <string>
using namespace std; 

class Edge {
public:
    string word;
    int value;
    char to;

    explicit Edge(string w, int v, char t): word(w), value(v), to(t) {}
    
    bool isCircle() {
        return word.at(0) == word.at(word.size() - 1);  
    }
};

#endif 