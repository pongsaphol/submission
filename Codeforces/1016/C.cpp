#include <bits/stdc++.h>
using namespace std;

#define long long long

const int N = 3e5+5;

int n, A[2][N];
long pfu[N<<1], pfd[N<<1];
long a1[N<<1], a2[N<<1];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", A[0] + i);
    for(int i = 1; i <= n; ++i) scanf("%d", A[1] + i);
    for(long i = 1; i <= n; ++i) pfu[i] = pfu[i-1] + i * A[0][i], a1[i] = a1[i-1] + A[0][i];
    for(long i = n+1; i <= n+n; ++i) pfu[i] = pfu[i-1] + i * A[1][n+n-i+1], a1[i] = a1[i-1] + A[1][n+n-i+1];
    for(long i = 1; i <= n; ++i) pfd[i] = pfd[i-1] + i * A[1][i], a2[i] = a2[i-1] + A[1][i];
    for(long i = n+1; i <= n+n; ++i) pfd[i] = pfd[i-1] + i * A[0][n+n-i+1], a2[i] = a2[i-1] + A[0][n+n-i+1];
    long ans = pfu[n+n] - a1[n+n];
    long sum = 0;
    for(long i = 1; i <= n; ++i) {
        if(i & 1) {
            sum += A[0][i] * (2*i - 2) + A[1][i] * (2*i - 1);
            ans = max(ans, sum + pfd[n+n-i] - pfd[i] + (i-1) * (a2[n+n-i] - a2[i]));
        } else {
            sum += A[1][i] * (2*i - 2) + A[0][i] * (2*i - 1);
            ans = max(ans, sum + pfu[n+n-i] - pfu[i] + (i-1) * (a1[n+n-i] - a1[i]));
        }
    }
    printf("%lld\n", ans);
}