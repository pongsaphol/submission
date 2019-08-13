#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, m, cnt;
int p[N];
int par[N];
set<int> S[N];

int find(int u) { return par[u] = par[u] == u ? u : find(par[u]); }

int main() {
  iota(par, par+N, 0);
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i) 
    scanf("%d", p+i);
  for(int i = 0, a, b; i < m; ++i) {
    scanf("%d %d", &a, &b);
    a = find(a), b = find(b);
    if(a != b) par[a] = b;
  } 
  for(int i = 1; i <= n; ++i) {
    S[find(i)].emplace(i);
  }
  for(int i = 1; i <= n; ++i) {
    if(S[find(i)].count(p[i])) cnt++;
  }
  printf("%d\n", cnt);
}