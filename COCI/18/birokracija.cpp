#include <bits/stdc++.h>
using namespace std;

#define long long long

const int N = 2e5+5;

int n;
long ans[N];
vector<int> g[N];

void dfs(int u) {
    for(int v : g[u]) dfs(v), ans[u] += ans[v]; 
}

int main() {
    fill_n(ans, N, 1);
    scanf("%d", &n);
    for(int i = 2, p; i <= n; ++i) {
        scanf("%d", &p);
        g[p].emplace_back(i);
    }
    dfs(1), dfs(1);
    for_each(ans+1, ans+n+1, [](long x) { printf("%lld ", x); });
}