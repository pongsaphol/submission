#include "game.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 1500;

int n;
int par[N];
int adj[N][N];

int find(int u) { return par[u] = par[u] == u ? u : find(par[u]); }

void initialize(int n) {
    iota(par, par+N, 0), ::n = n;
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) if(i != j) adj[i][j] = 1;
}

int hasEdge(int u, int v) {
    u = find(u), v = find(v);
    assert(u != v);
    if(adj[u][v] == 1) {
        adj[u][v] = adj[v][u] = 0;
        par[v] = u;
        for(int i = 0; i < n; ++i) adj[u][i] += adj[v][i], adj[v][i] = 0;
        for(int i = 0; i < n; ++i) if(par[i] == i && i != u) adj[i][u] += adj[i][v], adj[i][v] = 0;
        return 1;
    } else {
        adj[u][v]--, adj[v][u]--;
        return 0;
    }
}
