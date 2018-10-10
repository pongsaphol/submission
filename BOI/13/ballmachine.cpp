#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 1e5+5;

int n, m;
int par[N][17], dep[N];
int mnpth[N];
vector<int> g[N];

int dfs(int u) {
    mnpth[u]  = u;
    for(int i = 1; i < 17; ++i) par[u][i] = par[par[u][i-1]][i-1];
    for(int v : g[u]) {
        dep[v] = dep[u] + 1, par[v][0] = u;
        mnpth[u] = min(mnpth[u], dfs(v));
    }
    return mnpth[u];
}

int A[N], ptr;
int pos[N];

void solve(int u) {
    vector<pii> ret;
    for(auto v : g[u]) ret.emplace_back(mnpth[v], v);
    sort(ret.begin(), ret.end());
    for(auto v : ret) solve(v.y);
    A[++ptr] = u;
}

set<int> S;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1, val; i <= n; ++i) scanf("%d", &val), g[val].emplace_back(i);
    int rt = g[0][0];
    dep[rt] = 1, dfs(rt);
    solve(rt);
    for(int i = 1; i <= n; ++i) pos[A[i]] = i;
    int ptr = 0;
    for(int i = 1; i <= n; ++i) S.emplace(i);
    for(int i = 0, a, b; i < m; ++i) {
        scanf("%d %d", &a, &b);
        if(a == 1) {
            while(b--) {
                if(!b) printf("%d\n", A[*S.begin()]);
                S.erase(S.begin());
            } 
        } else {
            int sum = 0;
            for(int i = 16; ~i; --i) 
                if(par[b][i] != 0 && S.count(pos[par[b][i]]) == 0) b = par[b][i], sum += 1<<i;
            S.emplace(pos[b]);
            printf("%d\n", sum);
        }
    }
}
