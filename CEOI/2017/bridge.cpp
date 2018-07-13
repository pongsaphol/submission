#include <bits/stdc++.h>
#define long long long
using namespace std;

const long INF = 1e18;
const int N = 1e5+5, M = 1e6, MXN = 1<<20;

struct line {
    long k, b;
    line(long k = 0, long b = INF) : k(k), b(b) { }
    long get(long x) { return k*x + b; }
} t[MXN<<1];

int n;
long dp[N], h[N], w[N];
bitset<MXN<<1> vis;

void update(line x, int p = 1, int l = 0, int r = M) {
    if(!vis[p]) { vis[p] = true, t[p] = x; return; }
    if(t[p].get(l) < x.get(l) && t[p].get(r) < x.get(r)) return;
    if(t[p].get(l) > x.get(l) && t[p].get(r) > x.get(r)) { t[p] = x; return; }
    int m = (l + r) >> 1;
    if(t[p].get(l) > x.get(l)) swap(t[p], x);
    if(l == r) return;
    if(t[p].get(m) > x.get(m)) swap(t[p], x), update(x, p<<1, l, m);
    else update(x, p<<1|1, m+1, r);
}

long query(long pos, int p = 1, int l = 0, int r = M) {
    if(l == r) return t[p].get(pos);
    int m = (l + r) >> 1;
    long ans = t[p].get(pos);
    if(pos <= m) ans = min(ans, query(pos, p<<1, l, m));
    else ans = min(ans, query(pos, p<<1|1, m+1, r));
    return ans;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%lld", h+i);
    for(int i = 1; i <= n; ++i) scanf("%lld", w+i), w[i] += w[i-1];
    for(int i = 1; i <= n; ++i) {
        if(i != 1) dp[i] = h[i]*h[i] + w[i-1] + query(h[i]); 
        update(line(-2*h[i], dp[i] + h[i]*h[i] - w[i]));
    }
    printf("%lld\n", dp[n]);
}