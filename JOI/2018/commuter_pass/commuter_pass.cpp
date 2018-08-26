#include <bits/stdc++.h>
using namespace std;

#define long long long
#define pli pair<long, int>
#define pii pair<int, int>
#define x first
#define y second

const int N = 1e5+5;

int n, m, s, t, u, v;
long d[3][N], z[4][N];
bool mark[N];
vector<pii> g[N];

void dijkstra(int u, long d[]) {
    fill_n(d, N, (long)1e18);
    priority_queue<pli, vector<pli>, greater<pli> > Q;
    Q.emplace(d[u] = 0, u);
    while(!Q.empty()) {
        auto u = Q.top(); Q.pop();
        if(mark[u.y]) continue;
        else mark[u.y] = true;
        for(auto v : g[u.y]) if(d[v.x] > u.x + v.y) {
            Q.emplace(d[v.x] = u.x + v.y, v.x);
        }
    }
    memset(mark, 0, sizeof mark);
}

int main() {
    scanf("%d %d %d %d %d %d", &n, &m, &s, &t, &u, &v );
    for(int i = 0, u, v, w; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].emplace_back(v, w), g[v].emplace_back(u, w);
    }
    dijkstra(u, d[1]), dijkstra(v, d[2]), dijkstra(s, d[0]);
    long mn = 1e18;
    for(int i = 1; i <= n; ++i) z[1][i] = d[1][i], z[2][i] = d[2][i], z[3][i] = d[1][i] + d[2][i], mn = min(mn, z[3][i]);
    fill_n(z[0], N, (long)1e18);
    priority_queue<pli, vector<pli>, greater<pli> > Q;
    Q.emplace(z[0][s] = 0, s);
    while(!Q.empty()) {
        auto u = Q.top(); Q.pop();
        for(auto v : g[u.y]) if(u.x + v.y == d[0][v.x]) {
            if(!mark[v.x]) mark[v.x] = true, Q.emplace(z[0][v.x] = u.x + v.y, v.x);
            z[1][v.x] = min(z[1][v.x], z[1][u.y]);
            z[2][v.x] = min(z[2][v.x], z[2][u.y]);
            z[3][v.x] = min({z[3][v.x], z[1][u.y] + d[2][v.x], z[2][u.y] + d[1][v.x], z[3][u.y]});
        }
    }
    return !printf("%lld\n", min(mn, z[3][t]));
}
