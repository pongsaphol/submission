#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int C = 205;
const int INF = -1e9;

int dp[N][N][C<<1][N];
bool chk[N][N][C<<1][N];
int d2[N][N];
bool c2[N][N];
int d[N][N];
char A[N];
char inp[C<<1][N];
int n, m, val[C<<1], len[C<<1];

#define all l][r][c][ith

int fll(int l, int r);

int solve(int l, int r, int c, int ith) {
    int &ret = dp[all];
    if(chk[all]) return ret;
    chk[all] = true;
    if(!inp[c][ith+1]) return ret = val[c] + fll(l+1, r);
    for(int i = l+1; i <= r; ++i) if(A[i] == inp[c][ith+1]) ret = max(ret, fll(l+1, i-1) + solve(i, r, c, ith+1));
    return ret;
} 

int fll(int l, int r) {
    if(l > r) return 0;
    if(c2[l][r]) return d2[l][r];
    c2[l][r] = true;
    for(int i = 1; i <= 2 * m; ++i) if(inp[i][1] == A[l]) d2[l][r] = max(d2[l][r], solve(l, r, i, 1));
    return d2[l][r];
}

int main() {
    scanf("%s", A+1);
    n = strlen(A+1);
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%s %d", inp[i]+1, val + i);
        int n = strlen(inp[i]+1);
        val[i+m] = val[i];
        for(int j = n; j; --j) inp[i+m][n-j+1] = inp[i][j];
    }
    fill_n(dp[0][0][0], N*N*N*C, (int)(-1e9));
    fill_n(d2[0], N*N, (int)(-1e9));
    for(int i = 1; i <= n; ++i) for(int j = i; j <= n; ++j) for(int k = 1; k <= 2*m; ++k) 
        if(inp[k][1] == A[i]) d[i][j] = max(d[i][j], solve(i, j, k, 1));
    for(int len = 2; len <= n; ++len) for(int i = 1, j = len; j <= n; ++i, ++j) {
        for(int k = i; k < j; ++k) d[i][j] = max(d[i][j], d[i][k] + d[k+1][j]);
    }
    printf("%d\n", d[1][n]);
}