#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 1e9+7;

int n, pos[N];
int A[N], B[N], dp[N][N][N];

int solve(int x, int y, int len) {
    int &now = dp[x][y][len];
    if(now != -1) return now;
    if(len == 1 && A[x] == B[y]) return now = 1;
    if(len == 0) return now = 1;
    if(len == 1) return now = 0;
    if(pos[A[x]] < y || pos[A[x]] >= y+len) return now = 0; 
    int sz = pos[A[x]] - y;
    now = 0;
    for(int i = 0; i < len - sz; ++i) 
        now = (now + 1ll * solve(x+sz+1, y+sz+1, i) * solve(x+sz+i+1, y+sz+i+1, len-sz-i-1)) % M;
    return now = (1ll * now * solve(x+1, y, sz)) % M;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", A+i);
    for(int i = 0; i < n; ++i) scanf("%d", B+i), pos[B[i]] = i;
    fill_n(dp[0][0], N*N*N, -1);
    printf("%d\n", solve(0, 0, n));
}