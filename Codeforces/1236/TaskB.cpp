#include <bits/stdc++.h>
using namespace std;

const int N = 305;

bool used[N*N];

int main() {
  int n; cin >> n;
  if(n & 1) {
    for(int i = 0; i < n; ++i) printf("%d ", i*n+(n-1)/2+1);
    puts("");
  }
  for(int i = 0; i < n/2; ++i) {
    for(int j = 0; j < n; ++j) {
      if(j & 1) printf("%d ", j*n + n-i);
      else printf("%d ", j*n + i + 1);
    }
    puts("");
    for(int j = 0; j < n; ++j) {
      if(~j & 1) printf("%d ", j*n + n-i);
      else printf("%d ", j*n + i+1);
    }
    puts("");
  }
}