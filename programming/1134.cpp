#include <bits/stdc++.h>
using namespace std;

const int M = 2553;

inline void mul(int a[4][4], int b[4][4], int ret[4][4]) {
    for(int i = 0; i < 4; ++i) for(int j = 0; j < 4; ++j) for(int k = 0; k < 4; ++k) 
        ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % M;
}
inline void mul2(int a[4][4], int b[4]) {
    int ret[4] = {0, 0, 0, 0};
    ret[0] = (a[0][0] * b[0] + a[0][1] * b[1] + a[0][2] * b[2] + a[0][3] * b[3]) % M;
    ret[1] = (a[1][0] * b[0] + a[1][1] * b[1] + a[1][2] * b[2] + a[1][3] * b[3]) % M;
    ret[2] = (a[2][0] * b[0] + a[2][1] * b[1] + a[2][2] * b[2] + a[2][3] * b[3]) % M;
    ret[3] = (a[3][0] * b[0] + a[3][1] * b[1] + a[3][2] * b[2] + a[3][3] * b[3]) % M;
    for(int i = 0; i < 4; ++i) b[i] = ret[i];
}

inline void fast(long long &ret) {
    ret = 0;
    register int c = getchar();
    while(c < '0' || c > '9') c = getchar();
    for(; c >= '0' && c <= '9'; c = getchar()) 
        ret = (ret<<1) + (ret<<3) + c - '0';
}

int dp[64][4][4];

int main() {
    int a, b, c, d, e, f, g, h;
    scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h);
    dp[0][0][1] = dp[0][1][2] = dp[0][2][3] = 1; 
    dp[0][3][0] = h, dp[0][3][1] = g, dp[0][3][2] = f, dp[0][3][3] = e;
    for(int i = 1; i < 64; ++i) mul(dp[i-1], dp[i-1], dp[i]);
    int m; scanf("%d", &m);
    while(m--) {
        long long ret;
        fast(ret);
        int z[4] = {a, b, c, d};
        ret--;
        for(int i = 0; i < 64; ++i) if(ret & 1ll << i) mul2(dp[i], z);
        printf("%d\n", z[0]);
    }
}