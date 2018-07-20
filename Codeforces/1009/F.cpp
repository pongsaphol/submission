#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e6+5;

int n, ans[N];
vector<int> g[N];

struct item {
    pii mx;
    map<int, int> cnt;
    item(int d) {
        cnt[d] = 1;
        mx = pii(1, -d);
    }
};

item *dfs(int u, int p, int d) {
    item *big = new item(d);
    for(auto v : g[u]) if(v != p) {
        item *ret = dfs(v, u, d+1);
        if(big->cnt.size() < ret->cnt.size()) swap(big, ret);
        for(auto x : ret->cnt) {
            big->cnt[x.x]  += x.y;
            big->mx = max(big->mx, pii(big->cnt[x.x], -x.x));
        }
    }
    ans[u] = -big->mx.y - d;
    return big;
}

int main() {
    scanf("%d", &n);
    for(int i = 1, a, b; i < n; ++i) {
        scanf("%d %d", &a, &b);
        g[a].emplace_back(b), g[b].emplace_back(a);
    }
    dfs(1, 0, 0);
    for(int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
}