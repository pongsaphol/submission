#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 5e5+5;

int n, m, sz[N], pos[N], dep[N], in[N], out[N], mask[N];
string A;
bool ans[N];
vector<int> g[N];
vector<pii> que[N];

void get_sz(int u, int p = 0) {
    static int idx = 0;
    dep[u] = dep[p] + 1, in[u] = ++idx, pos[idx] = u, sz[u] = 1;
    for(int &v : g[u]) {
        get_sz(v, u), sz[u] += sz[v];
        if(sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
    }
    out[u] = idx;
}

void dfs(int u, bool keep = false) {
    for(int v : g[u]) if(v != g[u][0]) dfs(v, false);
    if(g[u].size()) dfs(g[u][0], true);
    for(int v : g[u]) if(v != g[u][0]) {
        for(int i = in[v]; i <= out[v]; ++i) {
            int w = pos[i];
            mask[dep[w]] ^= 1 << (A[w] - 'a');
        }
    }
    mask[dep[u]] ^= 1 << (A[u] - 'a');
    auto isPalin = [&](int x) {
        int z = log2(x);
        return !x || (1 << z) == x;
    };
    for(pii w : que[u]) ans[w.y] = isPalin(mask[w.x]);
    if(!keep) for(int i = in[u]; i <= out[u]; ++i) {
        int w = pos[i];
        mask[dep[w]] ^= 1 << (A[w] - 'a');
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 2, p; i <= n; ++i) {
        cin >> p;
        g[p].emplace_back(i);
    }
    cin >> A; A = "x" + A;
    for(int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        que[a].emplace_back(b, i);
    }
    get_sz(1), dfs(1);
    for_each(ans, ans + m, [&](bool ret) { cout << (ret ? "Yes" : "No") << '\n'; });
}