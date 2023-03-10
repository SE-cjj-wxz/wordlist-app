#include "core.h"

void convert(char* result[], vector<string> resultBuf) {
    for (int i = 0; i < resultBuf.size(); i++) {
        result[i] = (char*)malloc(sizeof(char) * resultBuf[i].size());
        for (int j = 0; j < resultBuf[i].size(); j++) {
            result[i][j] = resultBuf[i][j];
        }
    }
}

int countChains(char** words, int length, char* result[]) {
    Graph graph(words, length);
    vector<string> resultBuf;
    graph.countChains(resultBuf);
    convert(result, resultBuf);
    return resultBuf.size(); 
}

int getLongestWordChain(char** words, int length, char* result[], char head, 
                        char tail, char ban, bool allow_circle) {
    return 0;
}

int getLongestCharChain(char** words, int length, char* result[], char head, 
                        char tail, char ban, bool allow_circle) {
    return 0;
}