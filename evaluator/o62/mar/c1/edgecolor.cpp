#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1005;

int n, m;
set<pii> S;
int par[N], sz[N];

int find(int u) { return par[u] = par[u] == u ? u : find(par[u]); }

bool check() {
    iota(par, par+N, 0);
    fill_n(sz, N, 1);
    for(auto x : S) {
        int a = find(x.x), b = find(x.y);
        if(a != b) par[a] = b, sz[b] += sz[a];
        else if(sz[b] & 1) return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1, t, u, v; i <= m; ++i) {
        scanf("%d %d %d", &t, &u, &v);
        if(u > v) swap(u, v);
        if(t) S.emplace(pii(u, v));
        else S.erase(pii(u, v));
        puts(check() ? "yes" : "no");
    }
}
