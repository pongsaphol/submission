#include <bits/stdc++.h>
using namespace std;

const int N = 3e2+5;

const int INF = 1e9;
int n, m; 
int arr[N][N];
int pref[N][N];

int ans = -INF;
int dp1[N][N][N];
int dp2[N][N][N];

void solve(bool st) {
  fill_n(dp1[0][0], N*N*N, -INF);
  fill_n(dp2[0][0], N*N*N, -INF);
  for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
    pref[i][j] = (st ? arr[j][i] : arr[i][j]) + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
  }
  for(int sz = 1; sz <= n; ++sz) {
    for(int l = 0, r = sz; r <= n; ++l, ++r) {
      vector<int> rdp1(N+5);
      vector<int> rdp2(N+5);
      for(int i = 1; i <= m; ++i) {
        int val = pref[r][i] - pref[l][i] - pref[r][i-1] + pref[l][i-1]; 
        rdp1[i] = max(rdp1[i-1], 0) + val;
        dp1[l][r][i] = max({dp1[l+1][r][i], dp1[l][r-1][i], rdp1[i], dp1[l][r][i-1]});
      }
      for(int i = m; i >= 1; --i) {
        int val = pref[r][i] - pref[l][i] - pref[r][i-1] + pref[l][i-1]; 
        rdp2[i] = max(rdp2[i+1], 0) + val;
        dp2[l][r][i] = max({dp2[l+1][r][i], dp2[l][r-1][i], rdp2[i], dp2[l][r][i+1]});
      }
      for(int i = 1; i < m-1; ++i) {
        ans = max({ans, dp1[l][r][i] + rdp2[i+2], rdp1[i] + dp2[l][r][i+2]});
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) scanf("%d", &arr[i][j]);
  solve(false);
  swap(n, m);
  solve(true);
  printf("%d\n", ans);
}
