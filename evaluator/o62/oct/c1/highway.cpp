#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;

const int N = 1e5+5;

int n, m, k;
vector<int> g[N], rg[N];
vector<pii> que;
bool check1[N], check2[N];
bool call1[N], call2[N];
bool closed[N];

void dfs(int u, bool check[], vector<int> g[], bool call[]) {
  check[u] = true;
  for(int v : g[u]) if(!check[v] && !closed[v]) 
    dfs(v, check, g, call);
  else if(!check[v]) call[v] = true;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0, u, v; i < m; ++i) {
    scanf("%d %d", &u, &v);
    g[u].emplace_back(v), rg[v].emplace_back(u);
  }
  for(int i = 0, a, b; i < k; ++i) {
    scanf("%d %d", &a, &b);
    que.emplace_back(a, b);
  }
  reverse(all(que));
  for(auto x : que) if(x.x == 1) closed[x.y] = true;
  dfs(1, check1, g, call1), dfs(n, check2, rg, call2);
  vector<int> ans;
  for(auto x : que) {
    if(x.x == 1) {
      closed[x.y] = false;
      if(call1[x.y]) dfs(x.y, check1, g, call1);
      if(call2[x.y]) dfs(x.y, check2, rg, call2);
    } else {
      ans.emplace_back((check1[x.y] && check2[x.y]) ? 1 : 0);
    }
  }
  reverse(all(ans));
  for(int v : ans) printf("%d\n", v);
}