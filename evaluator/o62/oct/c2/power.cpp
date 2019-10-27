#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 2e5+5;

int n, m;
long t1[N<<1], t2[N<<1];

void build(long t[]) {
  for(int i = N-1; i; --i) t[i] = max(t[i<<1], t[i<<1|1]);
}

void update(long t[], int x, long v) {
  x += N;
  for(t[x] = max(t[x], v); x > 1; x >>= 1) t[x>>1] = max(t[x], t[x^1]);
}

long query(long t[], int l, int r) {
  long mx = -1e18;
  for(l += N, r += N+1; l < r; l >>= 1, r >>= 1) {
    if(l & 1) mx = max(mx, t[l++]);
    if(r & 1) mx = max(mx, t[--r]);
  }
  return mx;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i) t1[i+N] = i, t2[i+N] = -i;
  build(t1), build(t2);
  long pre = 0;
  for(int i = 0, a, b, c; i < m; ++i) {
    scanf("%d %d %d", &a, &b, &c); if(a > b) swap(a, b);
    long v1 = max(query(t1, 1, a) - a, query(t2, a, n) + a) + c;
    long v2 = max(query(t1, 1, b) - b, query(t2, b, n) + b) + c;
    pre = max({pre, v1, v2});
    update(t1, b, v1+b), update(t2, b, v1-b);
    update(t1, a, v2+a), update(t2, a, v2-a);
    printf("%lld\n", pre);
  }
}