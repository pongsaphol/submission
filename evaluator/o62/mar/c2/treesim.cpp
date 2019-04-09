#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 2e5+5;

int n;
vector<vector<int> > g(N);
pii dp[N];

pii add(pii a, pii b) { return pii(a.x + b.x, a.y + b.y); }
pii sub(pii a, pii b) { return pii(a.x - b.x, a.y - b.y); }

set<pii> s;
pii fll;

pii dfs(int u, int p) {
    if(u <= n) return dp[u];
    pii ret(0, 0);
    for(int v : g[u]) if(v != p) ret = add(ret, dfs(v, u));
    s.emplace(ret);
    return ret;
}

int cnt;

pii dfs2(int u, int p) {
    if(u <= n) return dp[u];
    pii ret(0, 0);
    for(int v : g[u]) if(v != p) ret = add(ret, dfs2(v, u));
    if(s.find(ret) == s.end() && s.find(sub(fll, ret)) == s.end()) cnt++;
    return ret;
}

int main() {
    scanf("%d", &n);
    dp[0] = pii(1, 1);
    for(int i = 1; i <= n; ++i) dp[i] = pii(dp[i-1].x * 2, dp[i-1].y * 3), fll = add(fll, dp[i]);
    for(int i = 0, u, v; i < 2*n-3; ++i) {
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    dfs(n+1, 0);
    g.clear(); g.resize(N);
    for(int i = 0, u, v; i < 2*n-3; ++i) {
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    dfs2(n+1, 0);
    printf("%d\n", cnt);
}
/*
5
1 8
2 6
3 6
6 8
8 7
7 4
5 7
1 8
8 5
7 8
2 6
6 3
4 7
6 7
*/
