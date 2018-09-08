#include <bits/stdc++.h>
using namespace std;

const int N = 3e3+5;

int n, m, A[N], dp[N][N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i), dp[i][0] = 1e9;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < min(m, i+1); ++j){
            dp[i][j] = min(dp[i][j-1], dp[i-j][m-j] + A[i]);
        }
        for(int j = min(m, i+1); j < m; ++j) dp[i][j] = dp[i][j-1];
    }
    int mn = 1e9;
    for(int i = n; i > n - m + 1; --i) {
        mn = min(mn, dp[i][m-(n-i)-1]);
    }
    printf("%d\n", mn);
}
