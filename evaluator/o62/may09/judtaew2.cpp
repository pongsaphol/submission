#include <bits/stdc++.h>
#define iii tuple<int, int, int>
using namespace std;

const int N = 105;
const long M = 1e9+7;

int n, m;
int A[N];
unordered_map<int, long> dp[N][N];
unordered_map<int, bool> dd[N][N];
long ans;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    dp[0][0][0] = 1;
    queue<iii> Q; Q.emplace(0, 0, 0);
    while(!Q.empty()) {
        auto z = Q.front(); Q.pop();
        int a, b, c; tie(a, b, c) = z;
        int mx = max({a, b, c});
        if(mx == n) {
            ans = (ans + dp[a][b][c]) % M;
            continue;
        }
        mx++;
        if(a == 0 || abs(A[a] - A[mx]) <= m) {
            dp[mx][b][c] = (dp[mx][b][c] + dp[a][b][c]) % M;
            if(!dd[mx][b][c]) {
                Q.emplace(mx, b, c);
                dd[mx][b][c] = true; 
            }
        }
        if(b == 0 || abs(A[b] - A[mx]) <= m) {
            dp[a][mx][c] = (dp[a][mx][c] + dp[a][b][c]) % M;
            if(!dd[a][mx][c]) {
                Q.emplace(a, mx, c);
                dd[a][mx][c] = true; 
            }
        }
        if(c == 0 || abs(A[c] - A[mx]) <= m) {
            dp[a][b][mx] = (dp[a][b][mx] + dp[a][b][c]) % M;
            if(!dd[a][b][mx]) {
                Q.emplace(a, b, mx);
                dd[a][b][mx] = true; 
            }
        }
    }
    printf("%lld\n", ans);
}