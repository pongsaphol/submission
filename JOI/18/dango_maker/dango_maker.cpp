#include <bits/stdc++.h>
using namespace std;

const int N = 3e3+5;

int n, m;

char A[N][N];
vector<bool> V[2][N<<1];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%s", A[i]+1);
    for(int i = 2; i <= n+m; ++i) V[0][i].resize(3), V[1][i].resize(3);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
        bool st = false, st2 = false;
        if(A[i][j] == 'R' and A[i+1][j] == 'G' and A[i+2][j] == 'W') st = true;
        if(A[i][j] == 'R' and A[i][j+1] == 'G' and A[i][j+2] == 'W') st2 = true;
        V[0][i+j].emplace_back(st);
        V[1][i+j].emplace_back(st2);
    }
    int sum = 0;
    for(int i = 2; i <= n+m; ++i) {
        vector<int> dp[2];
        dp[0].resize(V[0][i].size());
        dp[1].resize(V[1][i].size());
        for(int j = 2; j < V[0][i].size(); ++j) {
            dp[0][j] = V[0][i][j] + max(dp[0][j-1], dp[1][j-1]);
            dp[1][j] = V[1][i][j] + max(dp[1][j-1], dp[0][j-3]);
        }
        sum += max(dp[0].back(), dp[1].back());
    }
    printf("%d\n", sum);
}
