#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;

int n, m, ptr;
int A[N], pos[N], sz[N];
char str[N];
vector<int> g[N], ng[N];

int low[N], dist[N];
bool in[N];

void tar(int u) {
    static int idx = 0;
    static stack<int> S;
    low[u] = dist[u] = ++idx;
    S.emplace(u), in[u] = true;
    for(int v : g[u]) {
        if(!dist[v]) tar(v), low[u] = min(low[u], low[v]);
        else if(in[v]) low[u] = min(low[u], dist[v]);
    }
    if(low[u] == dist[u]) {
        ptr++;
        do pos[S.top()] = ptr, in[S.top()] = false, sz[ptr]++, S.pop(); while(!pos[u]);
    }
}

int dp[N];

int dfs(int u) {
    if(dp[u]) return dp[u];
    for(int v : ng[u]) 
        dp[u] = max(dp[u], dfs(v));
    return dp[u] += sz[u];
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    A[0] = A[n+1] = 1e9;
    for(int i = 1; i <= n; ++i) {
        if(A[i] >= A[i-1]) g[i].emplace_back(i-1);
        if(A[i] >= A[i+1]) g[i].emplace_back(i+1);
    }
    scanf("%s", str+1);
    for(int i = 1; i <= n; ++i) if(str[i] == 'T') g[i].emplace_back(n+1);
    for(int i = 1; i <= n; ++i) g[n+1].emplace_back(i);
    for(int i = 1; i <= n+1; ++i) if(!dist[i]) tar(i);
    sz[pos[n+1]]--;
    for(int i = 1; i <= n+1; ++i) for(int v : g[i]) if(pos[i] != pos[v]) 
        ng[pos[i]].emplace_back(pos[v]);
    printf("%d\n", dfs(pos[m]));
}
