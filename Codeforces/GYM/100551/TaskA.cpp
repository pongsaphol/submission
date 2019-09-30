#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;


const int N = 1<<19;

int n, m;

int dsu[N];
vector<pii> E[N<<1];
bool ask[N];
stack<pii> stk;

int find(int u) { return dsu[u] < 0 ? u : find(dsu[u]); }
bool mer(int u, int v) {
  u = find(u), v = find(v);
  if(u == v) return false;
  if(abs(dsu[u]) < abs(dsu[v])) swap(u, v);
  stk.emplace(u, dsu[u]);
  stk.emplace(v, dsu[v]);
  dsu[u] += dsu[v];
  dsu[v] = u;
  return true;
}
void rollback(int ver) {
  while(stk.size() > ver) {
    dsu[stk.top().x] = stk.top().y;
    stk.pop();
  }
}

void update(int x, int y, pii v, int p = 1, int l = 1, int r = m+1) {
  if(x > r || l > y || x > y) return;
  if(x <= l && r <= y) return void(E[p].emplace_back(v)) ;
  int m = l + r >> 1;
  update(x, y, v, p<<1, l, m), update(x, y, v, p<<1|1, m+1, r);
}

void solve(int com, int p = 1, int l = 1, int r = m+1) {
  int nowver = stk.size();
  for(auto x : E[p]) if(mer(x.x, x.y)) com--;
  if(l != r) {
    int m = l + r >> 1;
    solve(com, p<<1, l, m), solve(com, p<<1|1, m+1, r);
  } else {
    if(ask[l]) printf("%d\n", com);
  }
  rollback(nowver);
}

map<pii, int> Mp;

int main() {
  freopen("connect.in", "r", stdin);
  freopen("connect.out", "w", stdout);
  memset(dsu, -1, sizeof dsu);
  scanf("%d %d", &n, &m);
  for(int i = 1, a, b; i <= m; ++i) {
    char c; scanf(" %c", &c);
    if(c == '?') {
      ask[i] = true;
    } else {
      scanf("%d %d", &a, &b);
      if(a > b) swap(a, b);
      if(c == '+') {
        Mp[pii(a, b)] = i;
      } else {
        int start = Mp[pii(a, b)];
        update(start, i, pii(a, b));
        Mp[pii(a, b)] = 0;
      }
    }
  }
  for(auto x : Mp) if(x.y) {
    update(x.y, m+1, x.x);
  }
  solve(n);
}