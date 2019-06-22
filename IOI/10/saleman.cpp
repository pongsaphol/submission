#include <bits/stdc++.h>
#define long long long
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const long INF = 1e12;

const int N = 1<<19;

int n, u, d, s;
long t1[N<<1], t2[N<<1];

void update(long t[], int x, long v) {
    x += N;
    for(t[x] = max(t[x], v); x != 1; x >>= 1) t[x>>1] = max(t[x], t[x^1]);
}

long query(long t[], int l, int r) {
    long mx = -INF;
    for(l += N, r += N+1; l < r; l >>= 1, r >>= 1) {
        if(l & 1) mx = max(mx, t[l++]);
        if(r & 1) mx = max(mx, t[--r]);
    }
    return mx;
}

long p;

void updcost(long a, long b) {
    update(t1, a, b - p * a);
    update(t2, a, b + p * a);
}

long getcost(long a) {
    long vl = (query(t1, a, N-1) + p * a);
    long vr = (query(t2, 0, a) - p * a);
    return max(vl, vr);
}

long dp1[N], dp2[N], pref[N], suff[N], cost[N];
vector<pii> Mp[N];

int main() {
    fill_n(t1, N<<1, -INF);
    fill_n(t2, N<<1, -INF);
    scanf("%d %d %d %d", &n, &u, &d, &s);
    p = u+d;
    for(int i = 0, a, b, c; i < n; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        Mp[a].emplace_back(b, c << 1);
    }
    updcost(s, 0);
    for(int i = 0; i < N; ++i) if(Mp[i].size()) { // pos, cost
        vector<pii> &now = Mp[i];
        int n = now.size();
        sort(all(now));
        for(int i = 0; i < n; ++i) cost[i] = getcost(now[i].x) + now[i].y;
        dp1[0] = pref[0] = now[0].y;
        for(int i = 1; i < n; ++i) {
            dp1[i] = max(dp1[i-1] - 2 * p * (now[i].x - now[i-1].x), 0ll) + now[i].y;
            pref[i] = pref[i-1] + now[i].y - p * (now[i].x - now[i-1].x);
        }
        dp2[n-1] = suff[n-1] = now[n-1].y;
        for(int i = n-2; i >= 0; --i) {
            dp2[i] = max(dp2[i+1] - 2 * p * (now[i+1].x - now[i].x), 0ll) + now[i].y;
            suff[i] = suff[i+1] + now[i].y - p * (now[i+1].x - now[i].x); 
        }
        long premax = -INF;
        for(int i = 0; i < n; ++i) {
            if(i) cost[i] = max(cost[i], dp2[i] - now[i].y + pref[i] + premax);
            premax = max(premax, dp1[i] - pref[i] + getcost(now[i].x));
        }
        premax = -INF;
        for(int i = n-1; i >= 0; --i) {
            if(i != n-1) cost[i] = max(cost[i], dp1[i] - now[i].y + suff[i] + premax);
            premax = max(premax, dp2[i] - suff[i] + getcost(now[i].x));
        }
        for(int i = 0; i < n; ++i) {
            updcost(now[i].x, cost[i]);
            // cerr << now[i].x << " " << now[i].y << " -> " << cost[i] << endl;
        }
    }
    printf("%lld\n", getcost(s) >> 1);

}

