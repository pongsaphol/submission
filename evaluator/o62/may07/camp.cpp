#include <bits/stdc++.h>
#define iii tuple<int, int, int>
#define long long long
using namespace std;

const int N = 1<<18;

int n;
iii edge[N];
int val[N];
int t[N<<1];
long ans;
long dp[N];
int pmx[N];

int main() {
    scanf("%d", &n);
    for(int i = 1, a, b, c; i <= n; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        edge[i] = tie(a, b, c);
    }
    sort(edge+1, edge+1+n, [&](const iii &a, const iii &b) {
        return get<1>(a) < get<1>(b);
    });
    for(int i = 1; i <= n; ++i) t[i+N] = get<2>(edge[i]), val[i] = get<1>(edge[i]);
    for(int i = N-1; ~i; --i) t[i] = max(t[i<<1], t[i<<1|1]);
    auto query = [&](int l, int r) {
        int mx = 0;
        for(l += N, r += N+1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) mx = max(mx, t[l++]);
            if(r & 1) mx = max(mx, t[--r]);
        }
        return mx;
    };
    for(int i = 1; i <= n; ++i) {
        int pos = lower_bound(val, val+n+1, get<0>(edge[i])) - val - 1;
        long z = dp[pos] + get<2>(edge[i]);
        if(dp[i-1] >= z) {
            dp[i] = dp[i-1], pmx[i] = max(pmx[i-1], get<2>(edge[i]));
        } else {
            dp[i] = dp[pos] + get<2>(edge[i]);
            pmx[i] = max(pmx[pos], query(pos+1, i-1));
        }
        ans = max(ans, dp[i] + pmx[i]);
    }
    printf("%lld\n", ans);
}