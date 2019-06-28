#include "game.h"
#include <set>
using namespace std;

set<int> S[1505];

void initialize(int n) {
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) if(i != j) {
        S[i].emplace(j);
    }
}

int hasEdge(int u, int v) {
    bool st = false;
    if(S[u].count(v)) S[u].erase(v);
    else st = true;
    if(S[v].count(u)) S[v].erase(u);
    else st = true;
    if(S[u].size() == 1) {
        int a = *S[u].begin();
        S[a].erase(u);
    } 
    if(S[v].size() == 1) {
        int a = *S[v].begin();
        S[a].erase(v);
    }
    return st;
}
