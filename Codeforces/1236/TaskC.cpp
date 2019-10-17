#include <bits/stdc++.h>
#define long long long
using namespace std;

const long M = 1e9+7;

long powMod(long a, long b) {
  long ret = 1;
  for(; b; b >>= 1) {
    if(b & 1) ret = ret * a % M;
    a = a * a % M;
  }
  return ret;
}

int main() {
  long n, m; cin >> n >> m;
  long v = powMod(2, m) - 1 + M;
  v %= M;
  cout << powMod(v, n) << endl;
}