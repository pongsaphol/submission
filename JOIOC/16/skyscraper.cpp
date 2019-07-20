#include <bits/stdc++.h>
#define long long long 
using namespace std;

const long M = 1e9+7;

const int N = 105;
const int L = 1005;

int n, m;
int arr[N];
long dp[N][N][L][3];

long mic(int i, int j, int k, int l) {
    if(i != 0 && (j <= 0 || l > 2)) return 0;
    long &z = dp[i][j][k][l];
    if(z != -1) return z;
    if(i == n) return (j == 1 && l == 2);
    int v = (arr[i+1] - arr[i]) * (2*j - l) + k;
    if(v > m) return 0;
    z = (2 * j - l) * mic(i+1, j, v, l) % M;
    z = (z + (j + 1 - l) * mic(i+1, j+1, v, l)) % M;
    z = (z + (2 - l) * mic(i+1, j+1, v, l+1)) % M;
    z = (z + (2 - l) * mic(i+1, j, v, l+1)) % M;
    z = (z + (j - 1) * mic(i+1, j-1, v, l)) % M;
    return z;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", arr+i);
    sort(arr+1, arr+n+1);
    arr[0] = arr[1];
    printf("%lld\n", n == 1 ? 1 : mic(0, 0, 0, 0));
}