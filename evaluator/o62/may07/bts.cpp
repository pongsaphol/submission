#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int INF = 1e9;
const int N = 3005;

int n, m;
int a, b;
pii E[N];
int sz[N], W[N];
int cost[N][N];
int cnt;
vector<int> coor;
int pos[N];
int dp[N][N];


int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d", &a, &b);
    if(a > b) swap(a, b);
    
    for(int i = 1, u, v; i <= m; ++i) {
        scanf("%d %d %d", &u, &v, &W[i]);
        if(W[i] <= a) return !printf("-1\n");
        if(u > v) swap(u, v);
        E[i] = pii(u, v);
        coor.emplace_back(u), coor.emplace_back(v);
    }
    for(int i = 1; i <= m; ++i) if(W[i] <= b) cnt++;
    if(cnt == 0) return !printf("%d\n", (n-1) * b);
    sort(coor.begin(), coor.end());
    coor.resize(unique(coor.begin(), coor.end()) - coor.begin());
    for(int i = 0; i < coor.size(); ++i) pos[coor[i]] = i+1;
    for(int i = 1; i <= m; ++i) E[i] = pii(pos[E[i].x], pos[E[i].y]);
    for(int i = 1; i <= coor.size(); ++i) for(int j = i; j <= coor.size(); ++j) {
        for(int k = 1; k <= m; ++k) if(E[k].x >= i && E[k].y <= j) cost[i][j]++;
    } 
    int mn = 1e9;
    for(int i = 1; i <= m; ++i) {
        dp[i][0] = INF;
        for(int j = 1; j <= coor.size(); ++j) {
            dp[i][j] = dp[i][j-1];
            for(int k = j; k; --k) {
                int dis = coor[j-1] - coor[k-1];
                if(cost[k][j] <= i) dp[i][j] = min(dp[i][j], dp[i-cost[k][j]][k] + coor[j-1] - coor[k-1]);
                else break;
            }
        }
        if(i >= cnt) mn = min(mn, dp[i][coor.size()]);
    }
    printf("%d\n", (n-1-mn) * b + mn * a);
}