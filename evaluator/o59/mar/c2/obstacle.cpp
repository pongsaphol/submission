#include <bits/stdc++.h>
using namespace std;

const int N = 2e3+5;
const int S = 2e4+5;

int n, s;
int dp[S];
vector<int> h[N];

int main() {
  scanf("%d %d", &n, &s);
  for(int i = 0, sz; i < n; ++i) {
    scanf("%d", &sz);
    h[i].resize(sz);
    for(int &v : h[i]) scanf("%d", &v);
  }
  for(int i = n-1; i >= 0; --i) {
    vector<int> &v = h[i];
    for(int j = 0; j < v.size(); ++j) if(j > 0) {
      v[j] += v[j-1]; 
    }
    for(int j = s; j > 0; --j) {
      dp[j] = dp[j-1];
    }
    for(int j = s; j > 0; --j) {
      for(int k = 0; k < v.size() && k < j; ++k) {
        dp[j] = max(dp[j], dp[j-k-1] + v[k]);
      }
    }
  }
  return !printf("%d\n", dp[s]);
}
