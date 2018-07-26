#include <bits/stdc++.h>
using namespace std;

#define long long long
#define iii tuple<int, int, int>
#define pii pair<int, int>
#define x first
#define y second

const int N = 1<<17;

int n, m, A[N];
long t[N<<1];
vector<pii> pref[N<<1], suff[N<<1];

long getMerge(vector<pii> &L, vector<pii> &R, int l, int r, int m) {
    long sum = 0;
    for(int i = 0, j = L.size()-1; i < R.size(); ++i) {
        while(j >= 0 && __gcd(L[j].x, R[i].x) == 1) j--;
        if(j < 0) continue;
        long ret = m - (j < L.size()-1 ? L[j+1].y : l-1);
        ret *= (i < R.size()-1 ? R[i+1].y : r+1) - R[i].y;
        sum += ret; 
    }
    return sum;
}

vector<pii> Merge(vector<pii> &L, vector<pii> &R) {
    vector<pii> ret = L;
    for(int i = 0; i < R.size(); ++i) {
        int gcd = __gcd(L.back().x, R[i].x);
        if(gcd != ret.back().x) ret.emplace_back(gcd, R[i].y);
    }
    return ret;
}

void MergeAll(int p, int l, int r) {
    int m = l + r >> 1;
    t[p] = t[p<<1] + t[p<<1|1] + getMerge(suff[p<<1], pref[p<<1|1], l, r, m);
    pref[p] = Merge(pref[p<<1], pref[p<<1|1]);
    suff[p] = Merge(suff[p<<1|1], suff[p<<1]);
}

void build(int p = 1, int l = 1, int r = n) {
    if(l == r) {
        scanf("%d", A+l);
        pref[p].emplace_back(A[l], l);
        suff[p].emplace_back(A[r], r);
        t[p] = A[l] > 1;
        return;
    }
    int m = l + r >> 1;
    build(p<<1, l, m), build(p<<1|1, m+1, r);
    MergeAll(p, l, r);
}

void update(int x, int v, int p = 1, int l = 1, int r = n) {
    if(l == r) {
        pref[p][0] = suff[p][0] = pii(A[l] = v, r);
        t[p] = A[l] > 1;
        return;
    }
    int m = l + r >> 1;
    if(x <= m) update(x, v, p<<1, l, m);
    else update(x, v, p<<1|1, m+1, r);
    MergeAll(p, l, r);
}

vector<iii> query(int x, int y, int p = 1, int l = 1, int r = n) {
    if(x > r || l > y) return vector<iii>();
    if(x <= l && r <= y) return vector<iii>(1, make_tuple(p, l, r));
    int m = l + r >> 1;
    vector<iii> ret = query(x, y, p<<1, l, m);
    for(auto x : query(x, y, p<<1|1, m+1, r)) ret.emplace_back(x);
    return ret;
}

long get(int x, int y) {
    vector<iii> ret = query(x, y);
    vector<pii> rsuff;
    long sum = 0;
    int p, l, r;
    for(auto x : ret) {
        tie(p, l, r) = x;
        sum += t[p] + getMerge(rsuff, pref[p], get<1>(ret[0]), r, l-1);
        rsuff = Merge(suff[p], rsuff);
    }
    return sum;
}

int main() {
    scanf("%d %d", &n, &m);
    build();
    for(int i = 0, a, b, c; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1) update(b, c);
        else printf("%lld\n", get(b, c));
    }
}