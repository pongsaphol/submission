#include <bits/stdc++.h>
using namespace std;

int n, m, f[2005];

int main() {
    scanf("%d %d", &n, &m);
    f[0] = 0, f[1] = 1;
    for(int i = 2; i <= n; ++i) f[i] = (f[i-1] + f[i-2]) % m;
    printf("%d\n", f[n]);
}