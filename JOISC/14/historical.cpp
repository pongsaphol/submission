#include <bits/stdc++.h>
using namespace std;

#define long long long
#define iii tuple<int, int, int>
#define pii pair<int, int>
#define x first
#define y second

const int N = 1e5+5;

int n, q, A[N], freq[N];
long ans[N], t[N<<1];
vector<int> coor;

int main() {
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i), coor.emplace_back(A[i]);
    int sz = sqrt(n) + 1;
    coor.emplace_back(0);
    sort(coor.begin(), coor.end());
    coor.resize(unique(coor.begin(), coor.end()) - coor.begin());
    vector<iii> block[sz];
    for(int i = 0, a, b; i < q; ++i) {
        scanf("%d %d", &a, &b);
        block[a/sz].emplace_back(a, b, i);
    }
    for(int i = 0; i < sz; ++i) sort(block[i].begin(), block[i].end(), [&](const iii &a, const iii &b) { return get<1>(a) < get<1>(b); });
    for(int i = 0; i < sz; ++i) {
        int l = i*sz, r = i*sz;
        memset(t, 0, sizeof t), memset(freq, 0, sizeof freq);
        auto f = [&](int p, int v) { 
            p = A[p];
            int z = lower_bound(coor.begin(), coor.end(), p) - coor.begin();
            freq[z] += v;
            for(t[z += (int)coor.size()] = 1ll * freq[z] * p; z != 1; z >>= 1) t[z>>1] = max(t[z], t[z^1]);
        };
        for(auto z : block[i]) {
            int x, y, v; tie(x, y, v) = z;
            while(r <= y) f(r++, 1);
            while(l < x) f(l++, -1);
            while(l > x) f(--l, 1);
            ans[v] = t[1];
        }
    }
    for(int i = 0; i < q; ++i) printf("%lld\n", ans[i]);
}
