#ifndef __EDGE_H__
#define __EDGE_H__

#include <string>
using namespace std; 

#define WHITE 0
#define GRAY 1
#define BLACK 2

class Edge {
public:
    string word;
    int value;
    int to;
    int color;

    explicit Edge(string w): word(w) {
        value = word.size();
        to = word.at(value - 1) - 'a';
        color = WHITE;
    }
    
    bool isCircle() {
        return word.at(0) == word.at(word.size() - 1);  
    }
};

#endif 