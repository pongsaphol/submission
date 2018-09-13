#include <bits/stdc++.h>
using namespace std;

const int N = 2e3+5;

int n, p, q;
int A[N];
int dp[N][N];

bool f(int m) {
    for(int i = 0; i <= p; ++i) for(int j = 0; j <= q; ++j) {
        if(i == 0 and j == 0) continue;
        dp[i][j] = 0;
        if(i != 0) dp[i][j] = upper_bound(A+1, A+n+1, A[dp[i-1][j]+1] + m - 1) - A - 1;
        if(j != 0) dp[i][j] = max((long int)dp[i][j], upper_bound(A+1, A+n+1, A[dp[i][j-1]+1] + m + m - 1) - A - 1);
        if(dp[i][j] == n) return true;
    }
    return false;
}

int main() {
    scanf("%d %d %d", &n, &p, &q);
    if(p + q >= n) return puts("1"), 0;
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    sort(A+1, A+n+1);
    vector<int> ret;
    for(int i = 2; i <= n; ++i) ret.emplace_back(A[i] - A[i-1]);
    sort(ret.begin(), ret.end());
    int l = 1, r = 0;
    for(int i = 0; i < n - (p+q); ++i) r += ret[i];
    while(l < r) {
        int m = l + r >> 1;
        if(f(m)) r = m;
        else l = m+1;
    }
    return !printf("%d\n", r);
}
