#include <bits/stdc++.h>
#define iii tuple<int, int, int>
using namespace std;

const int logN = 17;
const int N = 1 << logN;

int n, m;
int d[logN + 1][N], tick[logN + 1][N];
int val[N];
int t[logN + 1][N << 1], lz[logN + 1][N << 1]; 
int centroidLV[N], centroidPar[N], centroidFrom[N];
int nid[logN+1], id[logN + 1][N];
bool check[N];
vector<int> g[N];
priority_queue<iii> priorCentroid[N];

void pushLazySegment(int lv, int p, int l, int r) {
  if (lz[lv][p]) {
    t[lv][p] += lz[lv][p];
    if (p < N) {
      lz[lv][p << 1] += lz[lv][p];
      lz[lv][p << 1 | 1] += lz[lv][p];
    }
    lz[lv][p] = 0;
  }
}

template<typename T>
void travelSegment(int lv, int x, int y, const T &f, int p = 1, int l = 1, int r = n) {
  pushLazySegment(lv, p, l, r);
  if (x > r || l > y) return;
  if (x <= l && r <= y) {
    f(p);
    pushLazySegment(lv, p, l, r);
    return;
  }
  int m = (l + r) >> 1;
  travelSegment(lv, x, y, f, p << 1, l, m);
  travelSegment(lv, x, y, f, p << 1 | 1, m + 1, r);
  t[lv][p] = max(t[lv][p << 1], t[lv][p << 1 | 1]);
}

void updateSegment(int lv, int x, int y, int v) {
  travelSegment(lv, x, y, [&](int p) {
    lz[lv][p] += v;
  });
}

void updateSegmentEqual(int x, int v) {
  travelSegment(0, x, x, [&](int p) {
    t[0][p] = v;
  });
}

int querySegment(int lv, int x, int y) {
  int mx = -2e9;
  travelSegment(lv, x, y, [&](int p) {
    mx = max(mx, t[lv][p]);
  });
  return mx;
}

void dfsFill(int u, int p, int lv) {
  id[lv][u] = ++nid[lv];
  if(p != -1) {
    updateSegment(lv, id[lv][u], id[lv][u] + d[lv][u] - 1, val[u]);
  }
  for (int v : g[u]) {
    if (v != p && !check[v]) {
      dfsFill(v, u, lv);
    }
  }
}

int getMaxCentroid(int lv, int u) {
  while (!priorCentroid[u].empty() && tick[lv][get<1>(priorCentroid[u].top())] != get<2>(priorCentroid[u].top())) {
    priorCentroid[u].pop();
  }
  if (priorCentroid[u].empty()) {
    return val[u];
  }
  auto tmp = priorCentroid[u].top(); priorCentroid[u].pop();
  while (!priorCentroid[u].empty() && tick[lv][get<1>(priorCentroid[u].top())] != get<2>(priorCentroid[u].top())) {
    priorCentroid[u].pop();
  }
  if (priorCentroid[u].empty()) {
    priorCentroid[u].emplace(tmp);
    return max(0, get<0>(tmp)) + val[u];
  }
  int ans = max(0, get<0>(tmp)) + max(0, get<0>(priorCentroid[u].top())) + val[u];
  priorCentroid[u].emplace(tmp);
  return ans;
}

void generateSegment(int u, int lv) {
  dfsFill(u, -1, lv);
  for (int v : g[u]) if (!check[v]) {
    int mx = querySegment(lv, id[lv][v], id[lv][v] + d[lv][v] - 1);
    priorCentroid[u].emplace(mx, v, 0);
  }
  updateSegment(0, u, u, getMaxCentroid(lv, u));
}

void findCentroid(int lv, int u, int p, int sz, int &centroid) {
  int mx = 0;
  d[lv][u] = 1;
  for (int v : g[u]) {
    if (v != p && !check[v]) {
      findCentroid(lv, v, u, sz, centroid);
      d[lv][u] += d[lv][v];
      mx = max(mx, d[lv][v]);
    }
  }
  mx = max(mx, sz - d[lv][u]);
  if ((mx << 1) <= sz) {
    centroid = u;
  }
}

void centroidDecomposition(int u, int p = -1, int sz = n, int lv = 1) {
  int centroid = -1;
  findCentroid(lv, u, -1, sz, centroid);
  centroidLV[centroid] = lv, centroidFrom[centroid] = u, centroidPar[centroid] = p;
  int tmp = -1;
  findCentroid(lv, centroid, -1, sz, tmp);
  generateSegment(centroid, lv);
  check[centroid] = true;
  for (int v : g[centroid]) {
    if (!check[v]) {
      centroidDecomposition(v, centroid, d[lv][v], lv+1);
    }
  }
}

void updateCentroid(int u, int v, int tt) {
  int diff = v - val[u];
  val[u] += diff;
  int centroid = u, from = u;
  for (int lv = centroidLV[u]; lv; --lv) {
    if(lv != centroidLV[u]) {
      from = centroidFrom[centroid];
      centroid = centroidPar[centroid];
    }
    if (u != centroid) {
      updateSegment(lv, id[lv][u], id[lv][u] + d[lv][u] - 1, diff);
      priorCentroid[centroid].emplace(querySegment(lv, id[lv][from], id[lv][from] + d[lv][from] - 1), from, tt);
      tick[lv][from] = tt;
      
    }
    updateSegmentEqual(centroid, getMaxCentroid(lv, centroid));
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", val+i);
  }
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    g[u].emplace_back(v), g[v].emplace_back(u);
  }
  centroidDecomposition(1);
  printf("%d\n", t[0][1]);
  for (int i = 1, u; i <= m; ++i) {
    int v;
    scanf("%d %d", &u, &v); 
    updateCentroid(u, v, i);
    printf("%d\n", t[0][1]);
  }
}
