#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

int n, m;
int dp[11][110000];

int main() {
    scanf("%d %d", &n, &m);
    fill_n(dp[0], 11 * 110000, (int)1e9);
    dp[0][0] = 0;
    m /= 100;
    for(int i = 1; i <= n; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        vector<pii> V;
        V.emplace_back(0, 0);
        for(int j = 1; j < a; ++j) V.emplace_back(j, j * i);
        V.emplace_back(a, a * i + (b / 100));
        for(pii x : V) for(int j = x.y; j < 110000; ++j) dp[i][j] = min(dp[i][j], dp[i-1][j-x.y] + x.x);
    }
    int ans = 1e9;
    for(int j = m; j < 110000; ++j) ans = min(ans, dp[n][j]);
    printf("%d\n", ans);
}
