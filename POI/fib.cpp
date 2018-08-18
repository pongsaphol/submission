#include <bits/stdc++.h>
using namespace std; 

#define pii pair<int, int>
#define x first
#define y second
#define all int p = 1, int l = 1, int r = n
#define lb p<<1, l, (l+r>>1)
#define rb p<<1|1, (l+r>>1) + 1, r 

const int N = 1<<17;
const int M = 1e9+7;

int n, m, lz[N<<1];
pii fib[N] = {{0, 1}, {1, 1}};
pii t[N<<1];

pii add(pii a, pii b) { return pii((a.x + b.x) % M, (a.y + b.y) % M); }

void build(all) {
    t[p] = pii(0, r-l+1);
    if(l == r) return;
    build(lb), build(rb);
}

void push(all) {
    if(!lz[p]) return;
    t[p] = pii((1ll*t[p].x*fib[lz[p]-1].x + 1ll*t[p].y*fib[lz[p]-1].y) % M, 
        (1ll*t[p].x*fib[lz[p]].x + 1ll*t[p].y*fib[lz[p]].y) % M);
    if(l != r) lz[p<<1] += lz[p], lz[p<<1|1] += lz[p];
    lz[p] = 0;
}

void update(int x, int y, all) {
    push(p, l, r);
    if(x <= l && r <= y) { lz[p]++, push(p, l, r); return; }
    if(x > r || l > y) return;
    update(x, y, lb), update(x, y, rb);
    t[p] = add(t[p<<1], t[p<<1|1]);
}

int query(int x, int y, all) {
    push(p, l, r);
    if(x <= l && r <= y) return t[p].x;
    if(x > r || l > y) return 0;
    return (query(x, y, lb) + query(x, y, rb)) % M; 
}

int main() {
    for(int i = 2; i < N; ++i) fib[i] = add(fib[i-1], fib[i-2]);
    scanf("%d %d", &n, &m);
    build();
    for(int i = 0, a, b; i < m; ++i) {
        char c; scanf(" %c %d %d", &c, &a, &b);
        if(c == 'D') update(a, b);
        else printf("%d\n", query(a, b));
    }
}