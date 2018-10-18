#include <bits/stdc++.h>
using namespace std;

#define iii tuple<int, int, int>
#define pii pair<int, int>
#define x first
#define y second

const int N = 1e4+5;
const int inf = 1e9;

int n, m, s, t;
vector<pii> g[N], rg[N];

int d[2][N];

void dijkstra(vector<pii> g[], int d[], int s) {
    fill_n(d, N, inf);
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    Q.emplace(d[s] = 0, s);
    while(!Q.empty()) {
        int u = Q.top().y; Q.pop();
        for(pii v : g[u]) if(d[v.x] > d[u] + v.y) Q.emplace(d[v.x] = d[u] + v.y, v.x);
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &t);
    vector<iii> E;
    for(int i = 0, u, v, w; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].emplace_back(v, w), rg[v].emplace_back(u, w);
        E.emplace_back(u, v, w);
    }
    dijkstra(g, d[0], s), dijkstra(rg, d[1], t); 
    int ans = inf;
    for(int i = 0; i < m; ++i) {
        int u, v, w; tie(u, v, w) = E[i];
        int ret = d[0][u] + d[1][v] + w;
        if(ret < ans and ret != d[0][t]) ans = ret;
    }
    printf("%d\n", ans);
}
