#include <bits/stdc++.h>
using namespace std;

#define long long long

const int N = 3e5+5;
const int bit = 5;

int n, m, k, col[N];
long d[N][1<<bit];
vector<int> g[N], eb[bit+1];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; ++i) scanf("%d", col+i), col[i]--;
    for(int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v);
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    for(int i = 0; i < (1<<k); ++i) {
        int cnt = 0;
        for(int j = 0; j < k; ++j) if(i >> j & 1) cnt++;
        eb[cnt].emplace_back(i);
    }
    for(int i = 1; i <= n; ++i) d[i][1<<col[i]] = 1;
    long sum = 0;
    for(int i = 2; i <= k; ++i) for(auto x : eb[i]) {
        for(int i = 1; i <= n; ++i) {
            if(x & (1 << col[i])) for(auto v : g[i]) d[i][x] += d[v][x ^ (1<<col[i])]; 
            sum += d[i][x];
        }
    }
    printf("%lld\n", sum);
}
