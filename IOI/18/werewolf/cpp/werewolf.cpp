#include <bits/stdc++.h>
#include "werewolf.h"
using namespace std;

const int N = 2e5+5;

int n, m, q, par[N];
vector<int> g[N];
vector<int> t1[N], t2[N];
vector<int> sl[N], sr[N];
int al[N], ar[N];

int find(int u) { return par[u] = par[u] == u ? u : find(par[u]); }

int sz[N], in[N], out[N], pos[N];

void dfs(int u, int p) {
  static int idx = 0;
  sz[pos[in[u] = ++idx] = u]++;
  if(p != -1) t1[u].erase(find(t1[u].begin(), t1[u].end(), p)); 
  for(int v : t1[u]) 
    dfs(v, u);
  out[u] = idx;
}

void solve(int u, int p) {

}

vector<int> check_validity(int N, vector<int> X, vector<int> Y, vector<int> S, vector<int> E, vector<int> L, vector<int> R) {
  n = N, m = X.size(), q = S.size();
  for(int i = 0; i < m; ++i) g[X[i]].emplace_back(Y[i]), g[Y[i]].emplace_back(X[i]);
  for(int i = 0; i < q; ++i) sl[L[i]].emplace_back(i);
  for(int i = 0; i < q; ++i) sr[R[i]].emplace_back(i);
  for(int i = n-1; ~i; --i) {
    par[i] = i;
    for(int v : g[i]) if(v > i) {
      int a = find(i), b = find(v); 
      if(a != b) {
        t1[a].emplace_back(b), t1[b].emplace_back(a);
        par[b] = a;
      }
    }
    for(int v : sl[i]) al[v] = find(S[v]);
  }
  for(int i = 0; i < n; ++i) {
    par[i] = i;
    for(int v : g[i]) if(v < i) {
      int a = find(i), b = find(v);
      if(a != b) {
        t2[a].emplace_back(b), t2[b].emplace_back(a);
        par[b] = a;
      }
    }
    for(int v : sr[i]) ar[v] = find(E[v]);
  }
  dfs(n-1);
  solve(0);
}
