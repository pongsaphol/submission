#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 2e5+5;

int n, x, A[N], pos[N];
int ret[N], t[N<<1];

void update(int x, int v) {
    for(t[x+=n] = v; x != 1; x >>= 1) t[x>>1] = max(t[x], t[x^1]);
}

int query(int r) {
    int l = 0, mx = 0;
    for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
        if(l & 1) mx = max(mx, t[l++]);
        if(r & 1) mx = max(mx, t[--r]);
    }
    return mx;
}

int main() {
    scanf("%d %d", &n, &x);
    vector<int> V, Z;
    vector<pii> ret;
    for(int i = 1; i <= n; ++i) scanf("%d", A+i), Z.emplace_back(A[i]), ret.emplace_back(A[i], i);
    sort(ret.begin(), ret.end()), sort(Z.begin(), Z.end());
    for(int i = 0; i < n; ++i) pos[ret[i].y] = i;
    for(int i = 1; i <= n; ++i) {
        auto it = lower_bound(V.begin(), V.end(), A[i]);
        if(it == V.end()) V.emplace_back(A[i]), it = V.end(), it--;
        else *it = A[i];
        update(pos[i], it - V.begin() + 1);
    }
    V.clear();
    int mx = 0;
    for(int i = n; i; --i) {
        update(pos[i], 0);
        auto it = lower_bound(V.begin(), V.end(), -A[i]);
        if(it == V.end()) V.emplace_back(-A[i]), it = V.end(), it--;
        else *it = -A[i];
        int z = it - V.begin() + 1; 
        mx = max(mx, z + query(lower_bound(Z.begin(), Z.end(), A[i]+x) - Z.begin()-1));
    }
    printf("%d\n", mx);
}