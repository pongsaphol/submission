#include <bits/stdc++.h>
#define iiii tuple<int, int, int, int>
using namespace std;

const int N = 3e5+5;

int par[N];

int find(int u) { return par[u] = par[u] == u ? u : find(par[u]); }

int n, m;
vector<iiii> vec;

int deg[N];

vector<int> g[N];
vector<int> ord[N];

int main() {
    iota(par, par+N, 0);
    scanf("%d %d", &n, &m);
    for(int i = 0, a, b, c, t; i < m; ++i) {
        scanf("%d %d %d %d", &t, &a, &b, &c);
        if(t == 3) {
            a = find(a), b = find(b), c = find(c);
            par[b] = par[c] = a;
        } else {
            vec.emplace_back(t, a, b, c);
        }
    }
    for(auto x : vec) {
        int t, a, b, c; tie(t, a, b, c) = x;
        if(t == 1) g[find(b)].emplace_back(find(a)), g[find(c)].emplace_back(find(a));
        else g[find(a)].emplace_back(find(b)), g[find(a)].emplace_back(find(c));
    }
    set<int> s;
    for(int i = 1; i <= n; ++i) s.emplace(find(i)), ord[find(i)].emplace_back(i);
    for(auto x : s) {
        for(auto v : g[x]) deg[v]++;
    }
    queue<int> Q;
    printf("%d\n", (int)s.size());
    for(auto x : s) if(!deg[x]) Q.emplace(x);
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        printf("%d ", ord[u].size());
        for(int v : ord[u]) printf("%d ", v);
        printf("\n");
        for(int v : g[u]) if(!--deg[v]) Q.emplace(v);
    }
}
/*
3 2
1 1 2 3
2 2 3 1
*/
