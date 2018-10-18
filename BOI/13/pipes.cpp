#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, m, s[N], t[N];
int A[N], deg[N];
int ans[N];

set<int> g[N];

void answer() {
    for(int i = 0; i < m; ++i) printf("%d\n", ans[i]);
    exit(0);
}

queue<int> Q;

void solve() {
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for(int x : g[u]) {
            int v = u ^ s[x] ^ t[x]; 
            g[v].erase(x);
            A[v] -= A[u];
            ans[x] = A[u] << 1;
            if(g[v].size() == 1) Q.emplace(v);
        }
        g[u].clear();
    }
}

int cnt = 0;

void dfs(int u, int p) {
    static int idx = 0;
    static int sum = 0;
    idx++;
    if(idx & 1) sum += A[u];
    else sum -= A[u];
    int z = -1;
    for(auto i : g[u]) {
        int v = u ^ s[i] ^ t[i];
        if(v != p) {
            if(cnt == idx) {
                ans[i] = sum;
                A[u] -= sum / 2, A[v] -= sum / 2;
                z = i;
                break;
            }
            dfs(v, u);
        }
    }
    if(cnt == idx) {
        int v = u ^ s[z] ^ t[z];
        g[v].erase(z), g[u].erase(z);
        Q.emplace(u);
    } 
}

int main() {
    scanf("%d %d", &n, &m);
    if(n < m) return puts("0"), 0;
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", s+i, t+i);
        g[s[i]].emplace(i), g[t[i]].emplace(i);
        deg[s[i]]++, deg[t[i]]++;
    }
    for(int i = 1; i <= n; ++i) if(deg[i] == 1) Q.emplace(i);
    solve(); 
    if(n == m+1) answer();
    for(int i = 1; i <= n; ++i) if(g[i].size()) cnt++;
    if(cnt % 2 == 0) return puts("0"), 0;
    for(int i = 1; i <= n; ++i) {
        if(g[i].size()) dfs(i, i);
        break;
    }
    solve();
    answer();
}
