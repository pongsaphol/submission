#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+5;
const int INF = 1e9;
int n, A[N], dp[N][N][2];
bool chk[N][N][2];

int solve(int i, int j, int v) {
    int &z = dp[i][j][v];
    if(chk[i][j][v]) return z;
    if(i == 0 and v == 0) return 0;
    if(i == 0 and v == 1) return max(0, A[j+1] - A[j+2] + 1);
    if(j <= 0) return INF;
    if(v == 0) 
        z = min(solve(i, j-1, 0), solve(i-1, j-2, 1) + max(0, A[j+1] - A[j] + 1));
    else 
        z = min(solve(i, j-1, 0) + max(0, A[j+1] - A[j+2] + 1),
            solve(i-1, j-2, 1) + max(0, A[j+1] - min(A[j], A[j+2]) + 1));
    chk[i][j][v] = true;
    return z;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    A[0] = A[n+1] = -INF;
    for(int i = 1; i <= (n+1)/2; ++i) 
        printf("%d ", solve(i, n, 0));
}
