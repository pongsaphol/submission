/*
    Model to tree structure
    find max dep of subtree that max{A(L), ..., A(R-1)} < R and track it
*/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1<<17;

struct node {
    int mx, argmx;
    vector<int> son;
};


int n, r, t[N], idx[N];
node g[N<<1];

void update(int x) {
    if(x <= n) t[x]--, update(x + (x & -x));
}

int query(int x) {
    return t[x] + (x ? query(x - (x & -x)) : 0);
}

int get(int x) {
    int l = 1, r = n;
    while(l < r) {
        int m = (l + r) >> 1;
        if(query(m) >= x) r = m;
        else l = m + 1;
    }
    return r;
}

int mx, argmx;
int mxq[N<<1];

int query(int l, int r) {
    int mx = 0;
    for(l += N, r += N+1; l < r; l >>= 1, r >>= 1) {
        if(l & 1) mx = max(mx, mxq[l++]);
        if(r & 1) mx = max(mx, mxq[--r]);
    }
    return mx;
}

pii dfs(int u) {
    if(g[u].son.empty()) return pii(g[u].argmx, g[u].argmx);
    int l = n+1, r = 0;
    g[u].argmx = N;
    for(int v : g[u].son) {
        pii now = dfs(v);
        l = min(l, now.x), r = max(r, now.y);
        if(g[v].mx > g[u].mx) g[u].mx = g[v].mx, g[u].argmx = N;
        if(g[v].mx == g[u].mx && g[v].argmx < g[u].argmx) g[u].argmx = g[v].argmx;
    }
    g[u].mx++;
    if(query(l, r-1) < ::r) {
        if(g[u].mx > mx) mx = g[u].mx, argmx = N;
        if(g[u].mx == mx && g[u].argmx < argmx) argmx = g[u].argmx;
    }
    return pii(l, r);
}

int GetBestPosition(int N, int C, int R, int *K, int *S, int *E) {
    n = N, r = R;
    for(int i = 1; i <= N; ++i) t[i] = i & -i, idx[i] = i, g[i].argmx = i, mxq[i+::N] = K[i-1];

    for(int i = ::N-1; i >= 1; --i) mxq[i] = max(mxq[i<<1], mxq[i<<1|1]);
    for(int i = 1; i <= C; ++i) {
        int s = S[i-1] + 1, e = E[i-1] + 1;
        vector<int> vec;
        for(int i = s; i <= e; ++i) vec.emplace_back(get(i));
        for(int v : vec) {
            g[i + N].son.emplace_back(idx[v]);
            if(v != vec[0]) update(v);
        }
        idx[vec[0]] = i + N;
    }
    dfs(N+C);
    if(!argmx) argmx = 1;
    return argmx-1;
}
