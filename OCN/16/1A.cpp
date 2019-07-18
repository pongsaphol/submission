#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 40;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;
long sum;
int cost[N][N];
bool visit[N][N];
char re[N];
vector<long> vec;

void dfs(int x, int y) {
    if(x <= 0 || x > n || y <= 0 || y > m) return;
    if(x == n && y == m) {
        vec.emplace_back(sum + cost[n][m]); 
        return;
    }
    if(visit[x][y]) return;
    visit[x][y] = true, sum += cost[x][y];
    for(int i = 0; i < 4; ++i) {
        dfs(x + dx[i], y + dy[i]);
    }
    visit[x][y] = false, sum -= cost[x][y];
}

int main() {
    scanf("%s", re);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) scanf("%d", &cost[i][j]);
    dfs(1, 1);
    sort(vec.begin(), vec.end());
    int q; scanf("%d", &q);
    for(int i = 0; i < q; ++i) {
        long a, b; scanf("%lld %lld", &a, &b);
        int v = upper_bound(vec.begin(), vec.end(), b) - lower_bound(vec.begin(), vec.end(), a);
        printf("%d\n", v);
    }
}