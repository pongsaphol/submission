#include <bits/stdc++.h>
#define long long long
using namespace std;

bool _solve() {
    long a, b, c, d; cin >> a >> b >> c >> d;
    if(d < b) return false;
    if(a - b < 0) return false;
    if(c + 1 >= b) return true;
    d %= b;
    if(d == 0) {
        if((a % b) > c) return false;
        return true;
    }
    d %= b,  a %= b;
    long l = c+1, r = b-1;
    if(r - l + 1 >= d) return false;
    if(__gcd(d, b) == 1) return false;
    a %= d, l %= d, r %= d;
    if(l <= r && l <= a) return false;
    if(r > l && (a >= l || a <= r)) return false;
    return true;
}

bool solve() {
    long a, b, c, d; cin >> a >> b >> c >> d;
    long z = max(1ll, (a-c+b-1)/b);
    a -= z *b;
    if(a < 0) return false;
    if(d < b) return false;
    if(b <= c) return true;
    long g = __gcd(b, d);
    long x = (b - a -1) / g;
    a += x * g;
    if(a > c) return false;
    return true;
}

int main() {
    int T; scanf("%d", &T);
    while(T--) puts(solve() ? "Yes" : "No");
}
