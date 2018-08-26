#include "aliens.h"
#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define long long long
#define pii pair<int, int>
#define x first
#define y second

vector<pii> V;

void compress() {
    sort(all(V), [](pii a, pii b) { if(a.x == b.x) return a.y > b.y; return a.x < b.x; });
    int en = -1;
    vector<pii> ret;
    for(auto x : V) if(x.y > en) en = x.y, ret.emplace_back(x);
    V = ret;
}

struct cht {
    struct line {
        long m, c;
        int cnt;
        line(long m, long c, int cnt) : m(m), c(c), cnt(cnt) {}
        long get(long x) { return m * x + c; }
    };
    vector<line> f;
    bool bad(line l1, line l2, line l3) {
        return (l1.c - l3.c) * (l2.m - l1.m) <= (l3.m - l1.m) * (l1.c - l2.c);
    }
    void update(long m, long c, int cnt) {
        line l(m, c, cnt);
        while(f.size() >= 2 and bad(f[f.size()-2], f[f.size()-1], l)) f.pop_back();
        f.emplace_back(l);
    }
    int idx;
    pair<long, int> query(long x) {
        while(idx + 1 < f.size() and f[idx+1].get(x) < f[idx].get(x)) ++idx;
        return make_pair(f[idx].get(x), f[idx].cnt);
    }
    void clear() {
        f.clear(), idx = 0;
    }
} hull;

long sq(long x) { return x * x; }

pair<long, int> f(long C) {
    vector<pair<long, int> > dp(V.size()+1);
    hull.clear();
    hull.update(-2*(V[0].x-1), sq(V[0].x-1), 0);
    for(int i = 1; i <= V.size(); ++i) {
        auto ret = hull.query(V[i-1].y);
        dp[i] = make_pair(ret.x + sq(V[i-1].y) + C, ret.y + 1);
        if(i != V.size())  
            hull.update(-2*(V[i].x-1), sq(V[i].x-1) + dp[i].x - sq(max(0, V[i-1].y - V[i].x + 1)), dp[i].y); 
    }
    return dp.back();
}

long take_photos(int n, int m, int k, vector<int> _r, vector<int> c) {
    for(int i = 0; i < n; ++i) V.emplace_back(min(_r[i], c[i]), max(_r[i], c[i]));
    compress();
    long l = 0, r = 1e12;
    while(l < r) {
        long m = l + r >> 1;
        if(f(m).y <= k) r = m;
        else l = m+1;
    }
    return f(r).x - r*k;
}
