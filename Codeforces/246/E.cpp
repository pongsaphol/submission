#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;

int n, q, sz[N], ans[N], in[N], out[N], dep[N], pos[N];
string s[N];
vector<int> g[N];
vector<pii> que[N];
unordered_map<string, int> M[N<<1];

void get_sz(int u) {
    static int idx = 0;
    sz[u] = 1, in[u] = ++idx, pos[idx] = u;
    for(int &v : g[u]) {
        dep[v] = dep[u]+1, get_sz(v), sz[u] += sz[v];
        if(sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
    }
    out[u] = idx;
}

void dfs(int u, bool keep = false) {
    for(int v : g[u]) if(v != g[u][0]) dfs(v, false);
    if(g[u].size()) dfs(g[u][0], true);
    M[dep[u]][s[u]]++;
    for(int v : g[u]) if(v != g[u][0]) 
        for(int i = in[v]; i <= out[v]; ++i) M[dep[pos[i]]][s[pos[i]]]++;
    for(pii w : que[u]) ans[w.y] = M[dep[u] + w.x].size(); 
    if(!keep) for(int i = in[u]; i <= out[u]; ++i) 
        if(!--M[dep[pos[i]]][s[pos[i]]]) M[dep[pos[i]]].erase(s[pos[i]]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1, p; i <= n; ++i) {
        cin >> s[i] >> p;
        g[p].emplace_back(i);
    }
    cin >> q;
    for(int i = 0, a, b; i < q; ++i) {
        cin >> a >> b;
        que[a].emplace_back(b, i);
    }
    get_sz(0);
    dfs(0);
    copy(ans, ans + q, ostream_iterator<int>(cout, "\n"));
}