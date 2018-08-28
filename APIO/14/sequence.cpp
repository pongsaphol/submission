#include <bits/stdc++.h>
using namespace std;

#define long long long
#define ll pair<long, long>
#define x first
#define y second

const int N = 1e5+5;

struct data {
    long m, c;
    int idx;
    data() { }
    data(long m, long c, int idx) : m(m), c(c), idx(idx) { }
};

struct Convex_Hull {
    vector<data> vec;
    int ptr = 0;
    bool del(data l0, data l1, data ln) { 
        return (l1.c - l0.c) * (l0.m - ln.m) >= (ln.c - l0.c) * (l0.m - l1.m);
    }
    void add(data d) {
        while(vec.size() > 1 && del(vec[vec.size()-2], vec.back(), d)) vec.pop_back();
        while(!vec.empty() && vec.back().m == d.m && vec.back().c <= d.c) vec.pop_back();
        vec.emplace_back(d);
    }
    long get(int pos, long x) { return vec[pos].m * x + vec[pos].c; }
    ll query(long x) {
        if(ptr >= vec.size()) ptr = vec.size() - 1;
        while(ptr+1 < vec.size() && get(ptr, x) <= get(ptr+1, x)) ptr++;
        return ll(get(ptr, x), vec[ptr].idx);
    }
    void clear() {
        vec.clear();
        ptr = 0;
    }
};

int n, k;
long dp[2][N];
int s[201][N];
long pref[N];

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i) scanf("%lld", pref+i), pref[i] += pref[i-1];
    Convex_Hull hull;
    for(int i = 1; i <= k; ++i) {
        hull.clear();
        for(int j = i+1; j <= n; ++j) {
            hull.add(data(pref[j-1], dp[~i&1][j-1] - pref[j-1] * pref[j-1], j-1));
            tie(dp[i&1][j], s[i][j]) = hull.query(pref[j]);
        }
    }
    printf("%lld\n", dp[k&1][n]);
    for(int i = k, z = n; i; --i) printf("%d ", z = s[i][z]);
}