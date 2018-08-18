#include <bits/stdc++.h>
using namespace std;

#define long long long

int main() {
    long a, b; cin >> a >> b;
    long m = b / 2;
    long l = m, r = m;
    for(long i = 60; ~i; --i) {
        long ret = l - (1ll <<i), rea = r + (1ll <<i);
        if(ret >= 1 && b - ret <= a) l = ret;
        if(rea <= a && b - rea >= 1) r = rea;
    }
    cout << (r-l+1) / 2;
}