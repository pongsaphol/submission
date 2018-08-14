#include <bits/stdc++.h>
using namespace std;

#define long long long 

const int N = 1e5+5;
const long M = 1e9+7;

char A[N];
int n;
long dp[N][3];

int main() {
    scanf("%s", A+1);
    n = strlen(A+1);
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 3; ++j) dp[i][j] = dp[i-1][j];
        if(A[i] == 'A' || A[i] == '?') dp[i][0] = (dp[i][0] + 1) % M;
        if(A[i] == 'B' || A[i] == '?') dp[i][1] = (dp[i-1][0] + dp[i][1]) % M;
        if(A[i] == 'C' || A[i] == '?') dp[i][2] = (dp[i-1][1] + dp[i][2]) % M;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 3; ++j) printf("%d ", dp[i][j]);
        puts("");
    }
    printf("%lld\n", dp[n][2]);
}