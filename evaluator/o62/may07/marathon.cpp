#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 5e4+5;
const int Z = 1<<6;
const int INF = 1e9+1;

int n, s, t, m, q;
set<int> S, T, zz;
vector<pii> g[N];
int rnd[N];
int d[Z][N];

void dijk(int d[], int s) {
    fill_n(d, N, INF);
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    Q.emplace(d[s] = 0, s);
    while(!Q.empty()) {
        auto u = Q.top(); Q.pop();
        for(pii v : g[u.y]) if(d[v.x] > d[u.y] + v.y)
            Q.emplace(d[v.x] = d[u.y] + v.y, v.x);
    }
}

int main() {
    scanf("%d %d %d %d %d", &n, &s, &t, &m, &q);
    for(int i = 0, u, v, w; i < m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].emplace_back(v, w), g[v].emplace_back(u, w);
    }
    srand(time(NULL));
    for(int i = 0, val; i < s+t; ++i) scanf("%d", &val), S.emplace(val);
    for(int i = 0, z; i < Z; ++i) {
        while(S.count(z = rand()%n + 1)) {}
        dijk(d[i], z);
    }
    for(int i = 0, a, b; i < q; ++i) {
        scanf("%d %d", &a, &b);
        int mn = INF;
        for(int i = 0; i < Z; ++i) mn = min(mn, d[i][a] + d[i][b]);
        printf("%d\n", mn);
    }
}