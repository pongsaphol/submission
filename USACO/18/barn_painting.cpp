#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int M = 1e9+7;

int n, k;
int dp[N][3];
vector<int> g[N];

void dfs(int u, int p) {
    for(int v : g[u]) if(v != p) for(int j = 1; j <= 3; ++j) {
        int sum = 0;
        for(int i = 1; i <= 3; ++i) if(i != j)
            sum = (sum + dp[v][i]) % M;
        dp[u][j] = (1ll * dp[u][j] * sum) % M;
    }
}

void online_judge() {
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
}

int main() {
    online_judge();
    scanf("%d %d", &n, &k);
    fill_n(dp[0], N*3, 1);
    for(int i = 1, a, b; i < n; ++i) {
        scanf("%d %d", &a, &b);
        g[a].emplace_back(b), g[b].emplace_back(a);
    }
    for(int i = 0, a, b; i < k; ++i) {
        scanf("%d %d", &a, &b);
        for(int j = 1; j <= 3; ++j) if(b != j) dp[a][j] = 0;
    }
    dfs(1, 0);
    int sum = 0;
    for(int i = 1; i <= 3; ++i) sum += dp[1][i], sum %= M;
    printf("%d\n", sum);
}
