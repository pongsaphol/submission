#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 2e5+5;

int n, P[N], sz[N], in[N], out[N], pos[N];
bool dis[N], dep[N];
vector<int> g[N];
int val[2][2];

void get_sz(int u) {
    static int idx = 0;
    sz[u] = 1, in[u] = ++idx, pos[idx] = u;
    for(int &v : g[u]) {
        dep[v] = dep[u] ^ dis[v], get_sz(v), sz[u] += sz[v];
        if(sz[v] >= sz[g[u][0]]) swap(v, g[u][0]);
    }
    out[u] = idx;
}

long sum = 0;

void dfs(int u, bool keep = 0) {
    for(int v : g[u]) if(v != g[u][0]) dfs(v, false);
    if(g[u].size()) dfs(g[u][0], true);
    for(int v : g[u]) if(v != g[u][0]) {
        for(int i = in[v]; i <= out[v]; ++i) { 
            int w = pos[i];        
            bool st = P[w] < 0;
            sum += 1ll * abs(P[w]) * (val[dep[w]^st][1] + val[dep[w]^1^st][0]);
        }
        for(int i = in[v]; i <= out[v]; ++i) { 
            int w = pos[i]; val[dep[w]][P[w] > 0] += abs(P[w]);
        }
    }
    bool st = P[u] < 0;
    sum += 1ll * abs(P[u]) * (val[dep[u]^st][1] + val[dep[u]^1^st][0]);
    val[dep[u]][P[u] > 0] += abs(P[u]);
    if(!keep) for(int i = in[u]; i <= out[u]; ++i) { 
        int w = pos[i]; val[dep[w]][P[w] > 0] -= abs(P[w]);
    }
}

int main() {
    scanf("%d %d", &n, P);
    for(int i = 1, p, d; i < n; ++i) {
        scanf("%d %d %d", P+i, &p, &d);
        dis[i] = d & 1;
        g[p].emplace_back(i);
    } 
    get_sz(0);
    dfs(0);
    printf("%lld\n", sum);
}