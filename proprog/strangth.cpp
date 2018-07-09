#include <bits/stdc++.h>
using namespace std;


int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int a;
    scanf("%d", &a);
    printf("%d\n", (a ^ (1 <<((int)log2(a))))<<1|1);
  }
}
