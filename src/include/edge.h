#ifndef __EDGE_H__
#define __EDGE_H__

#include <string>
using namespace std; 

class Edge {
private:
    string word;
    int value;
    char to;
public:
    Edge(string w, int v, char t): word(w), value(v), to(t) {}
};

#endif 