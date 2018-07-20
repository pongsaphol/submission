#include "catdog.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1<<17, INF = 1e9;

int n, col[N];
vector<vector<int> > g(N);
int par[N], spi[N], rot[N], dep[N], pos[N], last[N];
pii lastupd[N];

struct item {
  int d[4];
  item() { }
  friend item operator+(const item &a, const item &b) {
    item z;
    for(int i = 0; i < 4; ++i) {
      z.d[i] = INF;
      for(int j = 0; j < 4; ++j) z.d[i] = min(z.d[i], a.d[i&1|((j&1)<<1)] + b.d[(i&2)|((j&2)>>1)] + (j == 2 || j == 1));
    }
    return z;
  }
};

item t[N<<1];

void build(int p = 1, int l = 1, int r = n) {
  if(l == r) {
    t[p].d[0] = t[p].d[3] = 0;
    t[p].d[1] = t[p].d[2] = INF;
    return;
  }
  int m = l + r >> 1;
  build(p<<1, l, m), build(p<<1|1, m+1, r);
  t[p] = t[p<<1] + t[p<<1|1];
}

int dfs(int u, int p) {
  dep[u] = dep[p] + 1, par[u] = p;
  pii ret(0, -1);
  int sz = 1;
  for(int v : g[u]) if(v != p) {
    int now = dfs(v, u);
    if(now > ret.x) ret = pii(now, v);
    sz += now;
  }
  spi[u] = ret.y;
  return sz;
}

void hld() {
  dfs(1, 0);
  for(int i = 1, id = 0; i <= n; ++i) if(spi[par[i]] != i) 
    for(int j = i; j != -1; j = spi[j]) pos[j] = ++id, rot[j] = i, last[i] = j;
  build();
}

void updt(int x, pii v, int p = 1, int l = 1, int r = n) {
  if(l == r) {
    t[p].d[0] += v.x, t[p].d[3] += v.y; 
    return;
  }
  int m = l + r >> 1;
  if(x <= m) updt(x, v, p<<1, l, m);
  else updt(x, v, p<<1|1, m+1, r);
  t[p] = t[p<<1] + t[p<<1|1];
}

item query(int x, int y, int p = 1, int l = 1, int r = n) {
  if(x <= l && r <= y) return t[p];
  int m = l + r >> 1;
  if(y <= m) return query(x, y, p<<1, l, m);
  if(x > m) return query(x, y, p<<1|1, m+1, r);
  return query(x, y, p<<1, l, m) + query(x, y, p<<1|1, m+1, r);
}

void update(int x, pii v) {
  while(x) { 
    updt(pos[x], v);
    item ret = query(pos[rot[x]], pos[last[rot[x]]]);
    int b0 = min(ret.d[0], ret.d[2]), b1 = min(ret.d[1], ret.d[3]);
    pii nlast(min(b0, 1 + b1), min(b1, 1 + b0));
    v = pii(nlast.x - lastupd[rot[x]].x, nlast.y - lastupd[rot[x]].y);
    lastupd[rot[x]] = nlast;
    x = par[rot[x]];
  }
}

void initialize(int N, vector<int> A, vector<int> B) {
  n = N;
  for(int i = 0; i < n-1; ++i) {
    g[A[i]].emplace_back(B[i]);
    g[B[i]].emplace_back(A[i]);
  }
  hld();
}

int getMin() {
  item ret = query(1, pos[last[1]]);
  return *min_element(ret.d, ret.d+4);
}

int cat(int v) {
  col[v] = 0;
  update(v, pii(0, INF));
  return getMin();
}

int dog(int v) {
  col[v] = 1;
  update(v, pii(INF, 0));
  return getMin();
}

int neighbor(int v) {
  if(col[v]) update(v, pii(-INF, 0));
  else update(v, pii(0, -INF));
  return getMin();
}
