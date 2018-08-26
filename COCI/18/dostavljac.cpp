#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n, m, A[N];
int dp[2][N][N];
int L[N][N], R[N][N];
vector<int> g[N];

void dfs(int u, int p) {
    memset(L, 0, sizeof L), memset(R, 0, sizeof R);
    L[0][1] = R[g[u].size()][1] = A[u];
    dp[0][u][1] = dp[1][u][1] = A[u];
    if(u != 1) g[u].erase(find(g[u].begin(), g[u].end(), p));
    for(int i = 1; i < g[u].size(); ++i) {
        int v = g[u][i];
        dfs(v, u);
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= m; ++j) L[i][j] = max(L[i][j], L[i-1][j]);
            for(int j = i; j <= m-2; ++j) L[i][j+2] = max(L[i][j+2], L[i-1][j-i] + dp[0][v][i]);
        }
    }
    for(int i = g[u].size()-1; i; --i) {
        int v = g[u][i];
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= m; ++j) R[i][j] = max(R[i][j], R[i+1][j]);
            for(int j = i; j <= m-2; ++j) R[i][j+2] = max(R[i][j+2], R[i+1][j-i] + dp[0][v][i]);
        }
    }
    for(int i = 1; i < g[u].size(); ++i) {
        int v = g[u][i];
         for(int i = 1; i <= m; ++i)
            for(int j = i; j <= m-1; ++j) dp[1][u][j+1] = max(dp[1][u][j+1], max(L[i-1][j-i], R[i+1][j-i]) + dp[1][v][i]);
    }
    printf("---%d---\n", u);
    for(int i = 1; i <= m; ++i) dp[0][u][i] = max(dp[0][u][i], R[1][i]);
    for(int i = 1; i <= m; ++i) {
        printf("%d ", dp[0][u][i]);
    }
    puts("");
    for(int i = 1; i <= m; ++i) {
        printf("%d ", dp[1][u][i]);
    }
    puts("");
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i), g[i].emplace_back(0);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    dfs(1, 0);
    printf("%d\n", max(*max_element(dp[0][1], dp[0][1] + N), *max_element(dp[1][1], dp[1][1] + N)));
}