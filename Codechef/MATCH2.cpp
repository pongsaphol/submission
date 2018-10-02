#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

struct data {
    int sum, lazy;
    vector<int> V;
    data() : sum(0), lazy(0) {}
    void clear() { V.clear(), sum = lazy = 0; }
    friend inline data operator+(const data &a, const data &b) {
        data ret;
        merge(all(a.V), all(b.V), back_inserter(ret.V));
        ret.sum = a.sum + b.sum;
        return ret;
    }
};

const int N = 1<<17;

int n, m;
int A[N], B[N];

data t[N<<1];

#define var int p = 1, int l = 1, int r = n
#define mid (l + r >> 1)
#define lb p<<1, l, mid
#define rb p<<1|1, mid+1, r

void build(var) {
    t[p].clear();
    if(l == r) {
        t[p].V.emplace_back(B[l]);
        t[p].sum = (A[l] == B[r]);
        return;
    }
    build(lb), build(rb);
    t[p] = t[p<<1] + t[p<<1|1]; 
}

void push(var) {
    if(t[p].lazy) {
        t[p].sum = upper_bound(all(t[p].V), t[p].lazy) - lower_bound(all(t[p].V), t[p].lazy);
        if(l != r) t[p<<1].lazy = t[p<<1|1].lazy = t[p].lazy;
        t[p].lazy = 0;
    }
}

void update(int x, int y, int v, var) {
    push(p, l, r);
    if(x > r || l > y) return;
    if(x <= l && r <= y) { t[p].lazy = v, push(p, l, r); return; }
    update(x, y, v, lb), update(x, y, v, rb);
    t[p].sum = t[p<<1].sum + t[p<<1|1].sum;
}

void solve() {
    scanf("%d %d", &n, &m); 
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    for(int i = 1; i <= n; ++i) scanf("%d", B+i);
    build();
    int p = t[1].sum;
    for(int i = 0, l, r, v; i < m; ++i) {
        scanf("%d %d %d", &l, &r, &v);
        l ^= p, r ^= p, v ^= p;
        update(l, r, v);
        printf("%d\n", p = t[1].sum);
    }
}

int main() {
    int T; scanf("%d", &T);
    while(T--) solve();
}
