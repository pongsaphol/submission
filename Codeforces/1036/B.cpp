#include <bits/stdc++.h>
using namespace std;

#define long long long

int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        long x, y, k; scanf("%lld %lld %lld", &x, &y, &k);
        if(k < max(x, y)) puts("-1");
        else printf("%lld\n", k - ((x^k) & 1)- ((y^k) & 1));
    }
}
