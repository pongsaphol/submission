#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, m, sz[N], par[N];

int find(int u) { return par[u] = par[u] == u ? u : find(par[u]); }

int main() {
    iota(par, par + N, 0);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", sz+i);
    for(int i = 0, a, b; i < m; ++i) {
        scanf("%d %d", &a, &b);
        bool st;
        a = find(a), b = find(b);
        if(a == b) {
            printf("-1\n");
            continue;
        }
        if(sz[a] == sz[b]) st = a < b;
        else st = sz[a] > sz[b];
        if(st) swap(a, b);
        printf("%d\n", b);
        sz[b] += sz[a] >> 1;
        par[a] = b;
    }
}