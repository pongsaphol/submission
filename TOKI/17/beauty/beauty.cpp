#include <bits/stdc++.h>
#include "beauty.h"
#define vi vector<int>
using namespace std;

const int N = 2e5+5;

int n, m, q;
int cost[N];
vector<vi> g(N);
vector<vi> ccs;
bool art[N];
int low[N], pre[N];
int pos[N], mxb[N];

void find_component(int u, int p) {
  static int idx = 0;
  static stack<int> stk;
  low[u] = pre[u] = ++idx;
  stk.emplace(u);
  int cnt = 0;
  for(int v : g[u]) if(!pre[v]) {
    find_component(v, u);
    cnt++;
    low[u] = min(low[u], low[v]);
    if((p && low[v] >= pre[u]) || (!p && cnt > 1)) art[u] = true;    
    if(low[v] >= pre[u]) {
      ccs.emplace_back(vi());
      ccs.back().emplace_back(u);
      while(ccs.back().back() != v) ccs.back().emplace_back(stk.top()), stk.pop();
    }
  } else if(v != p) low[u] = min(low[u], pre[v]);
}

void gen_bctree() {
  g.clear(), g.emplace_back(vi());
  for(int i = 1; i <= n; ++i) if(art[i]) {
    mxb[pos[i] = g.size()] = cost[i];
    g.emplace_back(vi());
  }
  for(auto &z : ccs) {
    g.emplace_back(vi());
    for(int v : z) {
      if(art[v]) g[pos[v]].emplace_back(g.size()-1), g.back().emplace_back(pos[v]);
      else pos[v] = g.size()-1;
      mxb[g.size()-1] = max(mxb[g.size()-1], cost[v]);
    }
  }
}

int dep[N], par[N][18], mxp[N][18];

void init_lca(int u, int p) {
  dep[u] = dep[p] + 1, par[u][0] = p, mxp[u][0] = mxb[u];
  for(int i = 1; i < 18; ++i) {
    par[u][i] = par[par[u][i-1]][i-1];
    mxp[u][i] = max(mxp[u][i-1], mxp[par[u][i-1]][i-1]);
  }
  for(int v : g[u]) if(v != p) init_lca(v, u);
}

int get_lca(int a, int b) {
  int mx = 0;
  if(dep[a] < dep[b]) swap(a, b);
  for(int i = 17; ~i; --i) if(dep[par[a][i]] >= dep[b]) {
    mx = max(mx, mxp[a][i]);
    a = par[a][i];
  }
  if(a == b) return max(mx, mxp[a][0]);
  for(int i = 17; ~i; --i) if(par[a][i] != par[b][i]) {
    mx = max({mx, mxp[a][i], mxp[b][i]});
    a = par[a][i], b = par[b][i]; 
  }
  return max({mx, mxp[a][1], mxp[b][1]});
}

vector<int> getMaximumBeauty(int n, int m, int q, vector<int> T, vector<int> U, vector<int> V, vector<int> A, vector<int> B) {
  ::n = n, ::m = m, ::q = q;
  for(int i = 0; i < n; ++i) {
    cost[i+1] = T[i];
  }
  for(int i = 0; i < m; ++i) {
    g[U[i]].emplace_back(V[i]);
    g[V[i]].emplace_back(U[i]);
  }
  find_component(1, 0);
  gen_bctree();
  init_lca(1, 0);
  vi ans;
  for(int i = 0; i < q; ++i) ans.emplace_back(get_lca(pos[A[i]], pos[B[i]]));
  return ans;
}
