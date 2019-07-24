#include <bits/stdc++.h>
#include "radius.h"
using namespace std;

const int N = 1e5+5;

int n, q;
int dep[N], par[N][17], mmxp[N][17];
int in[N], out[N], pos[N];
int dp[N], pref[N], suff[N];
vector<int> g[N], mxp[N], mxs[N];

void init_dfs(int u, int p) {
  static int idx = 0;
  dp[u] = dep[u] = dep[p] + 1, par[u][0] = p; 
  for(int i = 1; i < 17; ++i) par[u][i] = par[par[u][i-1]][i-1];
  pos[in[u] = ++idx] = u;
  if(p) g[u].erase(find(g[u].begin(), g[u].end(), p));
  g[u].emplace_back(-1), g[u].emplace_back(n+1);
  mxp[u].resize(g[u].size()), mxs[u].resize(g[u].size());
  sort(g[u].begin(), g[u].end());
  for(int i = 1; i < g[u].size()-1; ++i) {
    init_dfs(g[u][i], u);
    dp[u] = max(dp[u], dp[g[u][i]]); 
    mxp[u][i] = mxs[u][i] = dp[g[u][i]];
    mxp[u][i] = max(mxp[u][i], mxp[u][i-1]);
  }
  for(int i = g[u].size()-2; i; --i) mxs[u][i] = max(mxs[u][i+1], mxs[u][i]);
  out[u] = idx;
}

vector<int> getRadius(int n, int q, vector<int> U, vector<int> V, vector<int> A) {
  ::n = n, ::q = q;
  for(int i = 0; i < n-1; ++i) g[U[i]].emplace_back(V[i]), g[V[i]].emplace_back(U[i]);
  init_dfs(1, 0);
  for(int i = 1; i <= n; ++i) pref[i] = max(pref[i-1], dep[pos[i]]);
  for(int i = n; i >= 1; --i) suff[i] = max(suff[i+1], dep[pos[i]]);
  for(int i = 2; i <= n; ++i) {
    int z = lower_bound(g[par[i][0]].begin(), g[par[i][0]].end(), i) - g[par[i][0]].begin();
    // cerr << i << ' ' << z << " => " << g[par[i][0]][z] << endl;
    int mxz = max(mxp[par[i][0]][z-1], mxs[par[i][0]][z+1]);
    // cerr << mxz << endl;
    mmxp[i][0] = mxz - 2 * (dep[i]-1);
    // cerr << i << ' ' << dp[i] << ' ' << dep[i] << " -> " << mxp[i][0] << endl;
  }
  for(int j = 1; j < 17; ++j) {
    for(int i = 2; i <= n; ++i) mmxp[i][j] = max(mmxp[i][j-1], mmxp[par[i][j-1]][j-1]);
  }

  // cerr << "-> " << mmxp[3][0] << endl;
  // cerr << "-> " << mmxp[6][1] << endl;
  vector<int> ans;
  for(int i = 0; i < q; ++i) {
    int v = A[i], vv = A[i];
    if(dep[v] <= 2) {
      ans.emplace_back(pref[n]-1);
      continue;
    }
    int z = dep[v]&1;
    int c = dep[v]/2 + 1;
    // cerr << "=> " << c << ' ' << z << endl;
    int mx = dp[v] - 2 * dep[v];
    for(int i = 16; ~i; --i) if(dep[par[v][i]] > c) mx = max(mx, mmxp[v][i]), v = par[v][i];
    mx += 2*c + (z);
    // cerr << mx << endl;
    mx = max({mx, pref[in[v]-1], suff[out[v]+1]});
    ans.emplace_back(mx-1);
  }
  return ans;
}
