#include "robots.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int INF = 1e6+1;
const int INF2 = 2e9+1;

int A, B, T, *X, *Y;
vector<pii> V;

bool can(int m) {
    priority_queue<int> Q;
    int p = 0;
    for(int i = 0; i < A; ++i) {
        for(; p < T and V[p].x < X[i]; p++) Q.emplace(V[p].y);
        for(int j = 0; !Q.empty() && j < m; ++j) Q.pop();
    }
    for(; p < T; ++p) Q.emplace(V[p].y);
    for(int i = B - 1; ~i; --i) {
        if(!Q.empty() && Q.top() >= Y[i]) return false;
        for(int j = 0; !Q.empty() && j < m; ++j) Q.pop();
    }
    return Q.empty();
}

int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {
    sort(X, X + A), sort(Y, Y + B);
    ::A = A, ::B = B, ::T = T, ::X = X, ::Y = Y;
    for(int i = 0; i < T; ++i) V.emplace_back(W[i], S[i]);
    sort(V.begin(), V.end());
    int l = 1, r = 1e6+1;
    while(l < r) {
        int m = l + r >> 1;
        if(can(m)) r = m;
        else l = m+1;
    }
    return can(r) ? r : -1;
}
