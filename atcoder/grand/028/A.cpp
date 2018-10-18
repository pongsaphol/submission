#include <bits/stdc++.h>
using namespace std;

#define long long long

const int N = 1e5+5;

int n, m;
char S[N], T[N];

int main() {
    scanf("%d %d", &n, &m);
    scanf("%s %s", S, T);
    long lcm = 1ll * n * m / __gcd(n, m);
    long x = lcm / n, y = lcm / m;
    long lcm2 = x * y / __gcd(x, y);
    long z1 = lcm2 / x, z2 = lcm2 / y;
    for(int i = 0; i < n; ++i) {
        if(z1 * i >= n || z2 * i >= m) break;
        if(S[z1*i] != T[z2*i]) return !printf("-1");
    }
    printf("%lld\n", lcm);
}
