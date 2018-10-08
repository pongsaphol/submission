#include <bits/stdc++.h>
using namespace std;

#define long long long

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        long a, b; scanf("%lld %lld", &a, &b);
        if(a - b == 1) {
            long val = a + b;
            bool st = true;
            for(long i = 2; i * i <= val; ++i) if(val % i == 0) st = false;
            puts(st ? "YES" : "NO");
        } else puts("NO");
    }
}
