#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 205;
const int K = 1005;
const long M = 1e9+7;

int n, k;
int arr[N];
int dp[N][N][K];

int mic(int i, int j, int k) {
    if(j < 0) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    int &z = dp[i][j][k];
    if(i == n) return z = (j == 0);
    int v = k + j * (arr[i+1] - arr[i]);
    if(v > ::k) return z = 0;
    return z = (1ll * mic(i+1, j, v) * (j+1) + 1ll * mic(i+1, j-1, v) * j + mic(i+1, j+1, v)) % M;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i) scanf("%d", arr+i);
    sort(arr+1, arr+n+1);
    printf("%d\n", mic(0, 0, 0));
}