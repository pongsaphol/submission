#include "grader.h"
#include "encoder.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

static vector<int> g[N], ng[N];
static int d[N], par[N];
static bool chk[N];
static int ntsp[N];

void addShort(int u) {
  for(int i = 9; ~i; --i) encode_bit(u >> i & 1);
}

static void dfs(int u, int p) {
  if(u) par[u] = p, ng[u].emplace_back(p);
  chk[u] = true;
  for(int v : g[u]) if(v != p && !chk[v]) ng[u].emplace_back(v), dfs(v, u);
}

// 0 -1 1
void process(int u, int p) {
  ntsp[u] = (d[u] == d[p] ? 0 : (d[u] < d[p] ? 1 : 2));
  for(int v : ng[u]) if(v != p) process(v, u);
}

void encode(int nv, int nh, int ne, int *v1, int *v2){
  for(int i = 0; i < ne; ++i)
    g[v1[i]].emplace_back(v2[i]), g[v2[i]].emplace_back(v1[i]);
  dfs(0, -1);
  for(int i = 1; i < nv; ++i) addShort(par[i]);
  for(int i = 0; i < nh; ++i) {
    fill_n(d, N, (int)1e9);
    queue<int> Q; Q.emplace(i), d[i] = 0;
    while(!Q.empty()) {
      int u = Q.front(); Q.pop();
      for(int v : g[u]) if(d[v] > d[u] + 1) 
        d[v] = d[u] + 1, Q.emplace(v);
    }
    process(i, i);
    for(int i = 0; i < 200; ++i) {
      int sum = 0;
      for(int j = 4; ~j; --j) sum = sum * 3 + ntsp[5*i+j];
      for(int j = 7; ~j; --j) encode_bit(sum >> j & 1);
    }
  } 
  return;
}
