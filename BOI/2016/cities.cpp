#include <bits/stdc++.h>
#define long long long
#define pll pair<long, long>
#define x first
#define y second
using namespace std;

const int N = 2e5+5;
long INF = 1e18;

int n, k, m;
long d[1<<5][N];
vector<pll> g[N];

void dijkstra(long d[]) {
    priority_queue<pll, vector<pll>, greater<pll> > Q;
    for(int i = 1; i <= n; ++i) Q.emplace(d[i], i);
    while(!Q.empty()) {
        auto now = Q.top(); Q.pop();
        if(now.x != d[now.y]) continue;
        for(auto v : g[now.y]) if(d[v.x] > now.x + v.y)
            Q.emplace(d[v.x] = now.x + v.y, v.x);
    }
}

int main() {
    scanf("%d %d %d", &n, &k, &m);
    fill_n(d[0], N * (1<<5), INF);
    for(int i = 0, a; i < k; ++i) {
        scanf("%d", &a);
        d[1<<i][a] = 0; 
    }
    for(int i = 0, u, v, w; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    for(int i = 1; i < (1<<k); ++i) {
        for(int j = i; j; j = (j - 1) & i) {
            int v = i - j;
            for(int z = 1; z <= n; ++z) d[i][z] = min(d[i][z], d[j][z] + d[v][z]);
        }
        dijkstra(d[i]);
    } 
    printf("%lld\n", *min_element(d[(1<<k)-1], d[(1<<k)-1] + N));
}