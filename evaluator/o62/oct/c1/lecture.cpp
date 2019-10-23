#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 1e5+5;
const int NN = 305;
const int INF = 1e9;

int c, n, m;
long cost[N];
int order[N];
int d[NN][NN];

int main() {
  fill_n(d[0], NN*NN, INF);
  scanf("%d %d %d", &c, &n, &m);
  for(int i = 1; i <= c; ++i) scanf("%d", &order[i]);
  for(int i = 1; i <= c; ++i) scanf("%lld", &cost[i]);
  for(int i = 2; i <= c; ++i) cost[i] += cost[i-1];
  for(int i = 1; i <= n; ++i) d[i][i] = 0;
  for(int i = 0, u, v, w; i < m; ++i) {
    scanf("%d %d %d", &u, &v, &w);
    d[u][v] = min(d[u][v], w);
    d[v][u] = min(d[v][u], w);
  }
  for(int k = 1; k <= n; ++k) for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) 
    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  long l = 1, r = 2e9;
  while(l < r) {
    long m = (l + r + 1) / 2;
    bool st = true;
    long tim = 0;
    for(int i = 2; i <= c; ++i) {
      tim += m * d[order[i]][order[i-1]];
      if(tim > cost[i]) st = false;
      tim = max(tim, cost[i-1]);
    }
    if(st) l = m;
    else r = m-1;
  }
  printf("%lld\n", l);
}