#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 1e3+5;
const long INF = 1e18;

int n, k, A[N];
long dp[N][N];

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    for(int i = 1; i <= n; ++i) for(int j = 0; j <= k; ++j) {
        dp[i][j] = max(dp[i-1][j], A[i] + max(j == 0 ? 0 : dp[i-1][j-1], i == 1 ? -INF : dp[i-2][j]));
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= k; ++j) printf("%lld ", dp[i][j]);
        puts("");
    }
    printf("%lld\n", dp[n][k]);
}
