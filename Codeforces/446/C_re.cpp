#include <bits/stdc++.h>
using namespace std;

#define long long long
#define pii pair<int, int>
#define x first
#define y second

#define all int p = 1, int l = 1, int r = n
#define mid (l+r>>1)
#define lb p<<1, l, mid
#define rb p<<1|1, mid+1, r

const int N = 1<<19;
const int M = 1e9+9;

int n, m, A[N], t[N<<1];
pii fib[N] = {{1, 0}, {0, 1}};
pii pff[N] = {{1, 0}};
pii lz[N<<1];

pii add(pii a, pii b) { return pii((a.x + b.x) % M, (a.y +  b.y) % M); }
int getVal(pii a, pii b) { return (1ll*a.x*b.x + 1ll*a.y*b.y) % M; }
pii ith(pii a, int x) { return pii(getVal(a, fib[x]), getVal(a, fib[x+1])); }

void push(all) {
    if(lz[p] == pii(0, 0)) return;
    t[p] = (t[p] + getVal(lz[p], pff[r-l])) % M;
    if(l != r) lz[p<<1] = add(lz[p<<1], lz[p]), lz[p<<1|1] = add(lz[p<<1|1], ith(lz[p], mid-l+1));
    lz[p] = pii(0, 0);
}

void build(all) {
    if(l == r) return void(scanf("%d", t+p));
    build(lb), build(rb);
    t[p] = (t[p<<1] + t[p<<1|1]) % M;
}

void update(int x, int y, all) {
    push(p, l, r);
    if(x > r || l > y) return; 
    if(x <= l && r <= y) { lz[p] = ith(pii(1, 1), l-x), push(p, l, r); return; } 
    update(x, y, lb), update(x, y, rb);
    t[p] = (t[p<<1] + t[p<<1|1]) % M;
}

int query(int x, int y, all) {
    push(p, l, r);
    if(x > r || l > y) return 0;
    if(x <= l && r <= y) return t[p];
    return (query(x, y, lb) + query(x, y, rb)) % M;
}

int main() {
    for(int i = 2; i < N; ++i) fib[i] = add(fib[i-1], fib[i-2]);    
    for(int i = 1; i < N; ++i) pff[i] = add(pff[i-1], fib[i]);
    scanf("%d %d", &n, &m);
    build();
    for(int i = 0, a, b, c; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1) update(b, c);
        else printf("%d\n", query(b, c));
    }
}