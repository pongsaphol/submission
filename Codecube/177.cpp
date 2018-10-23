#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;
const int N = 1e3+5;

int n, m;
int dp[N][N];
bool st[N][N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) scanf("%d", &st[i][j]);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
        if(i == 1 and j == 1) dp[i][j] = 1;
        else if(!st[i][j]) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % M;
    }
    printf("%d\n", dp[n][m]);
}
