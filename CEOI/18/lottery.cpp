#include <bits/stdc++.h>
using namespace std;

const int N = 2e4+5;
const int O = 10001;
const int Q = 105;

int n, l, q;
int cnt[N];
int A[N], dp[2][N], ans[Q][N], v[Q];

int main() {
    scanf("%d %d", &n, &l);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    scanf("%d", &q);
    for(int i = 0; i < q; ++i) scanf("%d", v+i);
    for(int i = 2-l; i <= n-l+1; ++i) {
        int z = (O+i)&1;
        memset(cnt, 0, sizeof cnt);
        for(int j = 2-l; j <= n-l+1; ++j) {
            dp[z][O+j] = dp[z^1][O+j-1];
            int a = i+l-1, b = j+l-1;
            int c = i-1, d = j-1;
            if(a >= 1 && b >= 1 && a <= n && b <= n)
                dp[z][O+j] += A[a] != A[b];
            if(c >= 1 && d >= 1 && c <= n && d <= n)
                dp[z][O+j] -= A[c] != A[d];
            if(i >= 1 && j >= 1) 
                cnt[dp[z][O+j]]++;
        }
        for(int j = 1; j <= n; ++j)
            cnt[j] += cnt[j-1];
        if(i >= 1) for(int j = 0; j < q; ++j)
            ans[j][i] = cnt[v[j]];
    }
    for(int i = 0; i < q; ++i) {
        for(int j = 1; j <= n-l+1; ++j) {
            printf("%d ", ans[i][j]-1);
        }
        puts("");
    }
}