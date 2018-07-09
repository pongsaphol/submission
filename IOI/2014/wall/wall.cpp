#include "wall.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 1<<21, INF = 1e9;

int n, lo[N<<1], hi[N<<1], *ans;

void addtag(int p, int low, int high) {
  lo[p] = min(high, max(lo[p], low));
  hi[p] = max(low, min(hi[p], high));
}

void push(int p, int l, int r) {
  if(l == r) ans[l] = min(max(ans[r], lo[p]), hi[p]);
  else {
    int m = (l + r) >> 1;
    addtag(p<<1, lo[p], hi[p]);
    addtag(p<<1|1, lo[p], hi[p]);
  }
  lo[p] = 0;
  hi[p] = INF;
}

void update(int x, int y, int lo, int hi, int p = 1, int l = 0, int r = n-1) {
  if(x > r || l > y) return;
  if(x <= l && r <= y) return addtag(p, lo, hi);
  push(p, l, r);
  int m = (l + r) >> 1;
  update(x, y, lo, hi, p<<1, l, m), update(x, y, lo, hi, p<<1|1, m+1, r); 
}

void build(int p = 1, int l = 0, int r = n-1) {
  hi[p] = INF;
  if(l == r) return;
  int m = (l + r) >> 1;
  build(p<<1, l, m), build(p<<1|1, m+1, r);
}

void fin(int p = 1, int l = 0, int r = n-1) {
  push(p, l, r);
  if(l == r) return;
  int m = (l + r) >> 1;
  fin(p<<1, l, m), fin(p<<1|1, m+1, r);
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
  ::n = n;
  ans = finalHeight;
  build();
  for(int i = 0; i < k; ++i) 
    if(op[i] == 1) update(left[i], right[i], height[i], INF);
    else update(left[i], right[i], 0, height[i]);
  fin();
  return;
}