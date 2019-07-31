#include <bits/stdc++.h>
#define long long long 
using namespace std;

const int N = 105;
const int K = 1005;
const long INF = 1e9+1;

int n, m, k;
long b[N][K], s[N][K];
long d1[N][N], d2[N][N], cost[N][N];

void apsp(long d[N][N]) {
  for(int k = 1; k <= n; ++k) 
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
  fill_n(d1[0], N*N, INF);
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 1; i <= n; ++i) 
    for(int j = 1; j <= k; ++j) 
      scanf("%lld %lld", &b[i][j], &s[i][j]);
  for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j)
    for(int l = 1; l <= k; ++l) if(s[j][l] != -1 && b[i][l] != -1)
      cost[i][j] = max(cost[i][j], s[j][l] - b[i][l]);
  for(int i = 0, u, v, w; i < m; ++i) {
    scanf("%d %d %d", &u, &v, &w);
    d1[u][v] = w;
  }
  apsp(d1);
  long l = 0, r = 1e9+1;
  while(l < r) {
    long m = (l + r + 1) / 2;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j)
      d2[i][j] = m * d1[i][j] - cost[i][j];
    apsp(d2);
    bool st = false;
    for(int i = 1; i <= n; ++i) st |= d2[i][i] <= 0;
    if(st) l = m;
    else r = m-1;
  }
  printf("%lld\n", l);
}