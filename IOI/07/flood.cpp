#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
 
const int N = 2e5+5;
 
int n, m;
int x[N>>1], y[N>>1];
int s[N], t[N];
int za[N], zb[N];
bitset<4> state[N];
bitset<N> check;
int idx;
vector<pii> coor;
vector<int> ss;
vector<vector<int> > zzz(N>>1);
 
int par[N<<1];
 
int find(int u) { return par[u] = par[u] == u ? u : find(par[u]); }
 
int Mp(pii x) {
    return upper_bound(coor.begin(), coor.end(), x) - coor.begin();
}
 
void merge(int a, int b, int c, int d) {
    int u = Mp(pii(a, b)), v = Mp(pii(c, d));
    par[find(u)] = find(v);
}

int main() {
    iota(par, par+(N<<1), 0);
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d %d", x+i, y+i);
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) scanf("%d %d", s+i, t+i), s[i]--, t[i]--;
    for(int i = 0; i < m; ++i) zzz[s[i]].emplace_back(t[i]), zzz[t[i]].emplace_back(s[i]);
    for(int i = 0; i < n; ++i) if(check[i] == false) {
        queue<int> Q;
        Q.emplace(i);
        int mny = 1e9, st;
        check[i] = true;
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            if(x[u] < mny) mny = x[u], st = u;
            for(int v : zzz[u]) if(!check[v]) check[v] = true, Q.emplace(v);
        }
        ss.emplace_back(st);
    }
    zzz.clear();
    for(int i = 0; i < n; ++i) {
        check[i] = false;
        coor.emplace_back(x[i], y[i]);
        coor.emplace_back(x[i]+1, y[i]);
        coor.emplace_back(x[i], y[i]+1);
        coor.emplace_back(x[i]+1, y[i]+1);
    }
    sort(coor.begin(), coor.end());
    coor.resize(unique(coor.begin(), coor.end()) - coor.begin());
    for(int i = 0; i < m; ++i) {
        if(x[s[i]] > x[t[i]]) swap(s[i], t[i]);
        if(y[s[i]] > y[t[i]]) swap(s[i], t[i]);
        if(x[s[i]] != x[t[i]]) {
            state[s[i]][1] = state[t[i]][3] = true;
            merge(x[s[i]]+1, y[s[i]], x[t[i]], y[t[i]]);
            merge(x[s[i]]+1, y[s[i]]+1, x[t[i]], y[t[i]]+1);            
        } else {
            state[s[i]][0] = state[t[i]][2] = true;
            merge(x[s[i]], y[s[i]]+1, x[t[i]], y[t[i]]);
            merge(x[s[i]]+1, y[s[i]]+1, x[t[i]]+1, y[t[i]]);
        }
    }
    for(int i = 0; i < n; ++i) {
        if(!state[i][0]) merge(x[i], y[i]+1, x[i]+1, y[i]+1);
        if(!state[i][1]) merge(x[i]+1, y[i], x[i]+1, y[i]+1);
        if(!state[i][2]) merge(x[i], y[i], x[i]+1, y[i]);
        if(!state[i][3]) merge(x[i], y[i], x[i], y[i]+1);
    }
    for(int i = 0; i < m; ++i) {
        int a, b;
        if(x[s[i]] != x[t[i]]) 
            a = find(Mp(pii(x[t[i]], y[t[i]]))), b = find(Mp(pii(x[t[i]], y[t[i]]+1)));
        else 
            a = find(Mp(pii(x[t[i]], y[t[i]]))), b = find(Mp(pii(x[t[i]]+1, y[t[i]])));
        za[i] = a, zb[i] = b;
    }
    for(auto &i : ss) i = find(Mp(pii(x[i], y[i])));
    coor.clear();
    vector<vector<int> > g(N<<1);
    vector<int> lv(N<<1);
    for(int i = 0; i < m; ++i) 
        g[za[i]].emplace_back(i), g[zb[i]].emplace_back(i);
    int ans = 0;
    for(auto i : ss) {
        queue<int> Q;
        if(lv[i]) continue;
        lv[i] = 1, Q.emplace(i);
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            for(int x : g[u]) {
                int v = za[x] ^ zb[x] ^ u;
                if(lv[v] == 0) lv[v] = lv[u] + 1, Q.emplace(v);
                if(lv[v] != lv[u] + 1 && lv[u] != lv[v] + 1) ans++, check[x] = true;
            } 
        }
    }
    printf("%d\n", ans >> 1);
    for(int i = 0; i < m; ++i) if(check[i]) printf("%d\n", i+1);
}