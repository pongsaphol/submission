#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5, M = 998244353;

int c[N][N];
int n, A[N], way[N];

int main() {
    scanf("%d", &n);
    c[0][0] = 1;
    for(int i = 1; i <= n; ++i) scanf("%d", A+i), c[i][0] = c[i][i] = 1;
    for(int i = 2; i <= n; ++i) for(int j = 1; j < n; ++j) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % M;
    int ans = 0;
    for(int i = n; i; --i) {
        if(A[i] <= 0 || A[i] > n-i) continue;
        way[i] = c[n-i][A[i]];
        for(int j = i+1; j <= n; ++j) {
            way[i] = (way[i] + (1ll * c[j-i-1][A[i]] * way[j]) % M) % M;
        }
        ans = (ans + way[i]) % M;
    }
    printf("%d\n", ans);
}