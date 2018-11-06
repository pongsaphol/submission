/*
First, I can think case build complete binary tree
but it use 2*N node on case N = 2^i + 1
I observaton for some node is can delete
and the edge back to root of tree
*/
#include "doll.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 3e5+5;

vector<int> A, X, Y;
int M, ptr = 1;
pii g[N];
bool state[N];

void solve(int p, int l, int r) {
    int m = (l + r) >> 1;
    if(l + 1 == r) {
        if(M <= m) g[p].x = 1;
        return;
    }
    g[p].y = ++ptr;
    solve(ptr, l, m);
    if(M > m) {
        g[p].x = ++ptr;
        solve(ptr, m+1, r);
    } else {
        g[p].x = 1;
    }
}

void dfs(int p, int v) {
    state[p] ^= 1;
    if(!state[p]) {
        if(g[p].y) dfs(g[p].y, v);
        else g[p].y = v;
    } else {
        if(g[p].x) dfs(g[p].x, v);
        else g[p].x = v;
    }
}

void create_circuit(int M, vector<int> A) {
    vector<int> C;
    C.emplace_back(A[0]);
    for(int i = 1; i <= M; ++i) C.emplace_back(-1);
    ::A = A;
    ::M = A.size();
    A.emplace_back(0);
    int z = 1;
    while(z * 2 <= ::M-1) z *= 2;
    z *= 2;
    solve(1, 1, z);
    for(int i = 1; i <= ::M; ++i) dfs(1, -A[i]);
    for(int i = 1; i <= ptr; ++i) X.emplace_back(-g[i].x), Y.emplace_back(-g[i].y);
    answer(C, X, Y);
}
