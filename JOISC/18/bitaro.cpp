/*
 first I think it is very hard problem
 and I got hint square root
 preprocess each block of size most sqrt
 if Y_i is < sqrt -> query in block
 else solve with topo order 
*/
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;
const int INF = 1e9;
const int sz = 350;

int n, m, q;
vector<int> g[N], topo;
vector<pii> block[N];
int pos[N], deg[N];
int d[N];
map<int, int> tod[N];
bool mark[N];

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        if(u > v) swap(u, v);
        g[u].emplace_back(v);
        deg[v]++;
    }
    queue<int> Q;
    for(int i = 1; i <= n; ++i) if(!deg[i]) Q.emplace(i);
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        topo.emplace_back(u);
        for(auto x : tod[u]) block[u].emplace_back(x);
        block[u].emplace_back(u, 0);
        sort(all(block[u]), [&](const pii &a, const pii &b) { return a.y > b.y; });
        if(block[u].size() > sz) block[u].resize(sz);
        for(int v : g[u]) {
            for(pii x : block[u]) tod[v][x.x] = max(tod[v][x.x], x.y + 1);
            if(!--deg[v]) Q.emplace(v);
        }    
    }
    for(int i = 0, u, t; i < q; ++i) {
        scanf("%d %d", &u, &t);
        vector<int> vec;
        for(int i = 0, v; i < t; ++i) scanf("%d", &v), vec.emplace_back(v);
        if(t < sz) {
            for(int v : vec) mark[v] ^= 1;
            bool st = true;
            for(pii v : block[u]) if(!mark[v.x]) {
                printf("%d\n", v.y), st = false;
                break;
            }
            if(st) puts("-1");
            for(int v : vec) mark[v] ^= 1;
        } else {
            memset(d, 0, sizeof d);
            for(int v : vec) d[v] = -INF;
            for(int i = 0; i < n; ++i) {
                int u = topo[i];
                for(int v : g[u]) d[v] = max(d[v], d[u] + 1);
            }
            printf("%d\n", d[u] < 0 ? -1 : d[u]);
        }
    } 
}
