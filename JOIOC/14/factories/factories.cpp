#include "factories.h"
#include <bits/stdc++.h>
using namespace std;

#define long long long
#define pii pair<int, int>
#define pll pair<long, long>
#define x first
#define y second

const int N = 5e5+5;

int dep[N], par[N], d[N];
long dis[N][20];
bool check[N];
vector<pii> g[N];
pll ans[N];


int find(int u, int p, int psz, pii &ret) {
    d[u] = 1;
    int mxsz = 0;
    for(auto v : g[u]) if(v.x != p and !check[v.x]) {
        int now = find(v.x, u, psz, ret);
        mxsz = max(mxsz, now);
        d[u] += now;
    }
    mxsz = max(mxsz, psz - d[u]);
    if(mxsz < ret.x) ret = pii(mxsz, u);
    return d[u];
}

void filldis(int u, int p, int ndep) {
    for(auto v : g[u]) if(v.x != p and !check[v.x]) dis[v.x][ndep] = dis[u][ndep] + v.y, filldis(v.x, u, ndep);
}

void centroid(int u, int p, int sz) {
    pii ret(sz, -1);
    find(u, u, sz, ret); 
    u = ret.y, dep[u] = dep[p] + 1, check[u] = true, par[u] = p;
    filldis(u, u, dep[u]); 
    for(auto v : g[u]) if(!check[v.x]) centroid(v.x, u, d[v.x] > d[u] ? sz - d[u] : d[v.x]);
}

void Init(int N, int A[], int B[], int D[]) {
    for(int i = 0; i < N-1; ++i) A[i]++, B[i]++;
    for(int i = 0; i < N-1; ++i) g[A[i]].emplace_back(B[i], D[i]), g[B[i]].emplace_back(A[i], D[i]);
    centroid(1, 0, N);
}

int step = 0;

long Query(int S, int X[], int T, int Y[]) {
    step++;
    for(int i = 0; i < S; ++i) {
        int now = X[i]+1;
        for(int j = now; j; j = par[j]) {
            if(ans[j].y != step) ans[j] = pll(1e18, step);
            ans[j].x = min(ans[j].x, dis[now][dep[j]]);
        }
    }
    long mn = 1e18;
    for(int i = 0; i < T; ++i) {
        int now = Y[i]+1;
        for(int j = now; j; j = par[j]) {
            if(ans[j].y != step) continue;
            mn = min(mn, ans[j].x + dis[now][dep[j]]);
        }
    }
    return mn;
}
