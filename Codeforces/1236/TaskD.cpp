#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 1e5+5;

long n, m, k;
set<int> R[N], C[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 0, x, y; i < k; ++i) {
    cin >> x >> y;
    R[x].emplace(y), C[y].emplace(x);
  }
  long cnt = 1;
  long x = 1, y = 1;
  int state = -1;
  int mnx = 0, mny = 0, mxx = n+1, mxy = m+1;
  while(true) {
    state++, state %= 4;
    if(state == 0) {
      int ny = 10000000;
      auto it = R[x].upper_bound(y);
      if(it == R[x].end()) ny = mxy-1;
      else ny = *it - 1;
      ny = min(ny, mxy-1);
      mnx = x;
      cnt += abs(ny-y);
      if(y == ny) break;
      y = ny;
    }
    if(state == 1) {
      int nx = 10000000;
      auto it = C[y].upper_bound(x);
      if(it == C[y].end()) nx = mxx-1;
      else nx = *it - 1;
      nx = min(nx, mxx-1);
      mxy = y;
      cnt += abs(nx - x);
      if(nx == x) break;
      x = nx;
    } 
    if(state == 2) {
      int ny = 0;
      auto it = R[x].lower_bound(y);
      if(it == R[x].begin()) ny = mny+1;
      else {
        it--;
        ny = *it + 1;
      }
      ny = max(ny, mny+1);
      mxx = x;
      cnt += abs(ny-y);
      if(ny == y) break;
      y = ny;
    } 
    if(state == 3) {
      int nx = 0;
      auto it = C[y].lower_bound(x);
      if(it == C[y].begin()) nx = mnx+1;
      else {
        it--;
        nx = *it + 1;
      }
      nx = max(nx, mnx+1);
      mny = y;
      cnt += abs(nx-x);
      if(nx == x) break;
      x = nx;
    }
    // cerr << state << " = " << x << ' ' << y << "=> " << cnt << endl;
  }
  if(n*m - k == cnt) puts("YES");
  else puts("NO");
}