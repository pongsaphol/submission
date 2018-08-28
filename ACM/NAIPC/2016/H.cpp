#include <bits/stdc++.h>
using namespace std;

#define long long long
#define pii pair<long, int>
#define x first
#define y second

const int N = 1e5+5;
const int M = 305;

int n, m;
vector<int> V[M];
long dp[N], ptr[N][M];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0, a, b; i < n; ++i) {
        scanf("%d %d", &a, &b);
        V[a].emplace_back(b);
    }
    for(int i = 1; i <= 300; ++i) sort(V[i].begin(), V[i].end(), greater<int>());
    for(int i = 1; i <= m; ++i) {
        pii mx;
        for(int j = 1; j <= min(i, 300); ++j) if(ptr[i-j][j] != V[j].size()) {
            long val = dp[i-j] + V[j][ptr[i-j][j]];
            if(val > mx.x) mx = pii(val, j); 
        }
        dp[i] = mx.x;
        for(int j = 1; j <= 300; ++j) ptr[i][j] = ptr[i-mx.y][j];
        ptr[i][mx.y]++;
    }
    for(int i = 1; i <= m; ++i) printf("%lld ", dp[i] = max(dp[i-1], dp[i]));
}