#include <bits/stdc++.h>
using namespace std;

#define long long long 

int main() {
    long n, m; cin >> n >> m;
    long mx = 0;
    for(long i = 0; i <= n; ++i) {
        long ret = (i) * (i-1) / 2;
        if(ret >= m) mx = max(mx, n - i);
    }
    long mn = max(0ll, n - 2ll*m);
    printf("%lld %lld\n", mn, mx);
}

