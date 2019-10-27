#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;

int n, m;
vector<pii> g[N];
vector<pii> vec;
int dep[N];
pii jump[N];
multiset<int> S;

void init_dfs(int u, int p) {
  dep[u] = dep[p] + 1;
  for(pii v : g[u]) if(v.x != p) {
    jump[v.x] = pii(u, v.y);
    init_dfs(v.x, u);
  }
}

int get_max(int u, int v) {
  int mx = 0;
  if(dep[u] < dep[v]) swap(u, v);
  while(dep[u] > dep[v]) {
    mx = max(mx, jump[u].y);
    u = jump[u].x;
  }
  while(u != v) {
    mx = max({mx, jump[u].y, jump[v].y});
    u = jump[u].x;
    v = jump[v].x;
  }
  return mx;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 1, u, v, w; i <= m; ++i) {
    scanf("%d %d %d", &u, &v, &w);
    if(i < n) {
      g[u].emplace_back(v, w), g[v].emplace_back(u, w);
    } else {
      vec.emplace_back(u, v);
      S.emplace(w);
    }
  }
  init_dfs(1, 0);
  vector<int> ans;
  for(pii v : vec) {
    int mx = get_max(v.x, v.y);
    auto it = S.upper_bound(mx);
    if(it == S.end()) 
      return !printf("0\n");
    ans.emplace_back(*it);
    S.erase(it);
  }
  printf("1\n");
  for(int v : ans) printf("%d\n", v);
}