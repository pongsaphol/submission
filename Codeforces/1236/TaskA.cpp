#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  while(T--) {
    int a, b, c; cin >> a >> b >> c;
    int cnt = 0;
    while(c >= 2 && b >= 1) cnt++, c -= 2, b -= 1;
    while(b >= 2 && a >= 1) cnt++, b -= 2, a -= 1;
    printf("%d\n", cnt*3);
  }
}