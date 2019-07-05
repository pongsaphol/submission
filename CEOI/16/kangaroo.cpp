/*
    new topic -> DP component 
    http://codeforces.com/blog/entry/47764
    
    dp(i, j) <- consider 1...i and have j component
    if i == s or i == t:
        dp(i, j) = dp(i-1, j-1) + dp(i-1, j)
    else:
        dp(i, j) = dp(i-1, j+1) * j + dp(i-1, j-1) * (j - (i > s) - (i > t)) 
*/
#include <bits/stdc++.h>
#define long long long
using namespace std;

const int M = 1e9+7;

const int N = 2e3+5;

int n, s, t;
long dp[N][N];

long solve(int i, int j) {
    if(j == 0) return 0;
    long &now = dp[i][j];
    if(now != -1) return now;
    if(i == 1) return now = (j == 1 ? 1 : 0);
    if(i == s || i == t) 
        return now = (solve(i-1, j-1) + solve(i-1, j)) % M;
    return now = (solve(i-1, j+1) * j + solve(i-1, j-1) * (j - (i > s ? 1 : 0) - (i > t ? 1 : 0))) % M; 
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d %d %d", &n, &s, &t);
    printf("%lld\n", solve(n, 1));
}
