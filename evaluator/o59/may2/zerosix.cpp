#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m;
int dp[N][N][2000];

int main() {
    scanf("%d %d", &n, &m); 
    fill_n(dp[0][0], n*n*2000, -10000000);
    dp[1][0][0] = 0;
    for(int i = 1; i <= n; ++i) for(int j = 1, ret; j <= m; ++j) {
        scanf("%d", &ret); 
        int c2 = 0, c3 = 0;
        while(ret % 2 == 0) c2++, ret /= 2;
        while(ret % 3 == 0) c3++, ret /= 3;
        for(int k = c2; k < 2000; ++k) dp[i][j][k] = max(dp[i-1][j][k-c2], dp[i][j-1][k-c2]) + c3;
    }
    int mx = 0;
    for(int i = 0; i < 2000; ++i) mx = max(mx, min(i, dp[n][m][i]));
    printf("%d\n", mx);
}
