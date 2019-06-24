#include <bits/stdc++.h>
#include "werewolf.h"
using namespace std;

const int N = 1 << 18;

int n, m, q, par[N];
vector<int> g[N];
vector<int> t1[N], t2[N];
vector<int> sl[N], sr[N];
int al[N], ar[N];

int find(int u) { return par[u] = par[u] == u ? u : find(par[u]); }

int in[N], out[N], pos[N];

void dfs(int u) {
  static int idx = 0;
  pos[in[u] = ++idx] = u;
  for(int v : t1[u]) 
    dfs(v);
  out[u] = idx;
}

int sz[N], in1[N], out1[N], pos1[N];

void pre(int u) {
  static int id = 0;
  sz[pos1[in1[u] = ++id] = u]++;
  for(int &v : t2[u]) {
    pre(v), sz[u] += sz[v];
    if(sz[v] > sz[t2[u][0]]) swap(v, t2[u][0]);
  }
  out1[u] = id;
}

bool t[N<<1];

void update(int x, bool v) {
  for(t[x += N] = v; x != 1; x >>= 1) t[x>>1] = t[x] | t[x^1];
}

bool query(int l, int r) {
  bool ret = false;
  for(l += N, r += N+1; l < r; l >>= 1, r >>= 1) {
    if(l & 1) ret |= t[l++];
    if(r & 1) ret |= t[--r];
  }
  return ret;
}

vector<int> ans;
vector<int> zz[N];

void solve(int u, bool keep) {
  for(int v : t2[u]) if(v != t2[u][0]) solve(v, false);
  if(t2[u].size()) solve(t2[u][0], true);
  update(in[u], true);
  for(int v : t2[u]) if(v != t2[u][0]) 
    for(int i = in1[v]; i <= out1[v]; ++i) update(in[pos1[i]], true);
  for(int x : zz[u]) ans[x] = query(in[al[x]], out[al[x]]);
  if(!keep) for(int i = in1[u]; i <= out1[u]; ++i) update(in[pos1[i]], false);
}

vector<int> check_validity(int N, vector<int> X, vector<int> Y, vector<int> S, vector<int> E, vector<int> L, vector<int> R) {
  n = N, m = X.size(), q = S.size();
  ans.resize(q);
  for(int i = 0; i < m; ++i) g[X[i]].emplace_back(Y[i]), g[Y[i]].emplace_back(X[i]);
  for(int i = 0; i < q; ++i) sl[L[i]].emplace_back(i);
  for(int i = 0; i < q; ++i) sr[R[i]].emplace_back(i);
  for(int i = n-1; ~i; --i) {
    par[i] = i;
    for(int v : g[i]) if(v > i) {
      int a = find(i), b = find(v); 
      if(a != b) {
        t1[a].emplace_back(b);
        par[b] = a;
      }
    }
    for(int v : sl[i]) {
      al[v] = find(S[v]);
    }
  }
  for(int i = 0; i < n; ++i) {
    par[i] = i;
    for(int v : g[i]) if(v < i) {
      int a = find(i), b = find(v);
      if(a != b) {
        t2[a].emplace_back(b);
        par[b] = a;
      }
    }
    for(int v : sr[i]) {
      zz[find(E[v])].emplace_back(v);
    }
  }
  dfs(0);
  pre(n-1);
  solve(n-1, true);
  return ans;
}
