#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 1e6+5;
const int M = 1e9+7;

int n, cnt, dsu[N<<1];
vector<pii> V;

int find(int x) { return dsu[x] = dsu[x] == x ? x : find(dsu[x]);}
void mge(int x, int y) { dsu[find(x)] = find(y); }

int main() {
    scanf("%d", &n);
    V.reserve(n);
    iota(dsu, dsu+2*N, 0);
    for(int i = 0, a, b; i < n; ++i) scanf("%d %d", &a, &b), V.emplace_back(a, b);
    sort(V.begin(), V.end());
    map<int, int> pos;
    for(int i = 0; i < n; ++i) {
        auto it = pos.lower_bound(V[i].x), zz = pos.upper_bound(V[i].y);
        bool st = it != zz;
        if(zz != pos.begin()) zz--;
        if(st) for(;; ++it) {
            mge(i, it->y+n), mge(i+n, it->y); 
            if(find(it->y) == find(zz->y)) break;
            if(it == zz) break;
        }
        pos[V[i].y] = i;
    }
    for(int i = 0; i < n; ++i) if(find(i) == find(i+n)) return puts("0"), 0;
    int ans = 1;
    for(int i = 0; i < n; ++i) if(find(i) == i) ans = ans * 2 % M;
    printf("%d\n", ans);
}
