#include <bits/stdc++.h>
#define iii tuple<int, int, int>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 2e3+10;
const int INF = 2e9+1;

int n, m, w, h;
int par[N];
int x[N], y[N], r[N];
int d[4][4];
double eps = 1e-6;

vector<pii> g[4];

void init() {
    g[1] = {{2, 3}, {0, 2}, {2, 1}};
    g[2] = {{1, 2}, {1, 3}, {0, 2}, {0, 3}};
    g[3] = {{1, 3}, {0, 1}, {1, 2}};
}

int find(int u) { return par[u] = par[u] == u ? u : find(par[u]); }

int main() {
    init();
    iota(par, par+N, 0);
    scanf("%d %d %d %d", &n, &m, &w, &h);
    vector<iii> E;
    for(int i = 0; i < n; ++i) {
        scanf("%d %d %d", x+i, y+i, r+i);
        E.emplace_back(i, n, h - y[i] - r[i]);
        E.emplace_back(i, n + 1, x[i] - r[i]);
        E.emplace_back(i, n + 2, y[i] - r[i]);
        E.emplace_back(i, n + 3, w - x[i] - r[i]);
    }
    for(int i = 0; i < n; ++i) for(int j = i+1; j < n; ++j) {
        int dist = (int)(hypot(x[i] - x[j], y[i] - y[j]))  - r[i] - r[j];
        E.emplace_back(i, j, dist);
    }
    sort(E.begin(), E.end(), [&](const iii &a, const iii &b) { return get<2>(a) < get<2>(b); });
    for(int i = 0; i < 4; ++i) for(int j = 0; j < 4; ++j) {
        if(i == j) d[i][i] = INF;
        else d[i][j] = -1;
    }
    for(auto x : E) {
        int u, v, w; tie(u, v, w) = x;
        par[find(u)] = find(v);
        for(int i = 0; i < 4; ++i) for(int j = 0; j < 4; ++j) if(i != j) {
            int dist = (j-i+4) % 4;
            for(auto z : g[dist]) {
                int a, b; tie(a, b) = z;
                a = n + ((a + i) % 4), b = n + ((b + i) % 4);
                if(find(a) == find(b) && d[i][j] == -1) d[i][j] = w;
            }
        }
    }
    for(int i = 0; i < 4; ++i) for(int j = 0; j < 4; ++j) if(d[i][j] == -1) d[i][j] = INF;
    for(int i = 0, a, b; i < m; ++i) {
        scanf("%d %d", &a, &b), b--; a *= 2;
        for(int j = 0; j < 4; ++j) if(a <= d[b][j]) printf("%d", j+1);
        printf("\n");
    }
}