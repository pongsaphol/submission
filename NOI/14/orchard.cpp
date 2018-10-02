#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 1e9;

int main() {
    scanf("%d %d", &n, &m);
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i = 1; i <= n; ++i) for(int j = 1, ret; j <= m; ++j) scanf("%1d", &ret), dp[i][j] = ret + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
    for(int i = 0 ; i < n; ++i) for(int j = i+1; j <= n; ++j) {
        int mn = 1e9;
        for(int k = 1; k <= m; ++k) {
            mn = min(mn, 2 * (dp[j][k-1] - dp[i][k-1]) + (i - j) * (k-1));
            ans = min(ans, dp[n][m] - 2 * (dp[j][k] - dp[i][k]) + (j - i) * k + mn);
        }
    }
    printf("%d\n", ans);
}
