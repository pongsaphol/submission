#include <bits/stdc++.h>
using namespace std;

const int N = 1<<18;
const int INF = 1e9;

int n, m, t[N<<1];

void update(int x, int v) {
    for(t[x += N] = v; x != 1; x >>= 1) t[x>>1] = min(t[x], t[x^1]); 
}

int query(int x, int v, int p = 1, int l = 0, int r = N - 1) {
    if(t[p] > v) return INF;
    if(l == r) return l;
    int m = l + r >> 1;
    if(x <= m) {
        int z = query(x, v, p<<1, l, m);
        if(z != INF) return z;
    }
    if(x <= r) {
        int z = query(x, v, p<<1|1, m+1, r);
        if(z != INF) return z;
    }
    return INF;
}

int main() {
    fill_n(t, N<<1, INF);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        char c; int a, b; scanf(" %c %d %d", &c, &a, &b);
        if(c == 'M') update(b, a);
        else {
            int ret = query(b, a);
            printf("%d\n", ret == INF ? -1 : ret);
        }
    }
}