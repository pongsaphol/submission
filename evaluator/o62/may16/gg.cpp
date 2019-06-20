#include <bits/stdc++.h>
#define long long long
using namespace std;

long getdis(int k, long x1, long y1, long x2, long y2) {
    // cerr << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << "-> getdis" << endl;
    if(x1 == x2 && y1 == y2) return 0;
    bool a = x1 >> k & 1, b = y1 >> k & 1, c = x2 >> k & 1, d = y2 >> k & 1;
    long del = (1ll << k) - 1;
    long de2 = (1ll << (k+1)) - 1;
    long ret = 0;
    if(k == 0) {
        if(a != c) ret++;
        if(b != d) ret++;
    }
    else if(a == c && b == d) ret = getdis(k-1, x1 & del, y1 & del, x2 & del, y2 & del);
    else if(a == c) ret = (1ll << k) + getdis(k-1, x1 & del, (y1 ^ (1ll << k)) & del, x2 & del, y2 & del);
    else if(b == d) ret = (1ll << k) + getdis(k-1, (x1 ^ (1ll << k)) & del, y1 & del, x2 & del, y2 & del);
    else {
        long xa = x1 ^ (1ll << k), ya = y1 ^ de2, xb = x1 ^ de2, yb = y1 ^ (1ll << k);
        if(abs(xa - x2) + abs(ya - y2) <= abs(xb - x2) + abs(yb - y2)) 
            ret = de2 + (1ll << k) + getdis(k-1, xa & del, ya & del, x2 & del, y2 & del);
        else 
            ret = de2 + (1ll << k) + getdis(k-1, xb & del, yb & del, x2 & del, y2 & del);
    }
    // cerr << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << "->" << ret << endl;
    return ret;
}

long solve(int k, long x1, long y1, long x2, long y2) {
    // cerr << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << "-> solve" << endl;
    if(x1 == x2 && y1 == y2) return 0;
    bool a = x1 >> k & 1, b = y1 >> k & 1, c = x2 >> k & 1, d = y2 >> k & 1;
    long del = (1ll << k) - 1;
    long de2 = (1ll << (k+1)) - 1;
    long ret;
    if(k == 0) ret = (a != c + b != d);
    else if(a == c && b == d) ret = solve(k-1, x1 & del, y1 & del, x2 & del, y2 & del);
    else if(a == c) ret = 1 + getdis(k-1, a ? del : 0, b ? 0 : del, x1 & del, y1 & del) + getdis(k-1, c ? del : 0, d ? 0 : del, x2 & del, y2 & del);
    else if(b == d) ret = 1 + getdis(k-1, a ? 0 : del, b ? del : 0, x1 & del, y1 & del) + getdis(k-1, c ? 0 : del, d ? del : 0, x2 & del, y2 & del);
    else ret = (1ll << (k+1)) + min(getdis(k-1, a ? del : 0, b ? 0 : del, x1 & del, y1 & del) + getdis(k-1, a ? del : 0, b ? 0 : del, x2 & del, y2 & del), 
        getdis(k-1, a ? 0 : del, b ? del : 0, x1 & del, y1 & del) + getdis(k-1, a ? 0 : del, b ? del : 0, x2 & del, y2 & del) );
    // cerr << x1 << ' ' << y2 << ' ' << x2 << ' ' << y2 << "->" << ret << endl;
    return ret;
}

int main() {
    long k, x1, y1, x2, y2;
    cin >> k >> x1 >> y1 >> x2 >> y2; 
    cout << solve(--k, x1, y1, x2, y2) << endl;     
}