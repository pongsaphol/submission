#include <bits/stdc++.h>
using namespace std;

const int N = 2e3+5;
const int M = 1e9+7;

int n, h;
int arr[N];
int dp[N];

int main() {
  scanf("%d %d", &n, &h);
  for(int i = 1; i <= n; ++i) scanf("%d", arr+i), arr[i] = h - arr[i];
  for(int i = 0; i <= n; ++i) if(arr[i] < 0 || abs(arr[i] - arr[i+1]) > 1) return !printf("0\n");
  dp[0] = 1;
  for(int i = 1; i <= n; ++i) {
    if(arr[i-1] <= arr[i]) dp[i] = dp[i-1];
    if(arr[i-1] >= arr[i]) dp[i] = (dp[i] + 1ll * dp[i-1] * arr[i-1]) % M;
  }
  printf("%d\n", dp[n]);
}