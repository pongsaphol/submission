#include <bits/stdc++.h>
#define long long long 
using namespace std;

int main() {
    long n, m; cin >> n >> m;
    long ans = 0;
    while(m--) {
        long x, d; cin >> x >> d;
        ans += n*x;
        if(d >= 0) ans += n * (n-1) / 2 *d;
        else  {
            long l = (n-1) >> 1;
            long r = n >> 1;
            ans += l * (l + 1) / 2 *d +  r * (r + 1) / 2 * d;
        }
    } 
    cout << setprecision(20) << ans * 1.0 / n;
}
